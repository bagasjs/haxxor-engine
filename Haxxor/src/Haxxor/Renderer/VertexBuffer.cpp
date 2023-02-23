#include "VertexBuffer.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"
#include "Haxxor/Backend/OpenGL/OpenGLVertexBuffer.h"

namespace Haxxor {
    Ref<VertexBuffer> VertexBuffer::Create(uint32_t count, float* data)
    {
        switch(RendererAPI::Get())
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLVertexBuffer>(count, data);
        }
        HX_LOG_ERROR("%s", "Broken \"VertexBuffer\" creation due to invalid renderer api kind.");
        return nullptr;
    }
}