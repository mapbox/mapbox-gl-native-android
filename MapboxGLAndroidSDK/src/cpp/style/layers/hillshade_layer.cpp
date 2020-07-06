// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "hillshade_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::HillshadeLayer& toHillshadeLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::HillshadeLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    HillshadeLayer::HillshadeLayer(jni::JNIEnv& env, jni::String& layerId, jni::String& sourceId)
        : Layer(std::make_unique<mbgl::style::HillshadeLayer>(jni::Make<std::string>(env, layerId), jni::Make<std::string>(env, sourceId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    HillshadeLayer::HillshadeLayer(mbgl::style::HillshadeLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    HillshadeLayer::HillshadeLayer(std::unique_ptr<mbgl::style::HillshadeLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    HillshadeLayer::~HillshadeLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> HillshadeLayer::getHillshadeIlluminationDirection(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::HillshadeLayer::getDefaultHillshadeIlluminationDirection()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toHillshadeLayer(*layer.get()).getHillshadeIlluminationDirection()));
    }

    jni::Local<jni::Object<>> HillshadeLayer::getHillshadeIlluminationAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::HillshadeLayer::getDefaultHillshadeIlluminationAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toHillshadeLayer(*layer.get()).getHillshadeIlluminationAnchor()));
    }

    jni::Local<jni::Object<>> HillshadeLayer::getHillshadeExaggeration(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::HillshadeLayer::getDefaultHillshadeExaggeration()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toHillshadeLayer(*layer.get()).getHillshadeExaggeration()));
    }

    jni::Local<jni::Object<TransitionOptions>> HillshadeLayer::getHillshadeExaggerationTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toHillshadeLayer(*layer.get()).getHillshadeExaggerationTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void HillshadeLayer::setHillshadeExaggerationTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toHillshadeLayer(*layer.get()).setHillshadeExaggerationTransition(options);
    }

    jni::Local<jni::Object<>> HillshadeLayer::getHillshadeShadowColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::HillshadeLayer::getDefaultHillshadeShadowColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toHillshadeLayer(*layer.get()).getHillshadeShadowColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> HillshadeLayer::getHillshadeShadowColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toHillshadeLayer(*layer.get()).getHillshadeShadowColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void HillshadeLayer::setHillshadeShadowColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toHillshadeLayer(*layer.get()).setHillshadeShadowColorTransition(options);
    }

    jni::Local<jni::Object<>> HillshadeLayer::getHillshadeHighlightColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::HillshadeLayer::getDefaultHillshadeHighlightColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toHillshadeLayer(*layer.get()).getHillshadeHighlightColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> HillshadeLayer::getHillshadeHighlightColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toHillshadeLayer(*layer.get()).getHillshadeHighlightColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void HillshadeLayer::setHillshadeHighlightColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toHillshadeLayer(*layer.get()).setHillshadeHighlightColorTransition(options);
    }

    jni::Local<jni::Object<>> HillshadeLayer::getHillshadeAccentColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::HillshadeLayer::getDefaultHillshadeAccentColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toHillshadeLayer(*layer.get()).getHillshadeAccentColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> HillshadeLayer::getHillshadeAccentColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toHillshadeLayer(*layer.get()).getHillshadeAccentColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void HillshadeLayer::setHillshadeAccentColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toHillshadeLayer(*layer.get()).setHillshadeAccentColorTransition(options);
    }


    // HillshadeJavaLayerPeerFactory

    HillshadeJavaLayerPeerFactory::~HillshadeJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<HillshadeLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> HillshadeJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new HillshadeLayer(toHillshadeLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> HillshadeJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new HillshadeLayer(std::unique_ptr<mbgl::style::HillshadeLayer>(static_cast<mbgl::style::HillshadeLayer*>(layer.release()))));
    }

    void HillshadeJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<HillshadeLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<HillshadeLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<HillshadeLayer, jni::String&, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&HillshadeLayer::getHillshadeIlluminationDirection, "nativeGetHillshadeIlluminationDirection"),
            METHOD(&HillshadeLayer::getHillshadeIlluminationAnchor, "nativeGetHillshadeIlluminationAnchor"),
            METHOD(&HillshadeLayer::getHillshadeExaggerationTransition, "nativeGetHillshadeExaggerationTransition"),
            METHOD(&HillshadeLayer::setHillshadeExaggerationTransition, "nativeSetHillshadeExaggerationTransition"),
            METHOD(&HillshadeLayer::getHillshadeExaggeration, "nativeGetHillshadeExaggeration"),
            METHOD(&HillshadeLayer::getHillshadeShadowColorTransition, "nativeGetHillshadeShadowColorTransition"),
            METHOD(&HillshadeLayer::setHillshadeShadowColorTransition, "nativeSetHillshadeShadowColorTransition"),
            METHOD(&HillshadeLayer::getHillshadeShadowColor, "nativeGetHillshadeShadowColor"),
            METHOD(&HillshadeLayer::getHillshadeHighlightColorTransition, "nativeGetHillshadeHighlightColorTransition"),
            METHOD(&HillshadeLayer::setHillshadeHighlightColorTransition, "nativeSetHillshadeHighlightColorTransition"),
            METHOD(&HillshadeLayer::getHillshadeHighlightColor, "nativeGetHillshadeHighlightColor"),
            METHOD(&HillshadeLayer::getHillshadeAccentColorTransition, "nativeGetHillshadeAccentColorTransition"),
            METHOD(&HillshadeLayer::setHillshadeAccentColorTransition, "nativeSetHillshadeAccentColorTransition"),
            METHOD(&HillshadeLayer::getHillshadeAccentColor, "nativeGetHillshadeAccentColor"));
    }

} // namespace android
} // namespace mbgl
