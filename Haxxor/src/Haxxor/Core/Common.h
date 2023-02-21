#pragma once

// Static assert
#if defined(__clang__) || defined(__gcc__)
    #define HX_STATIC_ASSERT _Static_assert
#else
    #define HX_STATIC_ASSERT static_assert
#endif

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define HX_PLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on Windows!"
    #endif
#elif defined(__linux__) || defined(__gnu_linux__)
    #define HX_PLATFORM_LINUX 1
    #if defined(__ANDROID__)
        #define HX_PLATFORM_ANDROID 1
    #endif
#elif defined(__unix__)
    #define HX_PLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
    #define HX_PLATFORM_POSIX 1
#elif __APPLE__
    #define HX_PLATFORM_APPLE 1
#else
    #error "Unknown platform!"
#endif

#ifdef HX_BUILD_SHAREDLIB
    #ifdef HX_EXPORT
        #ifdef _MSC_VER
            #define HXAPI __declspec(dllexport)
        #else 
            #define HXAPI __attribute__((visibility("default")))
        #endif
    #else
        #ifdef _MSC_VER
            #define HXAPI __declspec(dllimport)
        #else
            #define HXAPI
        #endif
    #endif
#else
    #define HXAPI
#endif


#include <stdint.h>
#include <memory>
#include <string>

namespace Haxxor {
    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ...Args>
    constexpr Ref<T> MakeRef(Args&& ...args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ...Args>
    constexpr Scope<T> MakeScope(Args&& ...args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
}