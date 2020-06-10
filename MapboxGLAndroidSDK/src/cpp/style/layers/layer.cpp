#include "layer.hpp"
#include "../android_conversion.hpp"

#include <jni/jni.hpp>

#include <mbgl/style/style.hpp>
#include <mbgl/style/filter.hpp>
#include <mbgl/util/logging.hpp>

// Java -> C++ conversion
#include <mbgl/style/conversion/filter.hpp>
#include <mbgl/style/conversion/layer.hpp>
#include <mbgl/style/conversion/source.hpp>
#include <mbgl/style/conversion_impl.hpp>

// C++ -> Java conversion
#include "../conversion/property_value.hpp"
#include "custom_layer.hpp"
#include "background_layer.hpp"
#include <mbgl/style/filter.hpp>

#include <string>

namespace mbgl {
namespace android {

namespace {
    const std::string ERR_MSG_DEAD_CORE_PEER = "core layer is not available";
    constexpr auto EMPTY_STRING = "";
    constexpr auto ZERO = static_cast<jfloat >(0);
}

    /**
     * Invoked when the construction is initiated from the jvm through a subclass
     */
    Layer::Layer(std::unique_ptr<mbgl::style::Layer> coreLayer)
        : ownedLayer(std::move(coreLayer))
        , layer(ownedLayer->makeWeakPtr()) {
    }

    /**
     * Takes a non-owning reference. For lookup methods
     */
    Layer::Layer(mbgl::style::Layer& coreLayer) : layer(coreLayer.makeWeakPtr()) {}

    Layer::~Layer() {
    }

    void Layer::addToStyle(mbgl::style::Style& style, mbgl::optional<std::string> before) {
        // Check to see if we own the layer first
        if (!ownedLayer) {
            throw std::runtime_error("Cannot add layer twice");
        }

        // Add layer to map
        style.addLayer(releaseCoreLayer(), before);
    }

    void Layer::setLayer(std::unique_ptr<mbgl::style::Layer> sourceLayer) {
        this->ownedLayer = std::move(sourceLayer);
    }

    std::unique_ptr<mbgl::style::Layer> Layer::releaseCoreLayer() {
        assert(ownedLayer != nullptr);
        return std::move(ownedLayer);
    }

