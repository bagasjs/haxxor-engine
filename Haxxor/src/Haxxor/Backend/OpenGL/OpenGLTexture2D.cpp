#include "OpenGLTexture2D.h"
#include "Haxxor/Core/Logging.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Haxxor
{
    OpenGLTexture2D::OpenGLTexture2D(uint32_t width, uint32_t height, const uint8_t* data)
        : m_Width(width), m_Height(height)
    {
        m_InternalFormat = GL_RGBA8;
        m_DataFormat = GL_RGBA;

        glGenTextures(1, &m_RendererID);
        glTexStorage2D(m_RendererID, 1, m_InternalFormat, m_Width, m_Height);
        glTexParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    OpenGLTexture2D::OpenGLTexture2D(const std::string& filepath)
    {
        int width, height, channels;
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* data = nullptr;
        data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
        if(!data) HX_ASSERT(false, "Failed to load image data");

        m_Loaded = true;
        m_Width = width;
        m_Height = height;
        if(channels == 4)
        {
            m_InternalFormat = GL_RGBA8;
            m_DataFormat = GL_RGBA;
        }
        else if(channels == 3)
        {
            m_InternalFormat = GL_RGBA8;
            m_DataFormat = GL_RGB;
        }

        HX_ASSERT(m_InternalFormat && m_DataFormat, "Invalid image format");

        glGenTextures(1, &m_RendererID);
        glTexStorage2D(m_RendererID, 1, m_InternalFormat, m_Width, m_Height);
        glTexParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::SetData(const void* data, uint32_t size)
    {
        uint32_t bpp = m_DataFormat == GL_RGBA ? 4 : 3;
        HX_ASSERT(size == m_Width * m_Height * bpp, "Invalid data size");
        glTexSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);
    }

    void OpenGLTexture2D::Enable(unsigned int slot)
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }
}