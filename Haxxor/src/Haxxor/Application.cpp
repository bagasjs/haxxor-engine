#include "Application.h"

#include "Haxxor/Renderer/RendererAPI.h"


namespace Haxxor {
    Application* Application::s_Instance = nullptr;

    Application::Application()
        : m_Running(false)
    {
        s_Instance = this;
        RendererAPI::Set(RendererAPI::Kind::OPENGL);
        RendererAPI::Init();
        m_Window = Window::Create("Haxxor Application", 1280, 720);
        m_Window->SetEventCallback(HX_BIND_EVENT_FN(Application::OnEvent));
        m_Renderer = Renderer::Create(m_Window);
    }

    Application::~Application()
    {
    }

    void Application::Run() 
    {
        m_Running = true;

        while(m_Running = true) {
            m_Window->PollEvents();

            for(Layer* layer : m_LayerStack)
                layer->OnUpdate();

        }
            m_Window->SwapBuffers();

        s_Instance = nullptr;
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(HX_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(HX_BIND_EVENT_FN(Application::OnWindowResize));
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        RendererAPI::SetViewport(0, 0, e.GetWidth(), e.GetHeight());
        return false;
    }
}