#include "OpenGLShader.h"

#include <glad/glad.h>

namespace Haxxor {
    OpenGLShader::OpenGLShader()
        : m_RendererID(0)
    {

    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_RendererID);
    }

    void OpenGLShader::Enable()
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShader::Disable()
    {
        glUseProgram(0);
    }

    void OpenGLShader::SetUniform(ShaderDataType type, const std::string& name, const void* data)
    {

    }
}