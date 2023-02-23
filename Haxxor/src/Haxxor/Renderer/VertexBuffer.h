#pragma once

#include "Haxxor/Core/Common.h"

#include "Haxxor/Renderer/Shader.h"

namespace Haxxor {
    struct BufferElement
    {
        std::string Name;
        Shader::DataType Type;
        uint32_t Size;
        size_t Offset;
        bool Normalized;
        BufferElement() = default;
        BufferElement(Shader::DataType type, const std::string& name, bool normalized = false)
            : Name(name), Type(type), Size(Shader::DataTypeSize(type)), Offset(0), Normalized(normalized)
        {
        }
    };

    class BufferLayout
    {
    public:
        BufferLayout() = default;
        BufferLayout(std::initializer_list<BufferElement> elements)
            : m_Elements(elements)
        {
            CalculateOffsetAndStride();
        }
        uint32_t GetStride() const { return m_Stride; }
        const std::vector<BufferElement>& GetElements() const { return m_Elements; }

    private:
        void CalculateOffsetAndStride()
        {
            size_t offset = 0;
            m_Stride = 0;
            for(auto& element : m_Elements)
            {
                element.Offset = offset;
                offset += element.Size;
                m_Stride += element.Size;
            }
        }

        std::vector<BufferElement> m_Elements;
        uint32_t m_Stride = 0;
    };

    class HXAPI VertexBuffer 
    {
    public:
        virtual ~VertexBuffer() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() const = 0;
        virtual void SetData(uint32_t count, float* data) = 0;
        
        virtual const BufferLayout& GetLayout() const = 0;
        virtual void SetLayout(const BufferLayout& layout) = 0;

    public:
        static Ref<VertexBuffer> Create(uint32_t count, float* data);
    };
}