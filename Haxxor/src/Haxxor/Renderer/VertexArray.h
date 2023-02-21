#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor {
    class HXAPI VertexArray {
    public:
        virtual ~VertexArray() {}

        virtual void Enable() = 0;
        virtual void Disable() = 0;
        virtual uint32_t GetRendererID() = 0;

    public:
        static Ref<VertexArray> Create();
    };
}