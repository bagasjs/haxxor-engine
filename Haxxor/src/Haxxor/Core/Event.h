#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Codes.h"

namespace Haxxor
{

    enum class EventType
    {
        NONE = 0,
        WINDOW_CLOSE = 1, 
        WINDOW_RESIZED = 2, 
        WINDOW_FOCUS = 3, 
        WINDOW_LOST_FOCUS = 4, 
        WINDOW_MOVED = 5,
        KEY_PRESSED = 6, 
        KEY_RELEASED = 7, 
        KEY_REPEATED = 8, 
        KEY_TYPED = 9,
        MOUSE_BUTTON_PRESSED = 10, 
        MOUSE_BUTTON_RELEASED = 11, 
        MOUSE_MOVED = 12, 
        MOUSE_SCROLLED = 13
    };

    struct Event
    {
        EventType Type;
        // Key Events
        KeyCode Key;
        char KeyChar;

        float MouseX, MouseY;

        Event()
            : Type(EventType::NONE), Key(KeyCode::KEY_UNKNOWN), 
            KeyChar(0), MouseX(0), MouseY(0)
        {}
    };
}