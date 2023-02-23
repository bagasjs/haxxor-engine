#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace Haxxor {
    OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t count, float* data)
        : m_RendererID(0)
    {
        glGenBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_DYNAMIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() 
    {
        glDeleteBuffers(1, &m_RendererID);
    }

    void OpenGLVertexBuffer::Enable() 
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }

    void OpenGLVertexBuffer::Disable() 
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::SetData(uint32_t count, float* data) 
    {
        Enable();
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * count, data);
    }
}