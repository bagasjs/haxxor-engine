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

    void RendererAPI::Init()
    {
        if(s_Instance == nullptr)
            s_Instance = Create();
        // TODO: Error handling
        // TODO: Consider if user can use multi renderer api
    }

    void RendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        s_Instance->ImplSetViewport(x, y, width, height);
    }

    void RendererAPI::SetClearColor(float r, float g, float b, float a)
    {
        s_Instance->ImplSetClearColor(r, g, b, a);
    }

    void RendererAPI::Clear()
    {
        s_Instance->ImplClear();
    }

    void RendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0)
    {
        s_Instance->ImplDrawIndexed(vertexArray, indexCount);
    }

    void RendererAPI::DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
    {
        s_Instance->ImplDrawLines(vertexArray, vertexCount);
    }

    void RendererAPI::SetLineWidth(float width)
    {
        s_Instance->ImplSetLineWidth(width);
    }

    void RendererAPI::LogError()
    {
        s_Instance->ImplLogError();
    }
}