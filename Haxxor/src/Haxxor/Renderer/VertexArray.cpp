#include "VertexArray.h"
#include "Renderer.h"
#include "Haxxor/Platform/OpenGL/OpenGLVertexArray.h"

namespace Haxxor {
    Ref<VertexArray> VertexArray::Create() {
        switch(Renderer::GetAPI()) {
            case Renderer::API::NONE: return nullptr;
            case Renderer::API::OPENGL: return MakeRef<OpenGLVertexArray>();
        }
        return nullptr;
    }
}