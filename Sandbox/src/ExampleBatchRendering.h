#pragma once

#include <Haxxor.h>

class ExampleBatchRenderingLayer : public Haxxor::Layer
{
private:
    struct Vertex
    {
        float x, y, z;
        float r, g, b, a;
        Vertex(float px, float py, float pz, float pr, float pg, float pb, float pa)
            : x(px), y(py), z(pz), r(pr), g(pg), b(pb), a(pa) {}
    };

    struct Rectangle
    {
        float x, y, w, h;
    };
public:

    void OnEvent(const Haxxor::Event& ev) override;
    void OnAttach() override;
    void OnUpdate() override;
    
    void DrawRectangle(const Rectangle& rect, float r, float g, float b, float a);
    void Clear();

private:
    Rectangle m_Player;
    float m_PlayerSpeed = 10.0f;
private:
    Haxxor::Ref<Haxxor::VertexArray> m_VAO;
    Haxxor::Ref<Haxxor::VertexBuffer> m_VBO;
    Haxxor::Ref<Haxxor::IndexBuffer> m_IBO;
    Haxxor::Ref<Haxxor::Shader> m_Shader;
    Haxxor::Ref<Haxxor::OrthographicCamera> m_Camera;

    std::vector<uint32_t> m_Indices;
    std::vector<Vertex> m_Vertices;
    uint32_t m_MaximumIndices = 10000;
    uint32_t m_MaximumVertices = 10000;
};