#ifndef POLYGON_SHADER_H
#define POLYGON_SHADER_H

#include "Core/Core.h"

#include<string>
#include<cstdint>

namespace PolygonEngine
{
	namespace Rendering
	{
		using RenderID = uint32_t;

		struct POLYGON_ENGINE_API PShader
		{
			virtual ~PShader() = default;

			virtual void Bind() const = 0;

			virtual void Unbind() const = 0;
		};
	}
}


#endif