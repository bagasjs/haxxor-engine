#include "LinuxWindow.h"

#include <GLFW/glfw3.h>

// TODO: Remove this
#include <stdio.h>

namespace Haxxor {
    static int s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char* description) {
        // TODO: change into Console::Error
        printf("GLFW Error (%i): %s", error, description);
    }

    LinuxWindow::~LinuxWindow() {
        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;
        if(s_GLFWWindowCount == 0) {
            glfwTerminate();
        }
    }

    LinuxWindow::LinuxWindow(const std::string& name, uint32_t width, uint32_t height) 
    {
        m_Data.Name = name;
        m_Data.Width = width;
        m_Data.Height = height;

        if(s_GLFWWindowCount == 0) {
            // TODO: add error checking or assertion
            glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Name.c_str(), nullptr, nullptr);
        ++s_GLFWWindowCount;

        // TODO: remove this into graphic context class
        glfwMakeContextCurrent(m_Window);
    }

    void LinuxWindow::SwapBuffers() 
    {
        glfwSwapBuffers(m_Window);
    }

    void LinuxWindow::PollEvents() 
    {
        glfwPollEvents();
    }

    bool LinuxWindow::ShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    }

    void* LinuxWindow::GetNativeHandle()
    {
        return (void*) m_Window;
    }
}