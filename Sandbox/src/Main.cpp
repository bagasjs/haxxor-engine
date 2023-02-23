#include <Haxxor.h>
#include <vector>

using namespace Haxxor;

class MyGame : public Application {
public:
    virtual ~MyGame() {}

    void Init() override
    {
        m_WindowName = "My Window";
        RendererAPI::Set(RendererAPI::Kind::OPENGL);
    }

    void Setup(Ref<Renderer> renderer) override 
    {
        m_VAO = VertexArray::Create();
        m_VAO->Enable();

        std::string vertsrc = LoadFileContent("res/shaders/basic.vert");
        std::string fragsrc = LoadFileContent("res/shaders/basic.frag");
        m_Shader = Shader::Create(vertsrc, fragsrc);

        float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
             0.5f,  0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.2f, 0.3f, 1.0f, 1.0f,
        };
        
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

    void Update(Ref<Renderer> renderer) override
    {
        RendererAPI::Clear();
        m_Shader->Enable();
        m_IBO->Enable();
        m_VAO->Enable();
        RendererAPI::DrawIndexed(m_VAO, m_IBO->GetCount());
    }

    void Clean() override 
    {

    }
private:
    Ref<VertexArray> m_VAO;
    Ref<VertexBuffer> m_VBO;
    Ref<IndexBuffer> m_IBO;
    Ref<Shader> m_Shader;
};

int main(int argc, char** argv) {
    Ref<Application> app = MakeRef<MyGame>();
    app->Run();
}