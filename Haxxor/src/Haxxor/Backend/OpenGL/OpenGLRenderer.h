#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/Renderer.h"

namespace Haxxor {
    class HXAPI OpenGLRenderer : public Renderer {
    public:
        OpenGLRenderer(const Ref<Window>& window);
        virtual ~OpenGLRenderer() = default;
    };
}