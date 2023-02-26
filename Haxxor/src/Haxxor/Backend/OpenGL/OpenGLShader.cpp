#include "OpenGLShader.h"
#include "Haxxor/Core/Logging.h"
#include "Haxxor/Renderer/RendererAPI.h"

#include <glad/glad.h>

namespace Haxxor {
    OpenGLShader::OpenGLShader(const std::string& vertSource, const std::string& fragSource)
        : m_RendererID(0)
    {
        uint32_t vertShader = glCreateShader(GL_VERTEX_SHADER);
        const char* vs = vertSource.c_str();
        glShaderSource(vertShader, 1, &vs, NULL);
        glCompileShader(vertShader);

        uint32_t fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fs = fragSource.c_str();
        glShaderSource(fragShader, 1, &fs, NULL);
        glCompileShader(fragShader);

        m_RendererID = glCreateProgram();
        glAttachShader(m_RendererID, vertShader);
        glAttachShader(m_RendererID, fragShader);
        glLinkProgram(m_RendererID);
        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
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

    int OpenGLShader::GetUniformLocation(const std::string& name)
    {
        int location = 0;
        if(m_UniformLocationCache.find(name) == m_UniformLocationCache.end())
        {
            location = glGetUniformLocation(m_RendererID, name.c_str());
            if(location < 0) 
                HX_LOG_ERROR("%s \"%s\"", "Invalid location for uniform with name", name.c_str());
            m_UniformLocationCache[name] = location;
        }
        else
        {
            location = m_UniformLocationCache[name];
        }
        return location;
    }

    void OpenGLShader::SetUniform(Shader::DataType type, const std::string& name, const void* data)
    {
        int location = GetUniformLocation(name);
        Enable();
        switch(type)
        {
            case Shader::DataType::FLOAT : glUniform1fv(location, 1, (float*)data); break;
            case Shader::DataType::FLOAT2: glUniform2fv(location, 1, (float*)data); break;
            case Shader::DataType::FLOAT3: glUniform3fv(location, 1, (float*)data); break;
            case Shader::DataType::FLOAT4: glUniform4fv(location, 1, (float*)data); break;
            case Shader::DataType::INT: glUniform1iv(location, 1, (int*)data); break;
            case Shader::DataType::INT2: glUniform2iv(location, 1, (int*)data); break;
            case Shader::DataType::INT3: glUniform3iv(location, 1, (int*)data); break;
            case Shader::DataType::INT4: glUniform4iv(location, 1, (int*)data); break;
            case Shader::DataType::MAT3: glUniformMatrix3fv(location, 1, false, (float*)data); break;
            case Shader::DataType::MAT4: glUniformMatrix4fv(location, 1, false, (float*)data); break;
        }
    }
}