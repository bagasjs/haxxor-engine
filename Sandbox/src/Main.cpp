#include <Haxxor.h>

#include "ExampleBatchRendering.h"

int main(int argc, char** argv) {
    Haxxor::Application app;
    app.AddLayer<ExampleBatchRenderingLayer>();
    app.Run();
}