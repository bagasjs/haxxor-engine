#include "IndexBuffer.h"
#include "RendererAPI.h"

#include "Haxxor/Backend/OpenGL/OpenGLIndexBuffer.h"

namespace Haxxor {
    Ref<IndexBuffer> IndexBuffer::Create(uint32_t count, uint32_t* data) {
        switch(RendererAPI::GetAPIKind()) {
            case RendererAPI::Kind::NONE: return nullptr; // TODO: Error handling
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLIndexBuffer>(count, data);
        }
        return nullptr; // TODO: error handling
    }
}