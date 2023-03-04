#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/Texture.h"

#include <glad/glad.h>

namespace Haxxor
{
    class HXAPI OpenGLTexture2D : public Texture2D
    {
    public:
        OpenGLTexture2D(const std::string& filepath);
        OpenGLTexture2D(uint32_t width, uint32_t height, const uint8_t* data);
        virtual ~OpenGLTexture2D();

        void Enable(unsigned int slot);

        inline bool IsLoaded() const { return m_Loaded; };
        inline uint32_t GetWidth() const { return m_Width; };
        inline uint32_t GetHeight() const { return m_Height; };
        inline uint32_t GetRendererID() const { return m_RendererID; }
        void SetData(const void* data, uint32_t size);

    private:
        bool m_Loaded;
        uint32_t m_RendererID;
        uint32_t m_Width, m_Height;
        GLenum m_InternalFormat = 0;
        GLenum m_DataFormat = 0;
    };
}