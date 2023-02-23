#include "IndexBuffer.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"
#include "Haxxor/Backend/OpenGL/OpenGLIndexBuffer.h"

namespace Haxxor {
    Ref<IndexBuffer> IndexBuffer::Create(uint32_t count, uint32_t* data) {
        switch(RendererAPI::Get()) {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLIndexBuffer>(count, data);
        }
        HX_LOG_ERROR("%s", "Broken \"IndexBuffer\" creation due to invalid renderer api kind.");
        return nullptr;
    }
}