// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include "symbol_layer.hpp"

#include <string>

#include "../conversion/property_value.hpp"
#include "../conversion/transition_options.hpp"

#include <mbgl/style/layer_impl.hpp>
#include <mbgl/util/logging.hpp>

namespace mbgl {
namespace android {

    inline mbgl::style::SymbolLayer& toSymbolLayer(mbgl::style::Layer& layer) {
        return static_cast<mbgl::style::SymbolLayer&>(layer);
    }

    /**
     * Creates an owning peer object (for layers not attached to the map) from the JVM side
     */
    SymbolLayer::SymbolLayer(jni::JNIEnv& env, jni::String& layerId, jni::String& sourceId)
        : Layer(std::make_unique<mbgl::style::SymbolLayer>(jni::Make<std::string>(env, layerId), jni::Make<std::string>(env, sourceId))) {
    }

    /**
     * Creates a non-owning peer object (for layers currently attached to the map)
     */
    SymbolLayer::SymbolLayer(mbgl::style::SymbolLayer& coreLayer)
        : Layer(coreLayer) {
    }

    /**
     * Creates an owning peer object (for layers not attached to the map)
     */
    SymbolLayer::SymbolLayer(std::unique_ptr<mbgl::style::SymbolLayer> coreLayer)
        : Layer(std::move(coreLayer)) {
    }

    SymbolLayer::~SymbolLayer() = default;

    // Property getters

