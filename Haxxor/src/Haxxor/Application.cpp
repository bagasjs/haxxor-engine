#include "Application.h"

#include "Haxxor/Renderer/RendererAPI.h"


namespace Haxxor {
    void Application::Run() {
        Init();

        RendererAPI::Init();
        m_Window = Window::Create(m_WindowName, m_WindowWidth, m_WindowHeight);
        m_Renderer = Renderer::Create(m_Window);

        Setup(m_Renderer);

        while(!m_Window->ShouldClose()) {
            m_Window->PollEvents();

            // Render here
            Update(m_Renderer);

            m_Window->SwapBuffers();
        }

        Clean();
    }
}