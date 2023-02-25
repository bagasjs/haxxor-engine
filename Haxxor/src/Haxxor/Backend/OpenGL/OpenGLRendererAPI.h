#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/RendererAPI.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor 
{
    class HXAPI OpenGLRendererAPI : public RendererAPI
    {
    public:
        OpenGLRendererAPI() = default;
        virtual ~OpenGLRendererAPI() = default;

    protected:
      void ImplSetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
      void ImplSetClearColor(float r, float g, float b, float a);
      void ImplClear();
      void ImplDrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount);
      void ImplDrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount);
      void ImplSetLineWidth(float width);
      void ImplLogError();
    };
}