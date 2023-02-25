#include <Haxxor.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

using namespace Haxxor;

class GameLayer : public Layer
{
public:
    void OnAttach() override
    {
        m_VAO = VertexArray::Create();
        m_VAO->Enable();

        std::string vertsrc = LoadFileContent("res/shaders/basic.vert");
        std::string fragsrc = LoadFileContent("res/shaders/basic.frag");
        m_Shader = Shader::Create(vertsrc, fragsrc);
        Ref<Camera> cam = Camera::Ortho(0.0f, 640.0f, 480.0f, 0.0f);
        glm::mat4 mvp = cam->GetViewProjectionMatrix();
        // m_Shader->SetUniform(Shader::DataType::MAT4, "u_Camera", glm::value_ptr(cam->GetViewProjectionMatrix()));

        std::cout << glm::to_string(mvp) << std::endl;

        float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
             0.5f,  0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
        };

        // float vertices[] = {
        //     100.5f, 100.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
        //     200.5f, 100.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
        //     200.5f, 200.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
        //     100.5f, 200.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
        // };

        m_VBO = VertexBuffer::Create(sizeof(vertices) / sizeof(float), vertices);
        m_VBO->Enable();

        BufferLayout layout({
            { Shader::DataType::FLOAT3, "a_Position" },
            { Shader::DataType::FLOAT4, "a_Color" },
        });
        m_VBO->SetLayout(layout);
        m_VAO->AddVertexBuffer(m_VBO);

        uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };
        m_IBO = IndexBuffer::Create(sizeof(indices) / sizeof(uint32_t), indices);
        m_VAO->SetIndexBuffer(m_IBO);
    }

    void OnUpdate() override
    {
        RendererAPI::Clear();
        m_Shader->Enable();
        m_IBO->Enable();
        m_VAO->Enable();
        RendererAPI::DrawIndexed(m_VAO, m_IBO->GetCount());
        RendererAPI::LogError();
    }

private:
    Ref<VertexArray> m_VAO;
    Ref<VertexBuffer> m_VBO;
    Ref<IndexBuffer> m_IBO;
    Ref<Shader> m_Shader;
};

int main(int argc, char** argv) {
    Application app;
    app.AddLayer<GameLayer>();
    app.Run();
}