#include "GlfwWindow.h"

#include "Haxxor/Renderer/RendererAPI.h"
#include "Haxxor/Events/ApplicationEvent.h"
#include "Haxxor/Events/KeyEvent.h"
#include "Haxxor/Events/MouseEvent.h"

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

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, true);
					data.EventCallback(event);
					break;
				}
			}
		});

    	glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});
    }

    void GlfwWindow::SwapBuffers() 
    {
        glfwSwapBuffers(m_Window);
    }

    void GlfwWindow::PollEvents() 
    {
        glfwPollEvents();
    }

    void GlfwWindow::SetVSync(bool enable)
    {
        glfwSwapInterval(enable ? 1 : 0);
        m_Data.VSync = enable;
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