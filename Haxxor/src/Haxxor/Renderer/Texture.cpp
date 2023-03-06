#include "Texture.h"
#include "RendererAPI.h"

#include "Haxxor/Core/Logging.h"
#include "Haxxor/Backend/OpenGL/OpenGLTexture2D.h"

namespace Haxxor
{
    Ref<Texture2D> Texture2D::Create(const std::string& filepath)
    {
        switch(RendererAPI::Get())
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLTexture2D>(filepath);
        }
        HX_LOG_ERROR("%s", "Broken \"Texture2D\" creation due to invalid renderer api kind.");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height, const uint8_t* data)
    {
        switch(RendererAPI::Get())
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLTexture2D>(width, height, data);
        }
        HX_LOG_ERROR("%s", "Broken \"Texture2D\" creation due to invalid renderer api kind.");
        return nullptr;
    }
}