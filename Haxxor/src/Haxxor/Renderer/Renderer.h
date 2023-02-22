#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Window.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor {
    class HXAPI Renderer {
    public:
        enum class API {
            NONE = 0,
            OPENGL = 1,  
        };
    public:
        virtual ~Renderer() {}

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(float r, float g, float b, float a) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) = 0;
		virtual void DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount) = 0;
		virtual void SetLineWidth(float width) = 0;

    public:
        inline static void SetAPI(API api = API::OPENGL) { s_API = api; }
        inline static API GetAPI() { return s_API; }
        static Ref<Renderer> Create(const Ref<Window>& window);

    private:
        static API s_API;
    };
}