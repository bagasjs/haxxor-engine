workspace "Haxxor Engine"
    configurations { "Debug", "Release" }
    architecture "x86_64"

include "Haxxor/vendors/glad"
include "Haxxor/vendors/glfw"
include "Haxxor"
include "Sandbox"