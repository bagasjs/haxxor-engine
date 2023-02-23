#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/Renderer.h"

namespace Haxxor {
    class HXAPI Application {
    public:
        virtual ~Application() {};
        void Run();
    
    protected:
        virtual void Init() {};
        virtual void Setup(Ref<Renderer> renderer) {};
        virtual void Update(Ref<Renderer> renderer) {};
        virtual void Clean() {};

    protected:
        uint32_t m_WindowWidth = 1280;
        uint32_t m_WindowHeight = 720;
        std::string m_WindowName = "Haxxor Application";

    private:
        Ref<Window> m_Window;
        Ref<Renderer> m_Renderer;
    };
}