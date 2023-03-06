#pragma once

#include <Haxxor.h>

class ExampleTextureRenderingLayer : public Haxxor::Layer
{
public:
    void OnAttach() override;
    void OnUpdate() override;
    
private:
    Haxxor::Ref<Haxxor::VertexArray> m_VAO;
    Haxxor::Ref<Haxxor::VertexBuffer> m_VBO;
    Haxxor::Ref<Haxxor::IndexBuffer> m_IBO;
    Haxxor::Ref<Haxxor::Texture2D> m_Tex;
    Haxxor::Ref<Haxxor::Shader> m_Shader;
};