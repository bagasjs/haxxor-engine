#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor {
    class HXAPI OpenGLVertexArray : public VertexArray {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();
        
        void Enable();
        void Disable();
        inline uint32_t GetRendererID() const { return m_RendererID; }
    private:
        uint32_t m_RendererID;
    };
}