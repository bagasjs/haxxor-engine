#include <Haxxor.h>

using namespace Haxxor;

class MyGame : public Application {
public:
    virtual ~MyGame() {}

    void Setup() override {
        m_WindowName = "My Window";
    }

    void Update() override {
        
    }

    void Clean() override {

    }
};

int main(int argc, char** argv) {
    Ref<Application> app = MakeRef<MyGame>();
    app->Run();
}