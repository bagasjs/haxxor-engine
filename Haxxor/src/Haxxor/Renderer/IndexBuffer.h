#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor {
    class HXAPI IndexBuffer {
    public:
        virtual ~IndexBuffer() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() = 0;

    public:
        static Ref<IndexBuffer> Create();
    };
}