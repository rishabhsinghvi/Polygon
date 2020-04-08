#ifndef POLYGON_CORE_STRING_UTILS_H
#define POLYGON_CORE_STRING_UTILS_H

#include<string>

#include "Core/Types/PString.h"

namespace PolygonEngine
{
	namespace Core
	{
		enum STRING_TRANSFORM_MODE
		{
			STM_UPPER, STM_LOWER
		};

		PString TransformString(const PString& string, STRING_TRANSFORM_MODE mode);
		PString TransformString(PString&& string, STRING_TRANSFORM_MODE mode);

		PString ToLower(const PString& string);
		PString ToLower(PString&& string);

		PString ToUpper(const PString& string);
		PString ToUpper(PString&& string);
	}
}


#endif