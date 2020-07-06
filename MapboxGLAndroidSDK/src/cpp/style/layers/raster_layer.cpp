// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "raster_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::RasterLayer& toRasterLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::RasterLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    RasterLayer::RasterLayer(jni::JNIEnv& env, jni::String& layerId, jni::String& sourceId)
        : Layer(std::make_unique<mbgl::style::RasterLayer>(jni::Make<std::string>(env, layerId), jni::Make<std::string>(env, sourceId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    RasterLayer::RasterLayer(mbgl::style::RasterLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    RasterLayer::RasterLayer(std::unique_ptr<mbgl::style::RasterLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    RasterLayer::~RasterLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> RasterLayer::getRasterOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> RasterLayer::getRasterOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toRasterLayer(*layer.get()).getRasterOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void RasterLayer::setRasterOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toRasterLayer(*layer.get()).setRasterOpacityTransition(options);
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterHueRotate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterHueRotate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterHueRotate()));
    }

    jni::Local<jni::Object<TransitionOptions>> RasterLayer::getRasterHueRotateTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toRasterLayer(*layer.get()).getRasterHueRotateTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void RasterLayer::setRasterHueRotateTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toRasterLayer(*layer.get()).setRasterHueRotateTransition(options);
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterBrightnessMin(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterBrightnessMin()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterBrightnessMin()));
    }

    jni::Local<jni::Object<TransitionOptions>> RasterLayer::getRasterBrightnessMinTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toRasterLayer(*layer.get()).getRasterBrightnessMinTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void RasterLayer::setRasterBrightnessMinTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toRasterLayer(*layer.get()).setRasterBrightnessMinTransition(options);
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterBrightnessMax(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterBrightnessMax()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterBrightnessMax()));
    }

    jni::Local<jni::Object<TransitionOptions>> RasterLayer::getRasterBrightnessMaxTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toRasterLayer(*layer.get()).getRasterBrightnessMaxTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void RasterLayer::setRasterBrightnessMaxTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toRasterLayer(*layer.get()).setRasterBrightnessMaxTransition(options);
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterSaturation(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterSaturation()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterSaturation()));
    }

    jni::Local<jni::Object<TransitionOptions>> RasterLayer::getRasterSaturationTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toRasterLayer(*layer.get()).getRasterSaturationTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void RasterLayer::setRasterSaturationTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toRasterLayer(*layer.get()).setRasterSaturationTransition(options);
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterContrast(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterContrast()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterContrast()));
    }

    jni::Local<jni::Object<TransitionOptions>> RasterLayer::getRasterContrastTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toRasterLayer(*layer.get()).getRasterContrastTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void RasterLayer::setRasterContrastTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toRasterLayer(*layer.get()).setRasterContrastTransition(options);
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterResampling(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterResampling()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterResampling()));
    }

    jni::Local<jni::Object<>> RasterLayer::getRasterFadeDuration(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::RasterLayer::getDefaultRasterFadeDuration()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toRasterLayer(*layer.get()).getRasterFadeDuration()));
    }


    // RasterJavaLayerPeerFactory

    RasterJavaLayerPeerFactory::~RasterJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<RasterLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> RasterJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new RasterLayer(toRasterLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> RasterJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new RasterLayer(std::unique_ptr<mbgl::style::RasterLayer>(static_cast<mbgl::style::RasterLayer*>(layer.release()))));
    }

    void RasterJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<RasterLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<RasterLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<RasterLayer, jni::String&, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&RasterLayer::getRasterOpacityTransition, "nativeGetRasterOpacityTransition"),
            METHOD(&RasterLayer::setRasterOpacityTransition, "nativeSetRasterOpacityTransition"),
            METHOD(&RasterLayer::getRasterOpacity, "nativeGetRasterOpacity"),
            METHOD(&RasterLayer::getRasterHueRotateTransition, "nativeGetRasterHueRotateTransition"),
            METHOD(&RasterLayer::setRasterHueRotateTransition, "nativeSetRasterHueRotateTransition"),
            METHOD(&RasterLayer::getRasterHueRotate, "nativeGetRasterHueRotate"),
            METHOD(&RasterLayer::getRasterBrightnessMinTransition, "nativeGetRasterBrightnessMinTransition"),
            METHOD(&RasterLayer::setRasterBrightnessMinTransition, "nativeSetRasterBrightnessMinTransition"),
            METHOD(&RasterLayer::getRasterBrightnessMin, "nativeGetRasterBrightnessMin"),
            METHOD(&RasterLayer::getRasterBrightnessMaxTransition, "nativeGetRasterBrightnessMaxTransition"),
            METHOD(&RasterLayer::setRasterBrightnessMaxTransition, "nativeSetRasterBrightnessMaxTransition"),
            METHOD(&RasterLayer::getRasterBrightnessMax, "nativeGetRasterBrightnessMax"),
            METHOD(&RasterLayer::getRasterSaturationTransition, "nativeGetRasterSaturationTransition"),
            METHOD(&RasterLayer::setRasterSaturationTransition, "nativeSetRasterSaturationTransition"),
            METHOD(&RasterLayer::getRasterSaturation, "nativeGetRasterSaturation"),
            METHOD(&RasterLayer::getRasterContrastTransition, "nativeGetRasterContrastTransition"),
            METHOD(&RasterLayer::setRasterContrastTransition, "nativeSetRasterContrastTransition"),
            METHOD(&RasterLayer::getRasterContrast, "nativeGetRasterContrast"),
            METHOD(&RasterLayer::getRasterResampling, "nativeGetRasterResampling"),
            METHOD(&RasterLayer::getRasterFadeDuration, "nativeGetRasterFadeDuration"));
    }

} // namespace android
} // namespace mbgl
