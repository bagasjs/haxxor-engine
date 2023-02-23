#include "VertexBuffer.h"
#include "RendererAPI.h"
#include "Haxxor/Backend/OpenGL/OpenGLVertexBuffer.h"

namespace Haxxor {
    Ref<VertexBuffer> VertexBuffer::Create(uint32_t count, float* data)
    {
        switch(RendererAPI::GetAPIKind())
        {
            case RendererAPI::Kind::NONE: return nullptr; // TODO: Error handling
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLVertexBuffer>(count, data);
        }
        return nullptr;
    }
}