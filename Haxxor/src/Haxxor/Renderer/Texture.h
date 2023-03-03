#pragma once

#include "Haxxor/Core/Common.h"

namespace Haxxor
{
    class HXAPI Texture
    {
    public:
        virtual ~Texture() = default;

        virtual void Enable() = 0;
        virtual void Disable() = 0;

        virtual bool IsLoaded() const = 0;
        virtual uint8_t* GetPixelsData() const = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

    public:
        static Ref<Texture> Create(const std::string& filepath);
        static Ref<Texture> Create(uint32_t width, uint32_t height, const uint8_t* data);
    };
}