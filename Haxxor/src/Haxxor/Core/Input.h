#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/KeyCodes.h"
#include "Haxxor/Core/MouseCodes.h"

namespace Haxxor
{
    class HXAPI Input
    {
    public:
        static bool IsKeyPressed(KeyCode keycodes);
        static bool IsMouseButtonPressed(MouseCode button);
        static float GetMouseX();
        static float GetMouseY();
    };
}