#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/VertexArray.h"

namespace Haxxor {


    class HXAPI RendererAPI
    {
    public:
        enum class Kind {
            NONE = 0,
            OPENGL
        };
    public:
        virtual ~RendererAPI() = default;

    public:
        static void Init();
        static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		static void SetClearColor(float r, float g, float b, float a);
		static void Clear();
		static void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount);
		static void DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount);
		static void SetLineWidth(float width);

        inline static Kind GetAPIKind() { return s_APIKind; }
        inline static void Set(Kind api) { s_APIKind = api; }

    protected:
		virtual void Impl_SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void Impl_SetClearColor(float r, float g, float b, float a) = 0;
		virtual void Impl_Clear() = 0;
		virtual void Impl_DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount) = 0;
		virtual void Impl_DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount) = 0;
		virtual void Impl_SetLineWidth(float width) = 0;

    private:
        static Kind s_APIKind;
        static Ref<RendererAPI> Create();
        static Ref<RendererAPI> s_Instance;
    };
}