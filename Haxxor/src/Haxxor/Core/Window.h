#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Event.h"

namespace Haxxor {
    class HXAPI Window 
    {
    public:
        virtual ~Window() {};

        virtual void SwapBuffers() = 0;
        virtual Event PollEvent() = 0;

        virtual void* GetNativeHandle() = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() = 0;
    public:
        static Ref<Window> Create(const std::string& name = "My Window", uint32_t width = 640, uint32_t height = 480);
    };
}