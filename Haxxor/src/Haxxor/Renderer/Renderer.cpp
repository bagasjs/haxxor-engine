#include "Renderer.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"

namespace Haxxor {
    Ref<Window> Renderer::s_Window = nullptr;

    void Renderer::Init(const Ref<Window>& window)
    {
        RendererAPI::Init(window);
        s_Window = window;
    }

    void Renderer::OnWindowResize(uint32_t width, uint32_t height)
    {
        RendererAPI::SetViewport(0, 0, width, height);
    }
}