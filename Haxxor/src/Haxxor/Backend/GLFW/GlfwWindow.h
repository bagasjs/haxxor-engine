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
        
        void* GetNativeHandle() override;
    private:
        GLFWwindow* m_Window;
        struct WindowData {
            std::string Name;
            uint32_t Width, Height;
        };
        WindowData m_Data;
    };
}