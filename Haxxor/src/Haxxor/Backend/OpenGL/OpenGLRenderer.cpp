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
}