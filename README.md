# Haxxor Engine
Status: On progress not ready for release yet

### How to build
- Make sure you have [premake5](https://premake.github.io/) installed
- Clone the repository with recursive switch ``` git clone --recursive https://github.com/thankz4lot/haxxor-engine.git ```
- Run ```premake5 <action>``` Look here for available [action](https://premake.github.io/docs/Using-Premake)

### FUTURE
- Audio
- Editor

### Issues / Bugs
- (fixed) Sometimes nothing is rendered.
    cause: when OpenGLVertexArray object is initialized m_VertexBufferIndex is not initialized into 0 or any default value that cause glEnableVertexAttribArray() takes unknown value.
- Resize event cannot determine the change when window is maximized
- (fixed) Camera matrix not working
    cause: MAT4 uniform not implemented in OpenGLShader class