#include "VertexBuffer.h"
#include "Renderer.h"
#include "Haxxor/Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Haxxor {
    Ref<VertexBuffer> VertexBuffer::Create(uint32_t count, float* data)
    {
        switch(Renderer::GetAPI())
        {
            case Renderer::API::NONE: return nullptr; // TODO: Error handling
            case Renderer::API::OPENGL: return MakeRef<OpenGLVertexBuffer>(count, data);
        }
        return nullptr;
    }
}