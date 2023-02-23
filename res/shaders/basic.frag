#version 430 core

layout(location = 0) out vec4 outputColor;
in vec4 v_Color;

void main()
{
    outputColor = v_Color;
}