#include <Haxxor.h>

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

        float vertices[] = {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f
        };
        
        m_VBO = VertexBuffer::Create(sizeof(vertices), vertices);
        m_VBO->Enable();

        uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };
        m_IBO = IndexBuffer::Create(sizeof(indices), indices);
        m_IBO->Enable();
    }

    void Update(Ref<Renderer> renderer) override
    {
        RendererAPI::Clear();
    }

    void Clean() override 
    {

    }
private:
    Ref<VertexArray> m_VAO;
    Ref<VertexBuffer> m_VBO;
    Ref<IndexBuffer> m_IBO;
};

int main(int argc, char** argv) {
    Ref<Application> app = MakeRef<MyGame>();
    app->Run();
}