#ifndef POLYGON_CORE_GUID_H
#define POLYGON_CORE_GUID_H

#include "Core/PTypes.h"

#include <numeric>
#include <algorithm>

namespace PolygonEngine
{
	namespace Core
	{
		static constexpr size_t TABLE_SIZE = 256;
	
		PStaticArray<PUInt32, TABLE_SIZE> GenerateCRCTable();

		template<typename Iterator>
		PUInt32 CRC32(Iterator begin, Iterator end)
		{
			static const auto table = GenerateCRCTable();

			return PUInt32{ 0xFFFFFFFFuL } &
				~std::accumulate(begin, end,
					~PUInt32{ 0 } & PUInt32{ 0xFFFFFFFFuL },
					[](PUInt32 checksum, PUInt8 value)
					{ return table[(checksum ^ value) & 0xFFu] ^ (checksum >> 8); });
		}

	}
}

#define GUID(x) PolygonEngine::Core::CRC32(std::begin(x), std::end(x))

#endif