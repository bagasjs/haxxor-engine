#include "OpenGLRenderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Haxxor {
    OpenGLRenderer::OpenGLRenderer(const Ref<Window>& window)
    {
        GLFWwindow* glfwhandle = (GLFWwindow*) window->GetNativeHandle();
        glfwMakeContextCurrent(glfwhandle);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    void OpenGLRenderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRenderer::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLRenderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRenderer::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
    {
        vertexArray->Enable();
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRenderer::DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
    {
        vertexArray->Enable();
        glDrawArrays(GL_LINES, 0, vertexCount);
    }

    void OpenGLRenderer::SetLineWidth(float width)
    {
        glLineWidth(width);
    }
}