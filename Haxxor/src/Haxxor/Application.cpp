#include "Application.h"


namespace Haxxor {
    void Application::Run() {
        Setup();
        m_Window = Window::Create(m_WindowName, m_WindowWidth, m_WindowHeight);
        m_Renderer = Renderer::Create(m_Window);
        while(!m_Window->ShouldClose()) {
            m_Window->PollEvents();
            // Render here
            Update();
            m_Window->SwapBuffers();
        }
        Clean();
    }
}