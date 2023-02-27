#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor {
    class HXAPI Renderer
    {
    public:
        static void Init(const Ref<Window>& window);
        static void OnWindowResize(uint32_t width, uint32_t height);

    private:
        static Ref<Window> s_Window;
    };
}