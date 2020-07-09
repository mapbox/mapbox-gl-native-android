#include "source.hpp"
#include "../android_conversion.hpp"
#include "attach_env.hpp"

#include <jni/jni.hpp>

#include <mbgl/style/style.hpp>
#include <mbgl/util/logging.hpp>

// Java -> C++ conversion
#include <mbgl/style/conversion/source.hpp>
#include <mbgl/style/conversion_impl.hpp>

// C++ -> Java conversion
#include "../conversion/property_value.hpp"

#include <string>

// Core Sources
#include <mbgl/style/sources/geojson_source.hpp>
#include <mbgl/style/sources/image_source.hpp>
#include <mbgl/style/sources/raster_source.hpp>
#include <mbgl/style/sources/vector_source.hpp>

// Android Source peers
#include "geojson_source.hpp"
#include "image_source.hpp"
#include "raster_source.hpp"
#include "unknown_source.hpp"
#include "vector_source.hpp"
#include "custom_geometry_source.hpp"
#include "raster_dem_source.hpp"

namespace mbgl {
namespace android {

namespace {
    const std::string ERR_MSG_DEAD_CORE_PEER = "core source is not available";
    constexpr auto EMPTY_STRING = "";
}

static std::unique_ptr<Source> createSourcePeer(jni::JNIEnv& env,
                                                mbgl::style::Source& coreSource,
                                                AndroidRendererFrontend* frontend) {
    if (coreSource.is<mbgl::style::VectorSource>()) {
        return std::make_unique<VectorSource>(env, *coreSource.as<mbgl::style::VectorSource>(), frontend);
    } else if (coreSource.is<mbgl::style::RasterSource>()) {
        return std::make_unique<RasterSource>(env, *coreSource.as<mbgl::style::RasterSource>(), frontend);
    } else if (coreSource.is<mbgl::style::GeoJSONSource>()) {
        return std::make_unique<GeoJSONSource>(env, *coreSource.as<mbgl::style::GeoJSONSource>(), frontend);
    } else if (coreSource.is<mbgl::style::ImageSource>()) {
        return std::make_unique<ImageSource>(env, *coreSource.as<mbgl::style::ImageSource>(), frontend);
    } else {
        return std::make_unique<UnknownSource>(env, coreSource, frontend);
    }
}

const jni::Object<Source> &
Source::peerForCoreSource(jni::JNIEnv &env, mbgl::style::Source &coreSource,
                          AndroidRendererFrontend &frontend) {
    if (!coreSource.peer.has_value()) {
        coreSource.peer = createSourcePeer(env, coreSource, &frontend).release();
    }
    return coreSource.peer.get<Source*>()->javaPeer;
}

const jni::Object<Source> &
Source::peerForCoreSource(jni::JNIEnv &env, mbgl::style::Source &coreSource) {
    if (!coreSource.peer.has_value()) {
        coreSource.peer = createSourcePeer(env, coreSource, nullptr).release();
    }
    return coreSource.peer.get<Source*>()->javaPeer;
}

Source::Source(jni::JNIEnv &env,
               mbgl::style::Source &coreSource,
               const jni::Object<Source> &obj,
               AndroidRendererFrontend *frontend)
        : source(coreSource.makeWeakPtr()), javaPeer(jni::NewGlobal(env, obj)), rendererFrontend(frontend) {}

Source::Source(jni::JNIEnv &, std::unique_ptr<mbgl::style::Source> coreSource)
        : ownedSource(std::move(coreSource)), source(ownedSource->makeWeakPtr()) {
}

Source::~Source() {
    if (ownedSource) {
        ownedSource.reset();
    }

    if (javaPeer.get() != nullptr) {
        // Manually clear the java peer
        android::UniqueEnv env = android::AttachEnv();
        static auto &javaClass = jni::Class<Source>::Singleton(*env);
        static auto nativePtrField = javaClass.GetField<jlong>(*env, "nativePtr");
        javaPeer.Set(*env, nativePtrField, (jlong) 0);
        javaPeer.reset();
        // Manually reset native peer when his object is GC-ed
        auto guard = source.lock();
        if (source) {
            source->peer = nullptr;
        }
    }
}

jni::Local<jni::String> Source::getId(jni::JNIEnv &env) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to get source id: " + ERR_MSG_DEAD_CORE_PEER);
        return jni::Make<jni::String>(env, EMPTY_STRING);
    }
    return jni::Make<jni::String>(env, source->getID());
}

