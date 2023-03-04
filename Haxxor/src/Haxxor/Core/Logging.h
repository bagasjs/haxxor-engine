#pragma once

#include "Haxxor/Core/Common.h"

#ifndef HX_RELEASE
    #include <stdio.h>
    #define HX_LOG_INFO(FMT, ...) printf("(%s: %d)[INFO]\n" FMT "\n", __FILE__, __LINE__, __VA_ARGS__)
    #define HX_LOG_WARN(FMT, ...) printf("(%s: %d)[WARN]\n" FMT "\n", __FILE__, __LINE__, __VA_ARGS__)
    #define HX_LOG_ERROR(FMT, ...) printf("(%s: %d)[ERROR]\n" FMT "\n", __FILE__, __LINE__, __VA_ARGS__)
    #define HX_ASSERT(CONDITION, MSG) if(CONDITION) {} else { printf("[Assertion Error at %s:%d]: %s", __FILE__, __LINE__, MSG); }
#else
#define HX_LOG_INFO(FMT, ...)
    #define HX_LOG_WARN(FMT, ...)
    #define HX_LOG_ERROR(FMT, ...)
    #define HX_ASSERT(CONDITION, MSG)
#endif