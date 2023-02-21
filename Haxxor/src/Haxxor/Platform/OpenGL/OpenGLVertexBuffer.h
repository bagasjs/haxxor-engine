#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/VertexBuffer.h"

namespace Haxxor {
    class HXAPI OpenGLVertexBuffer {
    public:
        OpenGLVertexBuffer(uint32_t count, float* data);
        virtual ~OpenGLVertexBuffer();
        void Enable();
        void Disable();
        void SetData(uint32_t count, float* data);
        inline uint32_t GetRendererID() const { return m_RendererID; }
    private:
        uint32_t m_RendererID;
    };
}