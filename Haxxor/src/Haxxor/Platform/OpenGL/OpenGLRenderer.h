#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/Renderer.h"

namespace Haxxor {
    class HXAPI OpenGLRenderer : public Renderer {
    public:
        OpenGLRenderer(const Ref<Window>& window);
        virtual ~OpenGLRenderer() = default;
        void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
        void SetClearColor(float r, float g, float b, float a);
        void Clear();
        void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount);
        void DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount);
        void SetLineWidth(float width);
    };
}