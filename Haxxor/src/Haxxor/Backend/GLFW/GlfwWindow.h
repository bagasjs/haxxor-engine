#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"

struct GLFWwindow;

namespace Haxxor {
    class HXAPI GlfwWindow : public Window {
    public:
        GlfwWindow(const std::string& name, uint32_t width, uint32_t height);

        virtual ~GlfwWindow();
        
        void SwapBuffers() override;
        void PollEvents() override;
        bool ShouldClose() override;
        void SetVSync(bool enable) override;
        
        void* GetNativeHandle() override;
        void SetEventCallback(const EventCallbackFn& fn) override { m_Data.EventCallback = fn; }
    private:
        GLFWwindow* m_Window;
        struct WindowData {
            std::string Name;
            uint32_t Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };
}