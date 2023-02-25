#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Events/ApplicationEvent.h"
#include "Haxxor/Renderer/Renderer.h"
#include "Haxxor/Layer.h"

namespace Haxxor {
    class HXAPI Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        
        Window& GetWindow() { return *m_Window; }
        Renderer& GetRenderer() { return *m_Renderer; }
        static Application& Get() { return *s_Instance; }
        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

    private:
        Ref<Window> m_Window;
        Ref<Renderer> m_Renderer;
        static Application* s_Instance;
        LayerStack m_LayerStack;
        bool m_Running;
    };
}