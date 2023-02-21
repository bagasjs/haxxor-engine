#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"

namespace Haxxor {
    class HXAPI Application {
    public:
        Application();
        ~Application();

        void Run();
    
    protected:
        virtual void Update() = 0;
        virtual void Setup() = 0;
        virtual void Clean() = 0;
    protected:
        Ref<Window> m_Window;
    };
}