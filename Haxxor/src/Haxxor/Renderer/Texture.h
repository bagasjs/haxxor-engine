#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor
{
    class HXAPI Texture
    {
    public:
        virtual ~Texture() = default;

        virtual void Enable(unsigned int slot) = 0;

        virtual bool IsLoaded() const = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual uint32_t GetRendererID() const = 0;

        virtual void SetData(const void* data, uint32_t size) = 0;
    };

    class HXAPI Texture2D : public Texture 
    {
    public:
        static Ref<Texture2D> Create(const std::string& filepath);
        static Ref<Texture2D> Create(uint32_t width, uint32_t height, const uint8_t* data);
    };
}