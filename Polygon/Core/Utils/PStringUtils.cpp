#include "PStringUtils.h"

#include <algorithm>

namespace PolygonEngine
{
	namespace Core
	{
		PString TransformString(const PString& string, STRING_TRANSFORM_MODE mode)
		{
			PString res;

			res.reserve(string.size());

			std::transform(string.begin(), string.end(), std::back_inserter(res), [mode](char c) {
				return (mode == STM_LOWER) ? std::tolower(c) : std::toupper(c);
				});
			return res;
		}

		PString TransformString(PString&& string, STRING_TRANSFORM_MODE mode)
		{
			std::transform(string.begin(), string.end(), string.begin(), [mode](char c) {
				return (mode == STM_LOWER) ? std::tolower(c) : std::toupper(c);
				});
			return string;
		}

		PString ToLower(const PString& string)
		{
			return TransformString(string, STM_LOWER);
		}

		PString ToLower(PString&& string)
		{
			return TransformString(std::move(string), STM_LOWER);
		}

		PString ToUpper(const PString& string)
		{
			return TransformString(string, STM_UPPER);
		}

		PString ToUpper(PString&& string)
		{
			return TransformString(std::move(string), STM_UPPER);
		}


	}
}

