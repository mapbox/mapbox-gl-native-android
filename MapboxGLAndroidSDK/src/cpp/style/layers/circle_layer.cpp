// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "circle_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::CircleLayer& toCircleLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::CircleLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    CircleLayer::CircleLayer(jni::JNIEnv& env, jni::String& layerId, jni::String& sourceId)
        : Layer(std::make_unique<mbgl::style::CircleLayer>(jni::Make<std::string>(env, layerId), jni::Make<std::string>(env, sourceId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    CircleLayer::CircleLayer(mbgl::style::CircleLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    CircleLayer::CircleLayer(std::unique_ptr<mbgl::style::CircleLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    CircleLayer::~CircleLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> CircleLayer::getCircleSortKey(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleSortKey()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleSortKey()));
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleRadius(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleRadius()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleRadius()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleRadiusTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleRadiusTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleRadiusTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleRadiusTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleColorTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleBlur(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleBlur()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleBlur()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleBlurTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleBlurTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleBlurTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleBlurTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleOpacityTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleTranslate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleTranslate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleTranslate()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleTranslateTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleTranslateTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleTranslateTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleTranslateTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleTranslateAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleTranslateAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleTranslateAnchor()));
    }

    jni::Local<jni::Object<>> CircleLayer::getCirclePitchScale(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCirclePitchScale()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCirclePitchScale()));
    }

    jni::Local<jni::Object<>> CircleLayer::getCirclePitchAlignment(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCirclePitchAlignment()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCirclePitchAlignment()));
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleStrokeWidth(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleStrokeWidth()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleStrokeWidth()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleStrokeWidthTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleStrokeWidthTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleStrokeWidthTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleStrokeWidthTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleStrokeColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleStrokeColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleStrokeColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleStrokeColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleStrokeColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleStrokeColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleStrokeColorTransition(options);
    }

    jni::Local<jni::Object<>> CircleLayer::getCircleStrokeOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::CircleLayer::getDefaultCircleStrokeOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toCircleLayer(*layer.get()).getCircleStrokeOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> CircleLayer::getCircleStrokeOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toCircleLayer(*layer.get()).getCircleStrokeOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void CircleLayer::setCircleStrokeOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toCircleLayer(*layer.get()).setCircleStrokeOpacityTransition(options);
    }


    // CircleJavaLayerPeerFactory

    CircleJavaLayerPeerFactory::~CircleJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<CircleLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> CircleJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new CircleLayer(toCircleLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> CircleJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new CircleLayer(std::unique_ptr<mbgl::style::CircleLayer>(static_cast<mbgl::style::CircleLayer*>(layer.release()))));
    }

    void CircleJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<CircleLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<CircleLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<CircleLayer, jni::String&, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&CircleLayer::getCircleSortKey, "nativeGetCircleSortKey"),
            METHOD(&CircleLayer::getCircleRadiusTransition, "nativeGetCircleRadiusTransition"),
            METHOD(&CircleLayer::setCircleRadiusTransition, "nativeSetCircleRadiusTransition"),
            METHOD(&CircleLayer::getCircleRadius, "nativeGetCircleRadius"),
            METHOD(&CircleLayer::getCircleColorTransition, "nativeGetCircleColorTransition"),
            METHOD(&CircleLayer::setCircleColorTransition, "nativeSetCircleColorTransition"),
            METHOD(&CircleLayer::getCircleColor, "nativeGetCircleColor"),
            METHOD(&CircleLayer::getCircleBlurTransition, "nativeGetCircleBlurTransition"),
            METHOD(&CircleLayer::setCircleBlurTransition, "nativeSetCircleBlurTransition"),
            METHOD(&CircleLayer::getCircleBlur, "nativeGetCircleBlur"),
            METHOD(&CircleLayer::getCircleOpacityTransition, "nativeGetCircleOpacityTransition"),
            METHOD(&CircleLayer::setCircleOpacityTransition, "nativeSetCircleOpacityTransition"),
            METHOD(&CircleLayer::getCircleOpacity, "nativeGetCircleOpacity"),
            METHOD(&CircleLayer::getCircleTranslateTransition, "nativeGetCircleTranslateTransition"),
            METHOD(&CircleLayer::setCircleTranslateTransition, "nativeSetCircleTranslateTransition"),
            METHOD(&CircleLayer::getCircleTranslate, "nativeGetCircleTranslate"),
            METHOD(&CircleLayer::getCircleTranslateAnchor, "nativeGetCircleTranslateAnchor"),
            METHOD(&CircleLayer::getCirclePitchScale, "nativeGetCirclePitchScale"),
            METHOD(&CircleLayer::getCirclePitchAlignment, "nativeGetCirclePitchAlignment"),
            METHOD(&CircleLayer::getCircleStrokeWidthTransition, "nativeGetCircleStrokeWidthTransition"),
            METHOD(&CircleLayer::setCircleStrokeWidthTransition, "nativeSetCircleStrokeWidthTransition"),
            METHOD(&CircleLayer::getCircleStrokeWidth, "nativeGetCircleStrokeWidth"),
            METHOD(&CircleLayer::getCircleStrokeColorTransition, "nativeGetCircleStrokeColorTransition"),
            METHOD(&CircleLayer::setCircleStrokeColorTransition, "nativeSetCircleStrokeColorTransition"),
            METHOD(&CircleLayer::getCircleStrokeColor, "nativeGetCircleStrokeColor"),
            METHOD(&CircleLayer::getCircleStrokeOpacityTransition, "nativeGetCircleStrokeOpacityTransition"),
            METHOD(&CircleLayer::setCircleStrokeOpacityTransition, "nativeSetCircleStrokeOpacityTransition"),
            METHOD(&CircleLayer::getCircleStrokeOpacity, "nativeGetCircleStrokeOpacity"));
    }

} // namespace android
} // namespace mbgl
