#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/Renderer.h"

namespace Haxxor {
    class Layer
    {
    public:
        ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
    };

    class HXAPI Application {
    public:
        Application(const std::string& name = "Haxxor Example Application", 
            uint32_t width = 640, uint32_t height = 480);
        virtual ~Application();
        void Run();

        template<typename T>
        void AddLayer()
        {
            Ref<Layer> layer = MakeRef<T>();
            layer->OnAttach();
            m_Layers.push_back(layer);
        }

    private:
        Ref<Window> m_Window;
        Ref<Renderer> m_Renderer;
        std::vector<Ref<Layer>> m_Layers;
    };
}