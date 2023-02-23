#include "VertexArray.h"
#include "RendererAPI.h"
#include "Haxxor/Backend/OpenGL/OpenGLVertexArray.h"

namespace Haxxor {
    Ref<VertexArray> VertexArray::Create() 
    {
        switch(RendererAPI::GetAPIKind()) 
        {
            case RendererAPI::Kind::NONE: return nullptr;
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLVertexArray>();
        }
        return nullptr;
    }
}