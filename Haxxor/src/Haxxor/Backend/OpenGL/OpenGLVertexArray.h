#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor {
    class HXAPI OpenGLVertexArray : public VertexArray 
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();
        
        void Enable();
        void Disable();
        inline uint32_t GetRendererID() const { return m_RendererID; }

        void AddVertexBuffer(const Ref<VertexBuffer>& vbo);
        void SetIndexBuffer(const Ref<IndexBuffer>& ibo);

        inline const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
        inline const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; };
    private:
        uint32_t m_RendererID;
        uint32_t m_VertexBufferIndex;
        std::vector<Ref<VertexBuffer>> m_VertexBuffers;
        Ref<IndexBuffer> m_IndexBuffer;
    };
}