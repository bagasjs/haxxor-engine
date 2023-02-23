#include "Renderer.h"
#include "RendererAPI.h"
#include "Haxxor/Backend/OpenGL/OpenGLRenderer.h"

namespace Haxxor {
    Ref<Renderer> Renderer::Create(const Ref<Window>& window)
    {
        switch (RendererAPI::GetAPIKind())
        {
            case RendererAPI::Kind::NONE: return nullptr; // TODO: error handling
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLRenderer>(window);
        }
        return nullptr;
    }
}