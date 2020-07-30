cmake_minimum_required(VERSION 3.10)

if (NOT ANDROID_NDK_TOOLCHAIN_INCLUDED)
    message(FATAL_ERROR "-- Toolchain file not included, see https://developer.android.com/ndk/guides/cmake")
endif ()

add_library(
    example-custom-layer MODULE
    ${PROJECT_SOURCE_DIR}/custom_layer.hpp
    ${PROJECT_SOURCE_DIR}/example_custom_layer.cpp
)

target_link_libraries(
    example-custom-layer
    PRIVATE
        GLESv2
        log
)

