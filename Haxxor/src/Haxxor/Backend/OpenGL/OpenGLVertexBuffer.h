#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/VertexBuffer.h"

namespace Haxxor {
    class HXAPI OpenGLVertexBuffer : public VertexBuffer 
    {
    public:
        OpenGLVertexBuffer(uint32_t count, float* data);
        virtual ~OpenGLVertexBuffer();
        void Enable();
        void Disable();
        void SetData(uint32_t count, float* data);
        inline uint32_t GetRendererID() const { return m_RendererID; }

        inline const BufferLayout& GetLayout() const { return m_Layout; }
        inline void SetLayout(const BufferLayout& layout) { m_Layout = layout; }
    private:
        uint32_t m_RendererID;
        BufferLayout m_Layout;
    };
}