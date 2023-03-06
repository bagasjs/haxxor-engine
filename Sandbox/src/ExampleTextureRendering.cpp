#include "ExampleTextureRendering.h"

using namespace Haxxor;

void ExampleTextureRenderingLayer::OnAttach()
{
    std::string vertsrc = LoadFileContent("res/shaders/texture-example.vert");
    std::string fragsrc = LoadFileContent("res/shaders/texture-example.frag");

    m_Shader = Shader::Create(vertsrc, fragsrc);

    m_Tex = Texture2D::Create("res/haxxor-bunny.png");

    m_VAO = VertexArray::Create();
    m_VAO->Enable();

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, 1.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f
    };
    
    m_VBO = VertexBuffer::Create(sizeof(vertices) / sizeof(float), vertices);
    m_VBO->Enable();

    BufferLayout layout({
        { Shader::DataType::FLOAT2, "a_Position" },
        { Shader::DataType::FLOAT2, "a_TexCoords" },
        { Shader::DataType::FLOAT , "a_TexID" }
    });

    m_VBO->SetLayout(layout);
    m_VAO->AddVertexBuffer(m_VBO);

    uint32_t indices[] = {
        0, 1, 2, 2, 3, 0
    };

    m_IBO = IndexBuffer::Create(sizeof(indices) / sizeof(uint32_t), indices);
    m_VAO->SetIndexBuffer(m_IBO);
}

void ExampleTextureRenderingLayer::OnUpdate()
{
    RendererAPI::Clear();

    m_Shader->Enable();
    m_IBO->Enable();
    m_VAO->Enable();
    RendererAPI::DrawIndexed(m_VAO, m_IBO->GetCount());
}
