#include "VertexArray.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"
#include "Haxxor/Backend/OpenGL/OpenGLVertexArray.h"

namespace Haxxor {
    Ref<VertexArray> VertexArray::Create() 
    {
        switch(RendererAPI::Get()) 
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLVertexArray>();
        }
        HX_LOG_ERROR("%s", "Broken \"VertexArray\" creation due to invalid renderer api kind.");
        return nullptr;
    }
}