#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/VertexArray.h"
#include <glm/glm.hpp>

namespace Haxxor {
    class HXAPI Renderer
    {
    public:
        static void Init(const Ref<Window>& window);
        static void OnWindowResize();
        inline static glm::vec2 GetViewport() { return s_Viewport; };

    private:
        static Ref<Window> s_Window;
        static glm::vec2 s_Viewport;
    };
}