// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "background_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::BackgroundLayer& toBackgroundLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::BackgroundLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    BackgroundLayer::BackgroundLayer(jni::JNIEnv& env, jni::String& layerId)
        : Layer(std::make_unique<mbgl::style::BackgroundLayer>(jni::Make<std::string>(env, layerId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    BackgroundLayer::BackgroundLayer(mbgl::style::BackgroundLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    BackgroundLayer::BackgroundLayer(std::unique_ptr<mbgl::style::BackgroundLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    BackgroundLayer::~BackgroundLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> BackgroundLayer::getBackgroundColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::BackgroundLayer::getDefaultBackgroundColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toBackgroundLayer(*layer.get()).getBackgroundColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> BackgroundLayer::getBackgroundColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toBackgroundLayer(*layer.get()).getBackgroundColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void BackgroundLayer::setBackgroundColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toBackgroundLayer(*layer.get()).setBackgroundColorTransition(options);
    }

    jni::Local<jni::Object<>> BackgroundLayer::getBackgroundPattern(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::BackgroundLayer::getDefaultBackgroundPattern()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toBackgroundLayer(*layer.get()).getBackgroundPattern()));
    }

    jni::Local<jni::Object<TransitionOptions>> BackgroundLayer::getBackgroundPatternTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toBackgroundLayer(*layer.get()).getBackgroundPatternTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void BackgroundLayer::setBackgroundPatternTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toBackgroundLayer(*layer.get()).setBackgroundPatternTransition(options);
    }

    jni::Local<jni::Object<>> BackgroundLayer::getBackgroundOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::BackgroundLayer::getDefaultBackgroundOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toBackgroundLayer(*layer.get()).getBackgroundOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> BackgroundLayer::getBackgroundOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toBackgroundLayer(*layer.get()).getBackgroundOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void BackgroundLayer::setBackgroundOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toBackgroundLayer(*layer.get()).setBackgroundOpacityTransition(options);
    }


    // BackgroundJavaLayerPeerFactory

    BackgroundJavaLayerPeerFactory::~BackgroundJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<BackgroundLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> BackgroundJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new BackgroundLayer(toBackgroundLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> BackgroundJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new BackgroundLayer(std::unique_ptr<mbgl::style::BackgroundLayer>(static_cast<mbgl::style::BackgroundLayer*>(layer.release()))));
    }

    void BackgroundJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<BackgroundLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<BackgroundLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<BackgroundLayer, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&BackgroundLayer::getBackgroundColorTransition, "nativeGetBackgroundColorTransition"),
            METHOD(&BackgroundLayer::setBackgroundColorTransition, "nativeSetBackgroundColorTransition"),
            METHOD(&BackgroundLayer::getBackgroundColor, "nativeGetBackgroundColor"),
            METHOD(&BackgroundLayer::getBackgroundPatternTransition, "nativeGetBackgroundPatternTransition"),
            METHOD(&BackgroundLayer::setBackgroundPatternTransition, "nativeSetBackgroundPatternTransition"),
            METHOD(&BackgroundLayer::getBackgroundPattern, "nativeGetBackgroundPattern"),
            METHOD(&BackgroundLayer::getBackgroundOpacityTransition, "nativeGetBackgroundOpacityTransition"),
            METHOD(&BackgroundLayer::setBackgroundOpacityTransition, "nativeSetBackgroundOpacityTransition"),
            METHOD(&BackgroundLayer::getBackgroundOpacity, "nativeGetBackgroundOpacity"));
    }

} // namespace android
} // namespace mbgl
