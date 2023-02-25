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
        static void LogError();

        inline static Kind Get() { return s_APIKind; }
        inline static void Set(Kind api) { s_APIKind = api; }

    protected:
		virtual void ImplSetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void ImplSetClearColor(float r, float g, float b, float a) = 0;
		virtual void ImplClear() = 0;
		virtual void ImplDrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount) = 0;
		virtual void ImplDrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount) = 0;
		virtual void ImplSetLineWidth(float width) = 0;
        virtual void ImplLogError() = 0;

    private:
        static Kind s_APIKind;
        static Ref<RendererAPI> Create();
        static Ref<RendererAPI> s_Instance;
    };
}