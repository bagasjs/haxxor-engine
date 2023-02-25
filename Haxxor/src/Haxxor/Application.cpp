#include "Application.h"
#include "Haxxor/Renderer/RendererAPI.h"

namespace Haxxor {
    Application::Application(const std::string& name, uint32_t width, uint32_t height)
    {
        RendererAPI::Set(RendererAPI::Kind::OPENGL);
        RendererAPI::Init();
        m_Window = Window::Create(name, width, height);
        m_Renderer = Renderer::Create(m_Window);
    }

    void Application::Run() {
        while(!m_Window->ShouldClose()) {
            m_Window->PollEvents();

            for(Ref<Layer> layer : m_Layers)
                layer->OnUpdate();

            m_Window->SwapBuffers();
        }
    }

    Application::~Application()
    {
        for(Ref<Layer> layer : m_Layers)
            layer->OnDetach();
    }
}