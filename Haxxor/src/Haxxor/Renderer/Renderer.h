#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"

namespace Haxxor {
    enum class RenderAPI {
        OPENGL = 0,
    };

    class HXAPI Renderer {
    public:
        virtual ~Renderer() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() = 0;

    public:
        static Ref<Renderer> Create(const Ref<Window>& window);
    };
}