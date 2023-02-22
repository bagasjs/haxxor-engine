#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/Shader.h"

namespace Haxxor {
    class HXAPI OpenGLShader : public Shader {
    public:
        OpenGLShader();
        virtual ~OpenGLShader();

        void Enable();
        void Disable();
        inline uint32_t GetRendererID() const { return m_RendererID; }
        void SetUniform(ShaderDataType type, const std::string& name, const void* data);

    private:
        uint32_t m_RendererID;
    };
}