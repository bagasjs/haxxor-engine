#include "Renderer.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"

namespace Haxxor {
    Ref<Window> Renderer::s_Window = nullptr;
    glm::vec2 Renderer::s_Viewport = glm::vec2(0.0f);

    void Renderer::Init(const Ref<Window>& window)
    {
        RendererAPI::Init(window);
        s_Window = window;
        s_Viewport = glm::vec2(window->GetWidth(), window->GetHeight());
    }

    void Renderer::OnWindowResize()
    {
        s_Viewport = glm::vec2(s_Window->GetWidth(), s_Window->GetHeight());
        RendererAPI::SetViewport(0, 0, s_Window->GetWidth(), s_Window->GetHeight());
    }
}