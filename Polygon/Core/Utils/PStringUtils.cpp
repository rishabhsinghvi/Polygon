#include "PStringUtils.h"

#include <algorithm>
#include <random>

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

		PString RandomString(PString::size_type length)
		{	
			static constexpr auto chars = "0123456789""ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijkllmnopqrstuvwxyz";
			static constexpr auto charsLength = 62;

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, charsLength);

			PString randomString;
			randomString.resize(length);

			std::generate_n(std::begin(randomString), length, [&]() {
				return chars[dis(gen)];
				});

			return randomString;
		}


	}
}

