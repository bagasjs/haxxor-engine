#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Haxxor {
    OpenGLVertexArray::OpenGLVertexArray()
        : m_RendererID(0)
    {
        glGenVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Enable() 
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Disable()
    {
        glBindVertexArray(0);
    }
}