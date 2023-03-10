#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor {
    class HXAPI IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() const = 0;
        virtual void SetData(uint32_t count, uint32_t* data) = 0;
        virtual uint32_t GetCount() const = 0;

    public:
        static Ref<IndexBuffer> Create(uint32_t count, uint32_t* data);
    };
}