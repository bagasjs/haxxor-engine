#include "GlfwWindow.h"

#include "Haxxor/Renderer/RendererAPI.h"

#include <GLFW/glfw3.h>

// TODO: Remove this
#include <stdio.h>

namespace Haxxor {
    static int s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char* description) 
    {
        // TODO: change into Console::Error
        printf("GLFW Error (%i): %s", error, description);
    }

    GlfwWindow::~GlfwWindow() 
    {
        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;
        if(s_GLFWWindowCount == 0) {
            glfwTerminate();
        }
    }

    GlfwWindow::GlfwWindow(const std::string& name, uint32_t width, uint32_t height) 
    {
        m_Data.Name = name;
        m_Data.Width = width;
        m_Data.Height = height;

        if(s_GLFWWindowCount == 0) {
            // TODO: add error checking or assertion
            glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        if(RendererAPI::Get() == RendererAPI::Kind::OPENGL)
        {
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Name.c_str(), nullptr, nullptr);
        ++s_GLFWWindowCount;

        // TODO: remove this into graphic context class
        glfwMakeContextCurrent(m_Window);
    }

    void GlfwWindow::SwapBuffers() 
    {
        glfwSwapBuffers(m_Window);
    }

    void GlfwWindow::PollEvents() 
    {
        glfwPollEvents();
    }

    bool GlfwWindow::ShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    }

    void* GlfwWindow::GetNativeHandle()
    {
        return (void*) m_Window;
    }
}