    jni::Local<jni::String> Layer::getId(jni::JNIEnv& env) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer id: " + ERR_MSG_DEAD_CORE_PEER);
            return jni::Make<jni::String>(env, EMPTY_STRING);
        }
        return jni::Make<jni::String>(env, layer->getID());
    }

    style::Layer& Layer::get() {
        return *layer.get();
    }

    void Layer::setProperty(jni::JNIEnv& env, const jni::String& jname, const jni::Object<>& jvalue) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set layer property: " + ERR_MSG_DEAD_CORE_PEER);
            return;
        }
        // Convert and set property
        optional<mbgl::style::conversion::Error> error =
            layer->setProperty(jni::Make<std::string>(env, jname), Value(env, jvalue));
        if (error) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set layer property: " + jni::Make<std::string>(env, jname) + " " + error->message);
            return;
        }
    }

    void Layer::setFilter(jni::JNIEnv& env, const jni::Array<jni::Object<>>& jfilter) {
        using namespace mbgl::style;
        using namespace mbgl::style::conversion;

        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set filter: " + ERR_MSG_DEAD_CORE_PEER);
            return;
        }

        Error error;
        optional<Filter> converted = convert<Filter>(Value(env, jfilter), error);
        if (!converted) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set layer filter: " + error.message);
            return;
        }

        layer->setFilter(std::move(*converted));
    }

    jni::Local<jni::Object<gson::JsonElement>> Layer::getFilter(jni::JNIEnv& env) {
        using namespace mbgl::style;
        using namespace mbgl::style::conversion;

        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer filter: " + ERR_MSG_DEAD_CORE_PEER);
            return jni::Local<jni::Object<gson::JsonElement>>(env, nullptr);
        }

        Filter filter = layer->getFilter();
        if (filter.expression) {
            mbgl::Value expressionValue = (*filter.expression)->serialize();
            return gson::JsonElement::New(env, expressionValue);
        } else {
            return jni::Local<jni::Object<gson::JsonElement>>(env, nullptr);
        }
    }

    void Layer::setSourceLayer(jni::JNIEnv& env, const jni::String& sourceLayer) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set layer's source layer: " + ERR_MSG_DEAD_CORE_PEER);
            return;
        }
        layer->setSourceLayer(jni::Make<std::string>(env, sourceLayer));
    }

    jni::Local<jni::String> Layer::getSourceLayer(jni::JNIEnv& env) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer's source layer: " + ERR_MSG_DEAD_CORE_PEER);
            return jni::Make<jni::String>(env, EMPTY_STRING);
        }
        return jni::Make<jni::String>(env, layer->getSourceLayer());
    }

    jni::Local<jni::String> Layer::getSourceId(jni::JNIEnv& env) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer source id: " + ERR_MSG_DEAD_CORE_PEER);
            return jni::Make<jni::String>(env, EMPTY_STRING);
        }
        return jni::Make<jni::String>(env, layer->getSourceID());
    }

    jni::jfloat Layer::getMinZoom(jni::JNIEnv&){
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer min zoom: " + ERR_MSG_DEAD_CORE_PEER);
            return ZERO;
        }
        return layer->getMinZoom();
    }

    jni::jfloat Layer::getMaxZoom(jni::JNIEnv&) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer max zoom: " + ERR_MSG_DEAD_CORE_PEER);
            return ZERO;
        }
        return layer->getMaxZoom();
    }

    void Layer::setMinZoom(jni::JNIEnv&, jni::jfloat zoom) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set layer min zoom: " + ERR_MSG_DEAD_CORE_PEER);
            return;
        }
        layer->setMinZoom(zoom);
    }

    void Layer::setMaxZoom(jni::JNIEnv&, jni::jfloat zoom) {
        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set layer max zoom: " + ERR_MSG_DEAD_CORE_PEER);
            return;
        }
        layer->setMaxZoom(zoom);
    }

    jni::Local<jni::Object<>> Layer::getVisibility(jni::JNIEnv& env) {
        using namespace mbgl::android::conversion;

        auto guard = layer.lock();
        if (!layer) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get layer visibility: " + ERR_MSG_DEAD_CORE_PEER);
            return std::move(*convert<jni::Local<jni::Object<>>>(env, style::VisibilityType::None));
        }
        return std::move(*convert<jni::Local<jni::Object<>>>(env, layer->getVisibility()));
    }

    void Layer::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<Layer>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<Layer>(
            env,
            javaClass,
            "nativePtr",
            METHOD(&Layer::getId, "nativeGetId"),
            METHOD(&Layer::setProperty,
                   "nativeSetLayoutProperty"), // TODO : Export only nativeSetProperty() when #15970 lands.
            METHOD(&Layer::setProperty, "nativeSetPaintProperty"),
            METHOD(&Layer::setFilter, "nativeSetFilter"),
            METHOD(&Layer::getFilter, "nativeGetFilter"),
            METHOD(&Layer::setSourceLayer, "nativeSetSourceLayer"),
            METHOD(&Layer::getSourceLayer, "nativeGetSourceLayer"),
            METHOD(&Layer::getSourceId, "nativeGetSourceId"),
            METHOD(&Layer::getMinZoom, "nativeGetMinZoom"),
            METHOD(&Layer::getMaxZoom, "nativeGetMaxZoom"),
            METHOD(&Layer::setMinZoom, "nativeSetMinZoom"),
            METHOD(&Layer::setMaxZoom, "nativeSetMaxZoom"),
            METHOD(&Layer::getVisibility, "nativeGetVisibility"));
    }

} // namespace android
} // namespace mbgl
