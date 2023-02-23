#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/Shader.h"

namespace Haxxor {
    class HXAPI OpenGLShader : public Shader 
    {
    public:
        OpenGLShader(const std::string& vertSource, const std::string& fragSource);
        virtual ~OpenGLShader();

        void Enable();
        void Disable();
        inline uint32_t GetRendererID() const { return m_RendererID; }
        void SetUniform(Shader::DataType type, const std::string& name, const void* data);

        int GetUniformLocation(const std::string& name);
    private:
        uint32_t m_RendererID;
        std::unordered_map<std::string, int> m_UniformLocationCache;
    };
}