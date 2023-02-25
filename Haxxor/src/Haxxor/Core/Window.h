#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Events/Event.h"

namespace Haxxor {
    class HXAPI Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void SetVSync(bool enable) = 0;
        virtual void SwapBuffers() = 0;
        virtual void PollEvents() = 0;
        virtual bool ShouldClose() = 0; // change this into an event system
        virtual void* GetNativeHandle() = 0;
        virtual void SetEventCallback(const EventCallbackFn&) = 0;
    public:
        static Ref<Window> Create(const std::string& name = "My Window", uint32_t width = 640, uint32_t height = 480);
    };
}