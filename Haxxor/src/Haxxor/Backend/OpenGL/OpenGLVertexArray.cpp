#include "OpenGLVertexArray.h"

#include <glad/glad.h>
#include "Haxxor/Core/Logging.h"
#include "Haxxor/Renderer/Shader.h"

namespace Haxxor {

    static GLenum ShaderDataTypeToOpenGLBaseType(Shader::DataType type)
    {
        switch (type)
        {
            case Shader::DataType::FLOAT:    return GL_FLOAT;
            case Shader::DataType::FLOAT2:   return GL_FLOAT;
            case Shader::DataType::FLOAT3:   return GL_FLOAT;
            case Shader::DataType::FLOAT4:   return GL_FLOAT;
            case Shader::DataType::MAT3:     return GL_FLOAT;
            case Shader::DataType::MAT4:     return GL_FLOAT;
            case Shader::DataType::INT:      return GL_INT;
            case Shader::DataType::INT2:     return GL_INT;
            case Shader::DataType::INT3:     return GL_INT;
            case Shader::DataType::INT4:     return GL_INT;
            case Shader::DataType::BOOL:     return GL_BOOL;
        }
        HX_LOG_ERROR("%s", "Unknown shader data type!");
        return 0;        
    }

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

    void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vbo)
    {
        glBindVertexArray(m_RendererID);
        vbo->Enable();
        const auto& layout = vbo->GetLayout();

        for(const auto& element : layout.GetElements())
        {
            switch(element.Type)
            {
                case Shader::DataType::FLOAT:
                case Shader::DataType::FLOAT2:
                case Shader::DataType::FLOAT3:
                case Shader::DataType::FLOAT4:
                {
                    glEnableVertexAttribArray(m_VertexBufferIndex);
                    glVertexAttribPointer(m_VertexBufferIndex,
                        Shader::DataTypeComponentCount(element.Type),
                        ShaderDataTypeToOpenGLBaseType(element.Type),
                        element.Normalized ? GL_TRUE : GL_FALSE,
                        layout.GetStride(),
                        (const void*) element.Offset);
                    m_VertexBufferIndex++;
                    break;
                }

                case Shader::DataType::MAT3:  
                case Shader::DataType::MAT4:
                {
					uint8_t count = Shader::DataTypeComponentCount(element.Type);
					for (uint8_t i = 0; i < count; i++)
					{
						glEnableVertexAttribArray(m_VertexBufferIndex);
						glVertexAttribPointer(m_VertexBufferIndex,
							count,
							ShaderDataTypeToOpenGLBaseType(element.Type),
							element.Normalized ? GL_TRUE : GL_FALSE,
							layout.GetStride(),
							(const void*)(element.Offset + sizeof(float) * count * i));
						glVertexAttribDivisor(m_VertexBufferIndex, 1);
						m_VertexBufferIndex++;
					}
					break;
                }

                case Shader::DataType::INT: 
                case Shader::DataType::INT2:
                case Shader::DataType::INT3:
                case Shader::DataType::INT4:
                case Shader::DataType::BOOL:
                {
                    glEnableVertexAttribArray(m_VertexBufferIndex);
                    glVertexAttribIPointer(m_VertexBufferIndex,
                        Shader::DataTypeComponentCount(element.Type),                    
                        ShaderDataTypeToOpenGLBaseType(element.Type),
                        layout.GetStride(),
                        (const void*)element.Offset);
                    m_VertexBufferIndex++;
                    break;
                }
                
            }
        }

        m_VertexBuffers.push_back(vbo);
    }

    void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& ibo)
    {

    }
}