jni::Local<jni::String> Source::getAttribution(jni::JNIEnv &env) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to get source attribution: " + ERR_MSG_DEAD_CORE_PEER);
        return jni::Make<jni::String>(env, EMPTY_STRING);
    }

    auto attribution = source->getAttribution();
    return attribution ? jni::Make<jni::String>(env, attribution.value()) : jni::Make<jni::String>(
            env, "");
}

void Source::setPrefetchZoomDelta(jni::JNIEnv &env, jni::Integer &delta) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to set source prefetch zoom delta: " + ERR_MSG_DEAD_CORE_PEER);
        return;
    }

    if (!delta) {
        source->setPrefetchZoomDelta(nullopt);
    } else {
        source->setPrefetchZoomDelta(jni::Unbox(env, delta));
    }
}

jni::Local<jni::Integer> Source::getPrefetchZoomDelta(jni::JNIEnv &env) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to get source prefetch zoom delta: " + ERR_MSG_DEAD_CORE_PEER);
        return jni::Local<jni::Integer>(env, nullptr);
    }
    auto delta = source->getPrefetchZoomDelta();
    if (delta.has_value()) {
        return jni::Box(env, jni::jint(delta.value()));
    }
    return jni::Local<jni::Integer>(env, nullptr);
}

void
Source::setMaxOverscaleFactorForParentTiles(jni::JNIEnv &env, jni::Integer &maxOverscaleFactor) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to set source max overscale factor for parent tiles: " + ERR_MSG_DEAD_CORE_PEER);
        return;
    }
    if (!maxOverscaleFactor) {
        source->setMaxOverscaleFactorForParentTiles(nullopt);
    } else {
        source->setMaxOverscaleFactorForParentTiles(jni::Unbox(env, maxOverscaleFactor));
    }
}

jni::Local<jni::Integer> Source::getMaxOverscaleFactorForParentTiles(jni::JNIEnv &env) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to get source max overscale factor for parent tiles: " + ERR_MSG_DEAD_CORE_PEER);
        return jni::Local<jni::Integer>(env, nullptr);
    }
    auto maxOverscaleFactor = source->getMaxOverscaleFactorForParentTiles();
    if (maxOverscaleFactor) {
        return jni::Box(env, jni::jint(*maxOverscaleFactor));
    }
    return jni::Local<jni::Integer>(env, nullptr);
}

void Source::addToStyle(JNIEnv &env, const jni::Object<Source> &obj, mbgl::style::Style &style) {
    if (!ownedSource) {
        throw std::runtime_error("Cannot add source twice");
    }

    // Add source to style and release ownership
    style.addSource(std::move(ownedSource));

    auto guard = source.lock();
    if (!source) {
        throw std::runtime_error("Failed to add source style: " + ERR_MSG_DEAD_CORE_PEER);
    }

    // Add peer to core source
    source->peer = this;

    // Add strong reference to java source
    javaPeer = jni::NewGlobal(env, obj);
}

void Source::addToMap(JNIEnv &env, const jni::Object<Source> &obj, mbgl::Map &map,
                      AndroidRendererFrontend &frontend) {
    // Check to see if we own the source first
    if (!ownedSource) {
        throw std::runtime_error("Cannot add source twice");
    }

    // Add source to map and release ownership
    map.getStyle().addSource(std::move(ownedSource));

    auto guard = source.lock();
    if (!source) {
        throw std::runtime_error("Failed to add source to map: " + ERR_MSG_DEAD_CORE_PEER);
    }

    // Add peer to core source
    source->peer = this;

    // Add strong reference to java source
    javaPeer = jni::NewGlobal(env, obj);

    rendererFrontend = &frontend;
}

