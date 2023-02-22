#include "IndexBuffer.h"
#include "Renderer.h"

#include "Haxxor/Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Haxxor {
    Ref<IndexBuffer> IndexBuffer::Create(uint32_t count, uint32_t* data) {
        switch(Renderer::GetAPI()) {
            case Renderer::API::NONE: return nullptr; // TODO: Error handling
            case Renderer::API::OPENGL: return MakeRef<OpenGLIndexBuffer>(count, data);
        }
        return nullptr;
    }
}