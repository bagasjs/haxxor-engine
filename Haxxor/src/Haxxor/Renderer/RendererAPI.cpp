#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"

#include "Haxxor/Backend/OpenGL/OpenGLRendererAPI.h"

namespace Haxxor
{
    Ref<RendererAPI> RendererAPI::s_Instance = nullptr;
    RendererAPI::Kind RendererAPI::s_APIKind = RendererAPI::Kind::NONE;

    Ref<RendererAPI> RendererAPI::Create()
    {
        switch(RendererAPI::Get())
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLRendererAPI>();
        }
        HX_LOG_ERROR("%s", "Broken \"RendererAPI\" creation due to invalid renderer api kind.");
        return nullptr;
    }

    void RendererAPI::Init(Ref<Window> window)
    {
        if(s_Instance == nullptr)
            s_Instance = Create();
        s_Instance->Impl_Init(window);
    }

    void RendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        s_Instance->Impl_SetViewport(x, y, width, height);
    }

    void RendererAPI::SetClearColor(float r, float g, float b, float a)
    {
        s_Instance->Impl_SetClearColor(r, g, b, a);
    }

    void RendererAPI::Clear()
    {
        s_Instance->Impl_Clear();
    }

    void RendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0)
    {
        s_Instance->Impl_DrawIndexed(vertexArray, indexCount);
    }

    void RendererAPI::DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
    {
        s_Instance->Impl_DrawLines(vertexArray, vertexCount);
    }

    void RendererAPI::SetLineWidth(float width)
    {
        s_Instance->Impl_SetLineWidth(width);
    }

    void RendererAPI::LogError()
    {
        s_Instance->Impl_LogError();
    }
}