bool Source::removeFromMap(JNIEnv &, const jni::Object<Source> &, mbgl::Map &map) {
    // Cannot remove if not attached yet
    if (ownedSource) {
        throw std::runtime_error("Cannot remove detached source");
    }

    auto guard = source.lock();
    if (!source) {
        throw std::runtime_error("Failed to remove source from map: " + ERR_MSG_DEAD_CORE_PEER);
    }

    // Remove the source from the map and take ownership
    ownedSource = map.getStyle().removeSource(source->getID());

    // The source may not be removed if any layers still reference it
    return ownedSource != nullptr;
}

jni::Local<jni::Boolean> Source::isVolatile(jni::JNIEnv &env) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed Source::isVolatile(): " + ERR_MSG_DEAD_CORE_PEER);
        return jni::Box(env, jni::jboolean(false));
    }
    return jni::Box(env, jni::jboolean(source->isVolatile()));
}

void Source::setVolatile(JNIEnv &env, jni::Boolean &value) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed Source::setVolatile(): " + ERR_MSG_DEAD_CORE_PEER);
        return;
    }
    source->setVolatile(jni::Unbox(env, value));
}

void Source::setMinimumTileUpdateInterval(JNIEnv &env, jni::Long &interval) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to set source minimum tile update interval: " + ERR_MSG_DEAD_CORE_PEER);
        return;
    }
    source->setMinimumTileUpdateInterval(Milliseconds(jni::Unbox(env, interval)));
}

jni::Local<jni::Long> Source::getMinimumTileUpdateInterval(JNIEnv &env) {
    auto guard = source.lock();
    if (!source) {
        mbgl::Log::Error(mbgl::Event::JNI, "Failed to get source minimum tile update interval: " + ERR_MSG_DEAD_CORE_PEER);
        jni::Box(env, jni::jlong(0));
    }
    return jni::Box(env, jni::jlong(source->getMinimumTileUpdateInterval().count() / 1000000));
}

void Source::releaseJavaPeer() {
    // We can't release the peer if the source was not removed from the map
    if (!ownedSource) {
        return;
    }

    // Release the peer relationships. These will be re-established when the source is added to a map
    assert(ownedSource->peer.has_value());
    ownedSource->peer.get<std::unique_ptr<Source>>().release();
    ownedSource->peer = mapbox::base::TypeWrapper();

    // Release the strong reference to the java peer
    assert(javaPeer);
    javaPeer.reset();

    rendererFrontend = nullptr;
}

void Source::registerNative(jni::JNIEnv &env) {
    // Lookup the class
    static auto &javaClass = jni::Class<Source>::Singleton(env);

#define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

    // Register the peer
    jni::RegisterNativePeer<Source>(
            env,
            javaClass,
            "nativePtr",
            METHOD(&Source::getId, "nativeGetId"),
            METHOD(&Source::getAttribution, "nativeGetAttribution"),
            METHOD(&Source::setPrefetchZoomDelta, "nativeSetPrefetchZoomDelta"),
            METHOD(&Source::getPrefetchZoomDelta, "nativeGetPrefetchZoomDelta"),
            METHOD(&Source::setMaxOverscaleFactorForParentTiles,
                   "nativeSetMaxOverscaleFactorForParentTiles"),
            METHOD(&Source::getMaxOverscaleFactorForParentTiles,
                   "nativeGetMaxOverscaleFactorForParentTiles"),
            METHOD(&Source::isVolatile, "nativeIsVolatile"),
            METHOD(&Source::setVolatile, "nativeSetVolatile"),
            METHOD(&Source::setMinimumTileUpdateInterval, "nativeSetMinimumTileUpdateInterval"),
            METHOD(&Source::getMinimumTileUpdateInterval, "nativeGetMinimumTileUpdateInterval"));


    // Register subclasses
    GeoJSONSource::registerNative(env);
    ImageSource::registerNative(env);
    RasterSource::registerNative(env);
    UnknownSource::registerNative(env);
    VectorSource::registerNative(env);
    CustomGeometrySource::registerNative(env);
    RasterDEMSource::registerNative(env);
}
} // namespace android
} // namespace mbgl
