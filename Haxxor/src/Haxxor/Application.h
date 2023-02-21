#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"

namespace Haxxor {
    class HXAPI Application {
    public:
        virtual ~Application() {};

        void Run();
    
    protected:
        virtual void Update() {};
        virtual void Setup() {};
        virtual void Clean() {};
    protected:
        uint32_t m_WindowWidth = 1280;
        uint32_t m_WindowHeight = 720;
        std::string m_WindowName = "Haxxor Engine";
    private:
        Ref<Window> m_Window;
    };
}