// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "fill_extrusion_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::FillExtrusionLayer& toFillExtrusionLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::FillExtrusionLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    FillExtrusionLayer::FillExtrusionLayer(jni::JNIEnv& env, jni::String& layerId, jni::String& sourceId)
        : Layer(std::make_unique<mbgl::style::FillExtrusionLayer>(jni::Make<std::string>(env, layerId), jni::Make<std::string>(env, sourceId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    FillExtrusionLayer::FillExtrusionLayer(mbgl::style::FillExtrusionLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    FillExtrusionLayer::FillExtrusionLayer(std::unique_ptr<mbgl::style::FillExtrusionLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    FillExtrusionLayer::~FillExtrusionLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> FillExtrusionLayer::getFillExtrusionOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toFillExtrusionLayer(*layer.get()).getFillExtrusionOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void FillExtrusionLayer::setFillExtrusionOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toFillExtrusionLayer(*layer.get()).setFillExtrusionOpacityTransition(options);
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> FillExtrusionLayer::getFillExtrusionColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toFillExtrusionLayer(*layer.get()).getFillExtrusionColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void FillExtrusionLayer::setFillExtrusionColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toFillExtrusionLayer(*layer.get()).setFillExtrusionColorTransition(options);
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionTranslate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionTranslate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionTranslate()));
    }

    jni::Local<jni::Object<TransitionOptions>> FillExtrusionLayer::getFillExtrusionTranslateTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toFillExtrusionLayer(*layer.get()).getFillExtrusionTranslateTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void FillExtrusionLayer::setFillExtrusionTranslateTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toFillExtrusionLayer(*layer.get()).setFillExtrusionTranslateTransition(options);
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionTranslateAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionTranslateAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionTranslateAnchor()));
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionPattern(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionPattern()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionPattern()));
    }

    jni::Local<jni::Object<TransitionOptions>> FillExtrusionLayer::getFillExtrusionPatternTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toFillExtrusionLayer(*layer.get()).getFillExtrusionPatternTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void FillExtrusionLayer::setFillExtrusionPatternTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toFillExtrusionLayer(*layer.get()).setFillExtrusionPatternTransition(options);
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionHeight(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionHeight()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionHeight()));
    }

    jni::Local<jni::Object<TransitionOptions>> FillExtrusionLayer::getFillExtrusionHeightTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toFillExtrusionLayer(*layer.get()).getFillExtrusionHeightTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void FillExtrusionLayer::setFillExtrusionHeightTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toFillExtrusionLayer(*layer.get()).setFillExtrusionHeightTransition(options);
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionBase(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionBase()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionBase()));
    }

    jni::Local<jni::Object<TransitionOptions>> FillExtrusionLayer::getFillExtrusionBaseTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toFillExtrusionLayer(*layer.get()).getFillExtrusionBaseTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void FillExtrusionLayer::setFillExtrusionBaseTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toFillExtrusionLayer(*layer.get()).setFillExtrusionBaseTransition(options);
    }

    jni::Local<jni::Object<>> FillExtrusionLayer::getFillExtrusionVerticalGradient(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::FillExtrusionLayer::getDefaultFillExtrusionVerticalGradient()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toFillExtrusionLayer(*layer.get()).getFillExtrusionVerticalGradient()));
    }


    // FillExtrusionJavaLayerPeerFactory

    FillExtrusionJavaLayerPeerFactory::~FillExtrusionJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<FillExtrusionLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> FillExtrusionJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new FillExtrusionLayer(toFillExtrusionLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> FillExtrusionJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new FillExtrusionLayer(std::unique_ptr<mbgl::style::FillExtrusionLayer>(static_cast<mbgl::style::FillExtrusionLayer*>(layer.release()))));
    }

    void FillExtrusionJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<FillExtrusionLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<FillExtrusionLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<FillExtrusionLayer, jni::String&, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&FillExtrusionLayer::getFillExtrusionOpacityTransition, "nativeGetFillExtrusionOpacityTransition"),
            METHOD(&FillExtrusionLayer::setFillExtrusionOpacityTransition, "nativeSetFillExtrusionOpacityTransition"),
            METHOD(&FillExtrusionLayer::getFillExtrusionOpacity, "nativeGetFillExtrusionOpacity"),
            METHOD(&FillExtrusionLayer::getFillExtrusionColorTransition, "nativeGetFillExtrusionColorTransition"),
            METHOD(&FillExtrusionLayer::setFillExtrusionColorTransition, "nativeSetFillExtrusionColorTransition"),
            METHOD(&FillExtrusionLayer::getFillExtrusionColor, "nativeGetFillExtrusionColor"),
            METHOD(&FillExtrusionLayer::getFillExtrusionTranslateTransition, "nativeGetFillExtrusionTranslateTransition"),
            METHOD(&FillExtrusionLayer::setFillExtrusionTranslateTransition, "nativeSetFillExtrusionTranslateTransition"),
            METHOD(&FillExtrusionLayer::getFillExtrusionTranslate, "nativeGetFillExtrusionTranslate"),
            METHOD(&FillExtrusionLayer::getFillExtrusionTranslateAnchor, "nativeGetFillExtrusionTranslateAnchor"),
            METHOD(&FillExtrusionLayer::getFillExtrusionPatternTransition, "nativeGetFillExtrusionPatternTransition"),
            METHOD(&FillExtrusionLayer::setFillExtrusionPatternTransition, "nativeSetFillExtrusionPatternTransition"),
            METHOD(&FillExtrusionLayer::getFillExtrusionPattern, "nativeGetFillExtrusionPattern"),
            METHOD(&FillExtrusionLayer::getFillExtrusionHeightTransition, "nativeGetFillExtrusionHeightTransition"),
            METHOD(&FillExtrusionLayer::setFillExtrusionHeightTransition, "nativeSetFillExtrusionHeightTransition"),
            METHOD(&FillExtrusionLayer::getFillExtrusionHeight, "nativeGetFillExtrusionHeight"),
            METHOD(&FillExtrusionLayer::getFillExtrusionBaseTransition, "nativeGetFillExtrusionBaseTransition"),
            METHOD(&FillExtrusionLayer::setFillExtrusionBaseTransition, "nativeSetFillExtrusionBaseTransition"),
            METHOD(&FillExtrusionLayer::getFillExtrusionBase, "nativeGetFillExtrusionBase"),
            METHOD(&FillExtrusionLayer::getFillExtrusionVerticalGradient, "nativeGetFillExtrusionVerticalGradient"));
    }

} // namespace android
} // namespace mbgl
