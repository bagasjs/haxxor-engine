#pragma once

#include "Haxxor/Core/Common.h"

#ifndef HX_RELEASE
    #include <stdio.h>
    #define HX_LOG_INFO(FMT, ...) printf("(%s in line %s)[INFO]" FMT, __FILE__, __LINE__, __VA_ARGS__)
    #define HX_LOG_WARN(FMT, ...) printf("(%s in line %s)[WARN]" FMT, __FILE__, __LINE__, __VA_ARGS__)
    #define HX_LOG_ERROR(FMT, ...) printf("(%s in line %s)[ERROR]" FMT, __FILE__, __LINE__, __VA_ARGS__)
    #define HX_ASSERT(CONDITION) if(CONDITION) {} else { printf("Assertion Error at %s in line %s", __FILE__, __LINE__); }
#else
#define HX_LOG_INFO(FMT, ...)
    #define HX_LOG_WARN(FMT, ...)
    #define HX_LOG_ERROR(FMT, ...)
    #define HX_ASSERT(CONDITION)
#endif