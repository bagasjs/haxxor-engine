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

        if(s_GLFWWindowCount == 0) 
        {
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

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;
            data.Event.Type = EventType::WINDOW_RESIZED;
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Event.Type = EventType::WINDOW_CLOSE;
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            if(key <= 0) data.Event.Key = KeyCode::KEY_UNKNOWN;
            else data.Event.Key = (KeyCode) key;
            switch (action)
            {
                case GLFW_PRESS:
                    data.Event.Type = EventType::KEY_PRESSED;
                    break;
                case GLFW_RELEASE:
                    data.Event.Type = EventType::KEY_RELEASED;
                    break;
                case GLFW_REPEAT:
                    data.Event.Type = EventType::KEY_REPEATED;
                    break;
            }
        });
        
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Event.Type = EventType::MOUSE_MOVED;
            data.Event.MouseX = xPos;
            data.Event.MouseY = yPos;
		});
    }

    void GlfwWindow::SwapBuffers()
    {
        glfwSwapBuffers(m_Window);
    }

    Event GlfwWindow::PollEvent()
    {
        m_Data.Event = Event();
        glfwPollEvents();
        return m_Data.Event;
    }

    void* GlfwWindow::GetNativeHandle()
    {
        return (void*) m_Window;
    }
    void GlfwWindow::SetVSync(bool enabled)
    {
        glfwSwapInterval(enabled ? 1 : 0);
        m_Data.VSync = enabled;
    }
}