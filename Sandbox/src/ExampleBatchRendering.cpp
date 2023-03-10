#include "ExampleBatchRendering.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

using namespace Haxxor;

void ExampleBatchRenderingLayer::OnEvent(const Event& ev)
{
    if(ev.Type == EventType::WINDOW_RESIZED)
    {
        Renderer::OnWindowResize();
        glm::vec2 viewport = Renderer::GetViewport();
        m_Camera->SetProjection(0.0f, viewport.x, viewport.y, 0.0f);
    }

    if(ev.Type == EventType::KEY_PRESSED || ev.Type == EventType::KEY_REPEATED)
    {
        switch(ev.Key)
        {
            case KeyCode::KEY_UP: m_Player.y -= m_PlayerSpeed; break;
            case KeyCode::KEY_DOWN: m_Player.y += m_PlayerSpeed; break;
            case KeyCode::KEY_LEFT: m_Player.x -= m_PlayerSpeed; break;
            case KeyCode::KEY_RIGHT: m_Player.x += m_PlayerSpeed; break;
        }
    }
}

void ExampleBatchRenderingLayer::OnAttach()
{
    // Renderer State
    m_VAO = VertexArray::Create();
    m_VAO->Enable();

    std::string vertsrc = LoadFileContent("res/shaders/basic.vert");
    std::string fragsrc = LoadFileContent("res/shaders/basic.frag");
    m_Shader = Shader::Create(vertsrc, fragsrc);
    m_Camera = MakeRef<OrthographicCamera>(0.0f, 640.0f, 480.0f, 0.0f);

    m_VBO = VertexBuffer::Create(m_MaximumVertices * sizeof(Vertex), nullptr);
    m_VBO->Enable();

    BufferLayout layout({
        { Shader::DataType::FLOAT3, "a_Position" },
        { Shader::DataType::FLOAT4, "a_Color" },
    });

    m_VBO->SetLayout(layout);
    m_VAO->AddVertexBuffer(m_VBO);

    m_IBO = IndexBuffer::Create(m_MaximumIndices * sizeof(uint32_t), nullptr);
    m_VAO->SetIndexBuffer(m_IBO);

    // Game State
    m_Player.x = 10.0f;
    m_Player.y = 10.0f;
    m_Player.w = 100.0f;
    m_Player.h = 100.0f;
}

void ExampleBatchRenderingLayer::OnUpdate()
{
    RendererAPI::Clear();
    Clear();


    // Draw Rectangle here
    DrawRectangle(m_Player, 0.2f, 0.3f, 1.0f, 1.0f);
    // End

    m_VBO->SetData(m_Vertices.size() * sizeof(Vertex) / sizeof(float), (float*) m_Vertices.data());
    m_IBO->SetData(m_Indices.size(), (uint32_t*) m_Indices.data());

    m_Shader->SetUniform(Shader::DataType::MAT4, "u_Camera", glm::value_ptr(m_Camera->GetViewProjectionMatrix()));

    m_Shader->Enable();
    m_IBO->Enable();
    m_VAO->Enable();
    RendererAPI::DrawIndexed(m_VAO, m_IBO->GetCount());
}

void ExampleBatchRenderingLayer::DrawRectangle(const Rectangle& rect, float r, float g, float b, float a)
{
    m_Indices.push_back(m_Vertices.size() + 0);
    m_Indices.push_back(m_Vertices.size() + 1);
    m_Indices.push_back(m_Vertices.size() + 2);
    m_Indices.push_back(m_Vertices.size() + 2);
    m_Indices.push_back(m_Vertices.size() + 3);
    m_Indices.push_back(m_Vertices.size() + 0);

    m_Vertices.emplace_back(rect.x, rect.y, 0.0f, r, g, b, a);
    m_Vertices.emplace_back(rect.x + rect.w, rect.y, 0.0f, r, g, b, a);
    m_Vertices.emplace_back(rect.x + rect.w, rect.y + rect.h, 0.0f, r, g, b, a);
    m_Vertices.emplace_back(rect.x, rect.y + rect.h, 0.0f, r, g, b, a);
}

void ExampleBatchRenderingLayer::Clear()
{
    m_Indices.clear();
    m_Vertices.clear();
}