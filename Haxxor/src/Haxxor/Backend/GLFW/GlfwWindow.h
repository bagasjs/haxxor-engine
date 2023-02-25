#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Core/Event.h"

struct GLFWwindow;

namespace Haxxor {
    using AppEvent = Event;

    class HXAPI GlfwWindow : public Window 
    {
    public:
        GlfwWindow(const std::string& name, uint32_t width, uint32_t height);

        virtual ~GlfwWindow();

        void SwapBuffers() override;
        Event PollEvent() override;

        void SetVSync(bool enabled) override;
        inline bool IsVSync() override { return m_Data.VSync; };
        void* GetNativeHandle() override;

    private:
        GLFWwindow* m_Window;
        struct WindowData {
            std::string Name;
            uint32_t Width, Height;
            bool VSync;
            AppEvent Event;
        };
        WindowData m_Data;
    };
}