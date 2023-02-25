#pragma once

// Static assert
#if defined(__clang__) || defined(__gcc__)
    #define HX_STATIC_ASSERT _Static_assert
#else
    #define HX_STATIC_ASSERT static_assert
#endif

#ifdef _MSC_VER
    #include <intrin.h>
    #define DEBUG_BREAK() __debugbreak()
#else
    #define DEBUG_BREAK() __builtin_trap()
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
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <sstream>
#include <algorithm>

#define BIT(x) (1 << x)
#define HX_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

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