#include "Shader.h"
#include "RendererAPI.h"
#include "Haxxor/Core/Logging.h"

#include "Haxxor/Backend/OpenGL/OpenGLShader.h"
#include <fstream>

namespace Haxxor 
{
    Ref<Shader> Shader::Create(const std::string& vertSource, const std::string& fragSource)
    {
        switch(RendererAPI::Get())
        {
            case RendererAPI::Kind::OPENGL: return MakeRef<OpenGLShader>(vertSource, fragSource);
        }
        HX_LOG_ERROR("%s", "Broken \"Shader\" creation due to invalid renderer api kind.");
        return nullptr;
    }

	uint32_t Shader::DataTypeSize(DataType type)
	{
		switch (type)
		{
			case DataType::FLOAT:    return 4;
			case DataType::FLOAT2:   return 4 * 2;
			case DataType::FLOAT3:   return 4 * 3;
			case DataType::FLOAT4:   return 4 * 4;
			case DataType::MAT3:     return 4 * 3 * 3;
			case DataType::MAT4:     return 4 * 4 * 4;
			case DataType::INT:      return 4;
			case DataType::INT2:     return 4 * 2;
			case DataType::INT3:     return 4 * 3;
			case DataType::INT4:     return 4 * 4;
			case DataType::BOOL:     return 1;
		}
		return 0;
	}

	uint32_t Shader::DataTypeComponentCount(DataType type)
	{
		switch (type)
		{
			case DataType::FLOAT:   return 1;
			case DataType::FLOAT2:  return 2;
			case DataType::FLOAT3:  return 3;
			case DataType::FLOAT4:  return 4;
			case DataType::MAT3:    return 3; // 3* float3
			case DataType::MAT4:    return 4; // 4* float4
			case DataType::INT:     return 1;
			case DataType::INT2:    return 2;
			case DataType::INT3:    return 3;
			case DataType::INT4:    return 4;
			case DataType::BOOL:    return 1;
		}
		return 0;		
	}

    std::string LoadFileContent(const std::string& filename)
    {
        std::string result;
		std::ifstream in(filename, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
			}
			else
			{
                HX_LOG_ERROR("Could not read from file '%s'", filename.c_str());
			}
		}
		else
		{
			HX_LOG_ERROR("Could not open file '%s'", filename.c_str());
		}
		return result;
    }
}