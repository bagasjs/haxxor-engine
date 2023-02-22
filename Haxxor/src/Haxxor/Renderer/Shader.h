#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor {

    enum class ShaderDataType {
        NONE = 0, FLOAT, FLOAT2, FLOAT3, FLOAT4, MAT3, MAT4, INT, INT2, INT3, INT4, BOOL
    };

    class HXAPI Shader {
    public:
        virtual ~Shader() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() const = 0;
        virtual void SetUniform(ShaderDataType type, const std::string& name, const void* data) = 0;
        
    public:
        static Ref<Shader> Create(const std::string& vertSource, const std::string& fragSource);
    };
}