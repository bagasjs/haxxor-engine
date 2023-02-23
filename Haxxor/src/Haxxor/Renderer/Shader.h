#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor {
    class HXAPI Shader {
    public:
        enum class DataType
        {
            NONE = 0, FLOAT, FLOAT2, FLOAT3, FLOAT4, MAT3, MAT4, INT, INT2, INT3, INT4, BOOL
        };
        static uint32_t DataTypeSize(DataType type);
        static uint32_t DataTypeComponentCount(DataType type);

    public:
        virtual ~Shader() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() const = 0;
        virtual void SetUniform(DataType type, const std::string& name, const void* data) = 0;
        
    public:
        static Ref<Shader> Create(const std::string& vertSource, const std::string& fragSource);
    };

    std::string LoadFileContent(const std::string& filename);
}