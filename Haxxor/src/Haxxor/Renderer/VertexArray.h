#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/VertexBuffer.h"
#include "Haxxor/Renderer/IndexBuffer.h"

namespace Haxxor {
    class HXAPI VertexArray {
    public:
        virtual ~VertexArray() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() const = 0;
        virtual void AddVertexBuffer(const Ref<VertexBuffer>& vbo) = 0;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& ibo) = 0;
        virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const = 0;
        virtual const Ref<IndexBuffer>& GetIndexBuffer() const = 0;

    public:
        static Ref<VertexArray> Create();
    };
}