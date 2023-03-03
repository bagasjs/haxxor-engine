#pragma once

#include "Haxxor/Core/Common.h"
#include "Haxxor/Renderer/Texture.h"

namespace Haxxor
{
    class HXAPI OpenGLTexture : public Texture
    {
    public:
        OpenGLTexture(bool loaded, uint32_t width, uint32_t height, const uint8_t* data);
        virtual ~OpenGLTexture();

        void Enable();
        void Disable();

        inline bool IsLoaded() const { return m_Loaded; };
        inline uint8_t* GetPixelsData() const { return m_PixelsData; };
        inline uint32_t GetWidth() const { return m_Width; };
        inline uint32_t GetHeight() const { return m_Height; };
    private:
        bool m_Loaded;
        uint32_t m_Width, m_Height;
        uint8_t* m_PixelsData;
    };
}