    jni::Local<jni::Object<>> SymbolLayer::getSymbolPlacement(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultSymbolPlacement()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getSymbolPlacement()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getSymbolSpacing(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultSymbolSpacing()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getSymbolSpacing()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getSymbolAvoidEdges(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultSymbolAvoidEdges()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getSymbolAvoidEdges()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getSymbolSortKey(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultSymbolSortKey()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getSymbolSortKey()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getSymbolZOrder(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultSymbolZOrder()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getSymbolZOrder()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconAllowOverlap(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconAllowOverlap()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconAllowOverlap()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconIgnorePlacement(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconIgnorePlacement()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconIgnorePlacement()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconOptional(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconOptional()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconOptional()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconRotationAlignment(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconRotationAlignment()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconRotationAlignment()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconSize(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconSize()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconSize()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconTextFit(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconTextFit()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconTextFit()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconTextFitPadding(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconTextFitPadding()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconTextFitPadding()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconImage(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconImage()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconImage()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconRotate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconRotate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconRotate()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconPadding(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconPadding()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconPadding()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconKeepUpright(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconKeepUpright()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconKeepUpright()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconOffset(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconOffset()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconOffset()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconAnchor()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconPitchAlignment(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconPitchAlignment()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconPitchAlignment()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextPitchAlignment(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextPitchAlignment()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextPitchAlignment()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextRotationAlignment(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextRotationAlignment()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextRotationAlignment()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextField(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextField()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextField()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextFont(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextFont()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextFont()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextSize(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextSize()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextSize()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextMaxWidth(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextMaxWidth()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextMaxWidth()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextLineHeight(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextLineHeight()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextLineHeight()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextLetterSpacing(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextLetterSpacing()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextLetterSpacing()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextJustify(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextJustify()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextJustify()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextRadialOffset(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextRadialOffset()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextRadialOffset()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextVariableAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextVariableAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextVariableAnchor()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextAnchor()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextMaxAngle(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextMaxAngle()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextMaxAngle()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextWritingMode(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextWritingMode()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextWritingMode()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextRotate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextRotate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextRotate()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextPadding(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextPadding()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextPadding()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextKeepUpright(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextKeepUpright()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextKeepUpright()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextTransform(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextTransform()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextTransform()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextOffset(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextOffset()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextOffset()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextAllowOverlap(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextAllowOverlap()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextAllowOverlap()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextIgnorePlacement(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextIgnorePlacement()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextIgnorePlacement()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextOptional(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextOptional()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextOptional()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getIconOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getIconOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setIconOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setIconOpacityTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getIconColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getIconColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setIconColorTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setIconColorTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconHaloColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconHaloColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconHaloColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getIconHaloColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getIconHaloColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setIconHaloColorTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setIconHaloColorTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconHaloWidth(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconHaloWidth()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconHaloWidth()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getIconHaloWidthTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getIconHaloWidthTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setIconHaloWidthTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setIconHaloWidthTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconHaloBlur(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconHaloBlur()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconHaloBlur()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getIconHaloBlurTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getIconHaloBlurTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setIconHaloBlurTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setIconHaloBlurTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconTranslate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconTranslate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconTranslate()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getIconTranslateTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getIconTranslateTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setIconTranslateTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setIconTranslateTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getIconTranslateAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultIconTranslateAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getIconTranslateAnchor()));
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextOpacity(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextOpacity()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextOpacity()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getTextOpacityTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getTextOpacityTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setTextOpacityTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setTextOpacityTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getTextColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getTextColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setTextColorTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setTextColorTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextHaloColor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextHaloColor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextHaloColor()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getTextHaloColorTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getTextHaloColorTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setTextHaloColorTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setTextHaloColorTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextHaloWidth(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextHaloWidth()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextHaloWidth()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getTextHaloWidthTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getTextHaloWidthTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setTextHaloWidthTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setTextHaloWidthTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextHaloBlur(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextHaloBlur()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextHaloBlur()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getTextHaloBlurTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getTextHaloBlurTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setTextHaloBlurTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setTextHaloBlurTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextTranslate(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextTranslate()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextTranslate()));
    }

    jni::Local<jni::Object<TransitionOptions>> SymbolLayer::getTextTranslateTransition(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, mbgl::style::TransitionOptions{}));
        }
        mbgl::style::TransitionOptions options = toSymbolLayer(*layer.get()).getTextTranslateTransition();
        return std::move(*convert<jni::Local<jni::Object<TransitionOptions>>>(env, options));
    }

    void SymbolLayer::setTextTranslateTransition(jni::JNIEnv&, jlong duration, jlong delay) 
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer transition options: core layer is not available");
            return;
        }
        mbgl::style::TransitionOptions options;
        options.duration.emplace(mbgl::Milliseconds(duration));
        options.delay.emplace(mbgl::Milliseconds(delay));
        toSymbolLayer(*layer.get()).setTextTranslateTransition(options);
    }

    jni::Local<jni::Object<>> SymbolLayer::getTextTranslateAnchor(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer property: core layer is not available");
            return std::move(*convert<jni::Local<jni::Object<>>>(env, mbgl::style::SymbolLayer::getDefaultTextTranslateAnchor()));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, toSymbolLayer(*layer.get()).getTextTranslateAnchor()));
    }


    // SymbolJavaLayerPeerFactory

    SymbolJavaLayerPeerFactory::~SymbolJavaLayerPeerFactory() = default;

    namespace {
        jni::Local<jni::Object<Layer>> createJavaPeer(jni::JNIEnv& env, Layer* layer) {
            static auto& javaClass = jni::Class<SymbolLayer>::Singleton(env);
            static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
            return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(layer));
        }
    }  // namespace

    jni::Local<jni::Object<Layer>> SymbolJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, mbgl::style::Layer& layer) {
        assert(layer.baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new SymbolLayer(toSymbolLayer(layer)));
    }

    jni::Local<jni::Object<Layer>> SymbolJavaLayerPeerFactory::createJavaLayerPeer(jni::JNIEnv& env, std::unique_ptr<mbgl::style::Layer> layer) {
        assert(layer->baseImpl->getTypeInfo() == getTypeInfo());
        return createJavaPeer(env, new SymbolLayer(std::unique_ptr<mbgl::style::SymbolLayer>(static_cast<mbgl::style::SymbolLayer*>(layer.release()))));
    }

    void SymbolJavaLayerPeerFactory::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<SymbolLayer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<SymbolLayer>(
            env,
            javaClass,
            "nativePtr",
            jni::MakePeer<SymbolLayer, jni::String&, jni::String&>,
            "initialize",
            "finalize",
            METHOD(&SymbolLayer::getSymbolPlacement, "nativeGetSymbolPlacement"),
            METHOD(&SymbolLayer::getSymbolSpacing, "nativeGetSymbolSpacing"),
            METHOD(&SymbolLayer::getSymbolAvoidEdges, "nativeGetSymbolAvoidEdges"),
            METHOD(&SymbolLayer::getSymbolSortKey, "nativeGetSymbolSortKey"),
            METHOD(&SymbolLayer::getSymbolZOrder, "nativeGetSymbolZOrder"),
            METHOD(&SymbolLayer::getIconAllowOverlap, "nativeGetIconAllowOverlap"),
            METHOD(&SymbolLayer::getIconIgnorePlacement, "nativeGetIconIgnorePlacement"),
            METHOD(&SymbolLayer::getIconOptional, "nativeGetIconOptional"),
            METHOD(&SymbolLayer::getIconRotationAlignment, "nativeGetIconRotationAlignment"),
            METHOD(&SymbolLayer::getIconSize, "nativeGetIconSize"),
            METHOD(&SymbolLayer::getIconTextFit, "nativeGetIconTextFit"),
            METHOD(&SymbolLayer::getIconTextFitPadding, "nativeGetIconTextFitPadding"),
            METHOD(&SymbolLayer::getIconImage, "nativeGetIconImage"),
            METHOD(&SymbolLayer::getIconRotate, "nativeGetIconRotate"),
            METHOD(&SymbolLayer::getIconPadding, "nativeGetIconPadding"),
            METHOD(&SymbolLayer::getIconKeepUpright, "nativeGetIconKeepUpright"),
            METHOD(&SymbolLayer::getIconOffset, "nativeGetIconOffset"),
            METHOD(&SymbolLayer::getIconAnchor, "nativeGetIconAnchor"),
            METHOD(&SymbolLayer::getIconPitchAlignment, "nativeGetIconPitchAlignment"),
            METHOD(&SymbolLayer::getTextPitchAlignment, "nativeGetTextPitchAlignment"),
            METHOD(&SymbolLayer::getTextRotationAlignment, "nativeGetTextRotationAlignment"),
            METHOD(&SymbolLayer::getTextField, "nativeGetTextField"),
            METHOD(&SymbolLayer::getTextFont, "nativeGetTextFont"),
            METHOD(&SymbolLayer::getTextSize, "nativeGetTextSize"),
            METHOD(&SymbolLayer::getTextMaxWidth, "nativeGetTextMaxWidth"),
            METHOD(&SymbolLayer::getTextLineHeight, "nativeGetTextLineHeight"),
            METHOD(&SymbolLayer::getTextLetterSpacing, "nativeGetTextLetterSpacing"),
            METHOD(&SymbolLayer::getTextJustify, "nativeGetTextJustify"),
            METHOD(&SymbolLayer::getTextRadialOffset, "nativeGetTextRadialOffset"),
            METHOD(&SymbolLayer::getTextVariableAnchor, "nativeGetTextVariableAnchor"),
            METHOD(&SymbolLayer::getTextAnchor, "nativeGetTextAnchor"),
            METHOD(&SymbolLayer::getTextMaxAngle, "nativeGetTextMaxAngle"),
            METHOD(&SymbolLayer::getTextWritingMode, "nativeGetTextWritingMode"),
            METHOD(&SymbolLayer::getTextRotate, "nativeGetTextRotate"),
            METHOD(&SymbolLayer::getTextPadding, "nativeGetTextPadding"),
            METHOD(&SymbolLayer::getTextKeepUpright, "nativeGetTextKeepUpright"),
            METHOD(&SymbolLayer::getTextTransform, "nativeGetTextTransform"),
            METHOD(&SymbolLayer::getTextOffset, "nativeGetTextOffset"),
            METHOD(&SymbolLayer::getTextAllowOverlap, "nativeGetTextAllowOverlap"),
            METHOD(&SymbolLayer::getTextIgnorePlacement, "nativeGetTextIgnorePlacement"),
            METHOD(&SymbolLayer::getTextOptional, "nativeGetTextOptional"),
            METHOD(&SymbolLayer::getIconOpacityTransition, "nativeGetIconOpacityTransition"),
            METHOD(&SymbolLayer::setIconOpacityTransition, "nativeSetIconOpacityTransition"),
            METHOD(&SymbolLayer::getIconOpacity, "nativeGetIconOpacity"),
            METHOD(&SymbolLayer::getIconColorTransition, "nativeGetIconColorTransition"),
            METHOD(&SymbolLayer::setIconColorTransition, "nativeSetIconColorTransition"),
            METHOD(&SymbolLayer::getIconColor, "nativeGetIconColor"),
            METHOD(&SymbolLayer::getIconHaloColorTransition, "nativeGetIconHaloColorTransition"),
            METHOD(&SymbolLayer::setIconHaloColorTransition, "nativeSetIconHaloColorTransition"),
            METHOD(&SymbolLayer::getIconHaloColor, "nativeGetIconHaloColor"),
            METHOD(&SymbolLayer::getIconHaloWidthTransition, "nativeGetIconHaloWidthTransition"),
            METHOD(&SymbolLayer::setIconHaloWidthTransition, "nativeSetIconHaloWidthTransition"),
            METHOD(&SymbolLayer::getIconHaloWidth, "nativeGetIconHaloWidth"),
            METHOD(&SymbolLayer::getIconHaloBlurTransition, "nativeGetIconHaloBlurTransition"),
            METHOD(&SymbolLayer::setIconHaloBlurTransition, "nativeSetIconHaloBlurTransition"),
            METHOD(&SymbolLayer::getIconHaloBlur, "nativeGetIconHaloBlur"),
            METHOD(&SymbolLayer::getIconTranslateTransition, "nativeGetIconTranslateTransition"),
            METHOD(&SymbolLayer::setIconTranslateTransition, "nativeSetIconTranslateTransition"),
            METHOD(&SymbolLayer::getIconTranslate, "nativeGetIconTranslate"),
            METHOD(&SymbolLayer::getIconTranslateAnchor, "nativeGetIconTranslateAnchor"),
            METHOD(&SymbolLayer::getTextOpacityTransition, "nativeGetTextOpacityTransition"),
            METHOD(&SymbolLayer::setTextOpacityTransition, "nativeSetTextOpacityTransition"),
            METHOD(&SymbolLayer::getTextOpacity, "nativeGetTextOpacity"),
            METHOD(&SymbolLayer::getTextColorTransition, "nativeGetTextColorTransition"),
            METHOD(&SymbolLayer::setTextColorTransition, "nativeSetTextColorTransition"),
            METHOD(&SymbolLayer::getTextColor, "nativeGetTextColor"),
            METHOD(&SymbolLayer::getTextHaloColorTransition, "nativeGetTextHaloColorTransition"),
            METHOD(&SymbolLayer::setTextHaloColorTransition, "nativeSetTextHaloColorTransition"),
            METHOD(&SymbolLayer::getTextHaloColor, "nativeGetTextHaloColor"),
            METHOD(&SymbolLayer::getTextHaloWidthTransition, "nativeGetTextHaloWidthTransition"),
            METHOD(&SymbolLayer::setTextHaloWidthTransition, "nativeSetTextHaloWidthTransition"),
            METHOD(&SymbolLayer::getTextHaloWidth, "nativeGetTextHaloWidth"),
            METHOD(&SymbolLayer::getTextHaloBlurTransition, "nativeGetTextHaloBlurTransition"),
            METHOD(&SymbolLayer::setTextHaloBlurTransition, "nativeSetTextHaloBlurTransition"),
            METHOD(&SymbolLayer::getTextHaloBlur, "nativeGetTextHaloBlur"),
            METHOD(&SymbolLayer::getTextTranslateTransition, "nativeGetTextTranslateTransition"),
            METHOD(&SymbolLayer::setTextTranslateTransition, "nativeSetTextTranslateTransition"),
            METHOD(&SymbolLayer::getTextTranslate, "nativeGetTextTranslate"),
            METHOD(&SymbolLayer::getTextTranslateAnchor, "nativeGetTextTranslateAnchor"));
    }

} // namespace android
} // namespace mbgl
