#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor {
    class HXAPI Renderer {
    public:
        virtual ~Renderer() {}

    public:
        static Ref<Renderer> Create(const Ref<Window>& window);
    };
}