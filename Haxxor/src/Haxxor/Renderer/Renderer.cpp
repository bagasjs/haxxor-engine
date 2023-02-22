#include "Renderer.h"
#include "Haxxor/Platform/OpenGL/OpenGLRenderer.h"

namespace Haxxor {
    Renderer::API Renderer::s_API = Renderer::API::NONE;

    Ref<Renderer> Renderer::Create(const Ref<Window>& window)
    {
        switch (Renderer::GetAPI())
        {
            case Renderer::API::NONE: return nullptr; // TODO: error handling
            case Renderer::API::OPENGL: return MakeRef<OpenGLRenderer>(window);
        }
        return nullptr;
    }
}