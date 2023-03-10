#include "Application.h"
#include "Haxxor/Core/Event.h"
#include "Haxxor/Core/Logging.h"
#include "Haxxor/Renderer/RendererAPI.h"
#include "Haxxor/Renderer/Renderer.h"

namespace Haxxor {
    Application::Application(const std::string& name, uint32_t width, uint32_t height)
        : m_Running(false)
    {
        RendererAPI::Set(RendererAPI::Kind::OPENGL);
        m_Window = Window::Create(name, width, height);
        Renderer::Init(m_Window);
        m_Window->SetVSync(true);
    }

    void Application::Run() 
    {
        m_Running = true;
        while(m_Running) 
        {
            Event event = m_Window->PollEvent();
            if(event.Type == EventType::WINDOW_CLOSE) 
                m_Running = false;

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