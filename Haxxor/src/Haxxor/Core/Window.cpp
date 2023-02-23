#include "Window.h"

#if defined(HX_PLATFORM_WINDOWS)
    #include "Haxxor/Backend/Windows/WindowsWindow.h"
#elif defined(HX_PLATFORM_LINUX)
    #include "Haxxor/Backend/Linux/LinuxWindow.h"
#else
    #error "Unsupported platform"
#endif

namespace Haxxor {
    Ref<Window> Window::Create(const std::string& name, uint32_t width, uint32_t height) {
    #if defined(HX_PLATFORM_LINUX)
        Ref<Window> window = MakeRef<LinuxWindow>(name, width, height);
        return window;
    #elif defined(HX_PLATFORM_WINDOWS)
        return nullptr;
    #else
        return nullptr;
    #endif
    }    
}