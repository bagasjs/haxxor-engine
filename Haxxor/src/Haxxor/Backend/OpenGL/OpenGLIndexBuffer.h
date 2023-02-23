#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/IndexBuffer.h"

namespace Haxxor {
    class HXAPI OpenGLIndexBuffer : public IndexBuffer {
    public:
        OpenGLIndexBuffer(uint32_t count, uint32_t* data);
        virtual ~OpenGLIndexBuffer();
        void Enable();
        void Disable();
        inline uint32_t GetRendererID() const { return m_RendererID; };
        void SetData(uint32_t count, uint32_t* data);
    private:
        uint32_t m_RendererID;
    };
}