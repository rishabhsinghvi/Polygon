#ifndef POLYGON_CORE_STRING_UTILS_H
#define POLYGON_CORE_STRING_UTILS_H

#include<string>

#include "Core/Core.h"
#include "Core/Types/PString.h"

namespace PolygonEngine
{
	namespace Core
	{
		enum STRING_TRANSFORM_MODE
		{
			STM_UPPER, STM_LOWER
		};

		PString POLYGON_ENGINE_API TransformString(const PString& string, STRING_TRANSFORM_MODE mode);
		PString POLYGON_ENGINE_API TransformString(PString&& string, STRING_TRANSFORM_MODE mode);

		PString POLYGON_ENGINE_API ToLower(const PString& string);
		PString POLYGON_ENGINE_API ToLower(PString&& string);

		PString POLYGON_ENGINE_API ToUpper(const PString& string);
		PString POLYGON_ENGINE_API ToUpper(PString&& string);

		PString POLYGON_ENGINE_API RandomString(PString::size_type length);
	}
}


#endif