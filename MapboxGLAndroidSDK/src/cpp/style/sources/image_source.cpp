#include "image_source.hpp"

// Java -> C++ conversion
#include "../android_conversion.hpp"

// C++ -> Java conversion
#include "../../conversion/conversion.hpp"
#include <mbgl/style/conversion_impl.hpp>
#include <mbgl/util/premultiply.hpp>

#include "bitmap.hpp"
#include <string>
#include <array>

namespace mbgl {
namespace android {

    ImageSource::ImageSource(jni::JNIEnv& env, const jni::String& sourceId, const jni::Object<LatLngQuad>& coordinatesObject)
        : Source(env, std::make_unique<mbgl::style::ImageSource>(
                jni::Make<std::string>(env, sourceId),
                LatLngQuad::getLatLngArray(env, coordinatesObject)
                )
            ) {
    }

    ImageSource::ImageSource(jni::JNIEnv& env, mbgl::style::Source& coreSource, AndroidRendererFrontend* frontend)
        : Source(env, coreSource, createJavaPeer(env), frontend) {}

    ImageSource::~ImageSource() = default;

    void ImageSource::setURL(jni::JNIEnv& env, const jni::String& url) {
        auto guard = source.lock();
        if (!source) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set image source URL: core source is not available.");
            return;
        }
        source->as<mbgl::style::ImageSource>()->ImageSource::setURL(jni::Make<std::string>(env, url));
    }

    jni::Local<jni::String> ImageSource::getURL(jni::JNIEnv& env) {
        auto guard = source.lock();
        if (!source) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to get image source URL: core source is not available.");
            return jni::Local<jni::String>();
        }
        optional<std::string> url =source->as<mbgl::style::ImageSource>()->ImageSource::getURL();
        return url ? jni::Make<jni::String>(env, *url) : jni::Local<jni::String>();
    }

    void ImageSource::setImage(jni::JNIEnv& env, const jni::Object<Bitmap>& bitmap) {
        auto guard = source.lock();
        if (!source) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set image source's image : core source is not available.");
            return;
        }
       source->as<mbgl::style::ImageSource>()->setImage(Bitmap::GetImage(env, bitmap));
    }

    void ImageSource::setCoordinates(jni::JNIEnv& env, const jni::Object<LatLngQuad>& coordinatesObject) {
        auto guard = source.lock();
        if (!source) {
            mbgl::Log::Error(mbgl::Event::JNI, "Failed to set image source coordinates : core source is not available.");
            return;
        }
       source->as<mbgl::style::ImageSource>()->setCoordinates(
                LatLngQuad::getLatLngArray(env, coordinatesObject));
    }

    jni::Local<jni::Object<Source>> ImageSource::createJavaPeer(jni::JNIEnv& env) {
        static auto& javaClass = jni::Class<ImageSource>::Singleton(env);
        static auto constructor = javaClass.GetConstructor<jni::jlong>(env);
        return javaClass.New(env, constructor, reinterpret_cast<jni::jlong>(this));
    }

    void ImageSource::registerNative(jni::JNIEnv& env) {
        // Lookup the class
        static auto& javaClass = jni::Class<ImageSource>::Singleton(env);

        #define METHOD(MethodPtr, name) jni::MakeNativePeerMethod<decltype(MethodPtr), (MethodPtr)>(name)

        // Register the peer
        jni::RegisterNativePeer<ImageSource>(
                env, javaClass, "nativePtr",
                jni::MakePeer<ImageSource, const jni::String&, const jni::Object<LatLngQuad>&>,
                "initialize",
                "finalize",
                METHOD(&ImageSource::setURL, "nativeSetUrl"),
                METHOD(&ImageSource::getURL, "nativeGetUrl"),
                METHOD(&ImageSource::setImage, "nativeSetImage"),
                METHOD(&ImageSource::setCoordinates, "nativeSetCoordinates")
        );
    }

} // namespace android
} // namespace mbgl
