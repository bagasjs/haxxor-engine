#include "Renderer.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"

#include "Haxxor/Backend/OpenGL/OpenGLRenderer.h"

namespace Haxxor {
    Ref<Renderer> Renderer::Create(const Ref<Window>& window)
    {
        switch (RendererAPI::Get())
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLRenderer>(window);
        }
        HX_LOG_ERROR("%s", "Broken \"Renderer\" creation due to invalid renderer api kind.");
        return nullptr;
    }
}