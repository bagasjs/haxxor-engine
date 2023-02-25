#include "Application.h"
#include "Haxxor/Renderer/RendererAPI.h"
#include "Haxxor/Core/Event.h"
#include "Haxxor/Core/Logging.h"

namespace Haxxor {
    Application::Application(const std::string& name, uint32_t width, uint32_t height)
        : m_Running(false)
    {
        RendererAPI::Set(RendererAPI::Kind::OPENGL);
        RendererAPI::Init();
        m_Window = Window::Create(name, width, height);
        m_Renderer = Renderer::Create(m_Window);
    }

    void Application::Run() 
    {
        m_Running = true;
        while(m_Running) 
        {
            Event event = m_Window->PollEvent();
            if(event.Type == EventType::WINDOW_CLOSE) m_Running = false;
            if(event.Type == EventType::WINDOW_RESIZED)
            {
                HX_LOG_INFO("New window size is %u, %u", m_Window->GetWidth(), m_Window->GetHeight());
                RendererAPI::SetViewport(0, 0, m_Window->GetWidth(), m_Window->GetHeight());
            }
            for(Ref<Layer> layer : m_Layers)
            {
                layer->OnEvent(event);
                layer->OnUpdate();
            }
            m_Window->SwapBuffers();
        }
    }

    Application::~Application()
    {
        for(Ref<Layer> layer : m_Layers)
            layer->OnDetach();
    }
}