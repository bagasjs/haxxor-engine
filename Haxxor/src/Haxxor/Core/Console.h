#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor {
    class HXAPI Console {
    public:
        static void Init();
        static void Shutdown();

        static void Log();
        static void Info();
        static void Warn();
        static void Error();
    };
}