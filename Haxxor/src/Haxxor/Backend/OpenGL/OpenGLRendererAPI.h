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
      void Impl_SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
      void Impl_SetClearColor(float r, float g, float b, float a);
      void Impl_Clear();
      void Impl_DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount);
      void Impl_DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount);
      void Impl_SetLineWidth(float width);
      void Impl_LogError();
    };
}