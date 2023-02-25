#include "OpenGLRendererAPI.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Haxxor/Core/Logging.h"

namespace Haxxor
{
    void OpenGLRendererAPI::Impl_Init(Ref<Window> window)
    {
        GLFWwindow* glfwhandle = (GLFWwindow*) window->GetNativeHandle();
        glfwMakeContextCurrent(glfwhandle);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);        
    }

    void OpenGLRendererAPI::Impl_SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRendererAPI::Impl_SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLRendererAPI::Impl_Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::Impl_DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
    {
        vertexArray->Enable();
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRendererAPI::Impl_DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
    {
        vertexArray->Enable();
        glDrawArrays(GL_LINES, 0, vertexCount);
    }

    void OpenGLRendererAPI::Impl_SetLineWidth(float width)
    {
        glLineWidth(width);
    }

    void OpenGLRendererAPI::Impl_LogError()
    {
        int check = 1;
        while (check)
        {
            const GLenum err = glGetError();
            switch (err)
            {
                case GL_NO_ERROR: check = 0; break;
                case 0x0500: HX_LOG_WARN("%s", "OpenGL Error detected: GL_INVALID_ENUM"); break;
                case 0x0501: HX_LOG_WARN("%s", "OpenGL Error detected: GL_INVALID_VALUE"); break;
                case 0x0502: HX_LOG_WARN("%s", "OpenGL Error detected: GL_INVALID_OPERATION"); break;
                case 0x0503: HX_LOG_WARN("%s", "OpenGL Error detected: GL_STACK_OVERFLOW"); break;
                case 0x0504: HX_LOG_WARN("%s", "OpenGL Error detected: GL_STACK_UNDERFLOW"); break;
                case 0x0505: HX_LOG_WARN("%s", "OpenGL Error detected: GL_OUT_OF_MEMORY"); break;
                case 0x0506: HX_LOG_WARN("%s", "OpenGL Error detected: GL_INVALID_FRAMEBUFFER_OPERATION"); break;
                default: HX_LOG_WARN("%s:%i", "OpenGL Error detected: Unknown error code:", err); break;
            }
        }        
    }
}