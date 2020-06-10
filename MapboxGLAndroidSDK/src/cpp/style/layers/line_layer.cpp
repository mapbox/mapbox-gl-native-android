// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "line_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::LineLayer& toLineLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::LineLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    LineLayer::LineLayer(jni::JNIEnv& env, jni::String& layerId, jni::String& sourceId)
        : Layer(std::make_unique<mbgl::style::LineLayer>(jni::Make<std::string>(env, layerId), jni::Make<std::string>(env, sourceId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    LineLayer::LineLayer(mbgl::style::LineLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    LineLayer::LineLayer(std::unique_ptr<mbgl::style::LineLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    LineLayer::~LineLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> LineLayer::getLineCap(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineCap()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineCap()));
    }

    jni::Local<jni::Object<>> LineLayer::getLineJoin(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineJoin()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineJoin()));
    }

    jni::Local<jni::Object<>> LineLayer::getLineMiterLimit(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineMiterLimit()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineMiterLimit()));
    }

    jni::Local<jni::Object<>> LineLayer::getLineRoundLimit(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineRoundLimit()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineRoundLimit()));
    }

    jni::Local<jni::Object<>> LineLayer::getLineSortKey(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineSortKey()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineSortKey()));
    }

    jni::Local<jni::Object<>> LineLayer::getLineOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineOpacityTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineColorTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineColorTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineTranslate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineTranslate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineTranslate()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineTranslateTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineTranslateTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineTranslateTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineTranslateTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineTranslateAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineTranslateAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineTranslateAnchor()));
    }

    jni::Local<jni::Object<>> LineLayer::getLineWidth(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineWidth()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineWidth()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineWidthTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineWidthTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineWidthTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineWidthTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineGapWidth(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineGapWidth()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineGapWidth()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineGapWidthTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineGapWidthTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineGapWidthTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineGapWidthTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineOffset(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineOffset()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineOffset()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineOffsetTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineOffsetTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineOffsetTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineOffsetTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineBlur(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineBlur()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineBlur()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineBlurTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineBlurTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineBlurTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineBlurTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineDasharray(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineDasharray()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineDasharray()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLineDasharrayTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLineDasharrayTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLineDasharrayTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLineDasharrayTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLinePattern(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLinePattern()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLinePattern()));
    }

    jni::Local<jni::Object<TransitionOptions>> LineLayer::getLinePatternTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toLineLayer(*layer.get()).getLinePatternTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void LineLayer::setLinePatternTransition(jni::JNIEnv&, jlong duration, jlong delay) {
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toLineLayer(*layer.get()).setLinePatternTransition(options);
    }

    jni::Local<jni::Object<>> LineLayer::getLineGradient(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Error getting layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::LineLayer::getDefaultLineGradient()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toLineLayer(*layer.get()).getLineGradient()));
    }


    // LineJavaLayerPeerFactory

    LineJavaLayerPeerFactory::~LineJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<LineLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> LineJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new LineLayer(toLineLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> LineJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new LineLayer(std::unique_ptr<mbgl::style::LineLayer>(static_cast<mbgl::style::LineLayer*>(layer.release()))));
    }

    void LineJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<LineLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<LineLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<LineLayer, jni::String&, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&LineLayer::getLineCap, "nativeGetLineCap"),
            METHOD(&LineLayer::getLineJoin, "nativeGetLineJoin"),
            METHOD(&LineLayer::getLineMiterLimit, "nativeGetLineMiterLimit"),
            METHOD(&LineLayer::getLineRoundLimit, "nativeGetLineRoundLimit"),
            METHOD(&LineLayer::getLineSortKey, "nativeGetLineSortKey"),
            METHOD(&LineLayer::getLineOpacityTransition, "nativeGetLineOpacityTransition"),
            METHOD(&LineLayer::setLineOpacityTransition, "nativeSetLineOpacityTransition"),
            METHOD(&LineLayer::getLineOpacity, "nativeGetLineOpacity"),
            METHOD(&LineLayer::getLineColorTransition, "nativeGetLineColorTransition"),
            METHOD(&LineLayer::setLineColorTransition, "nativeSetLineColorTransition"),
            METHOD(&LineLayer::getLineColor, "nativeGetLineColor"),
            METHOD(&LineLayer::getLineTranslateTransition, "nativeGetLineTranslateTransition"),
            METHOD(&LineLayer::setLineTranslateTransition, "nativeSetLineTranslateTransition"),
            METHOD(&LineLayer::getLineTranslate, "nativeGetLineTranslate"),
            METHOD(&LineLayer::getLineTranslateAnchor, "nativeGetLineTranslateAnchor"),
            METHOD(&LineLayer::getLineWidthTransition, "nativeGetLineWidthTransition"),
            METHOD(&LineLayer::setLineWidthTransition, "nativeSetLineWidthTransition"),
            METHOD(&LineLayer::getLineWidth, "nativeGetLineWidth"),
            METHOD(&LineLayer::getLineGapWidthTransition, "nativeGetLineGapWidthTransition"),
            METHOD(&LineLayer::setLineGapWidthTransition, "nativeSetLineGapWidthTransition"),
            METHOD(&LineLayer::getLineGapWidth, "nativeGetLineGapWidth"),
            METHOD(&LineLayer::getLineOffsetTransition, "nativeGetLineOffsetTransition"),
            METHOD(&LineLayer::setLineOffsetTransition, "nativeSetLineOffsetTransition"),
            METHOD(&LineLayer::getLineOffset, "nativeGetLineOffset"),
            METHOD(&LineLayer::getLineBlurTransition, "nativeGetLineBlurTransition"),
            METHOD(&LineLayer::setLineBlurTransition, "nativeSetLineBlurTransition"),
            METHOD(&LineLayer::getLineBlur, "nativeGetLineBlur"),
            METHOD(&LineLayer::getLineDasharrayTransition, "nativeGetLineDasharrayTransition"),
            METHOD(&LineLayer::setLineDasharrayTransition, "nativeSetLineDasharrayTransition"),
            METHOD(&LineLayer::getLineDasharray, "nativeGetLineDasharray"),
            METHOD(&LineLayer::getLinePatternTransition, "nativeGetLinePatternTransition"),
            METHOD(&LineLayer::setLinePatternTransition, "nativeSetLinePatternTransition"),
            METHOD(&LineLayer::getLinePattern, "nativeGetLinePattern"),
            METHOD(&LineLayer::getLineGradient, "nativeGetLineGradient"));
    }

} // namespace android
} // namespace mbgl
