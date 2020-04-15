#ifndef POLYGON_CORE_GUID_H
#define POLYGON_CORE_GUID_H

#include "Core/Types/PStaticArray.h"
#include "Core/Types/PIntTypes.h"

#include <numeric>
#include <algorithm>
#include <string>

namespace PolygonEngine
{
	namespace Core
	{
		/*static constexpr size_t TABLE_SIZE = 256;
	
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

	
		*/

		// Compile time CRC32. See: https://stackoverflow.com/a/28801005/4678128
		// Generate CRC lookup table
		template <unsigned c, int k = 8>
		struct f : f<((c & 1) ? 0xedb88320 : 0) ^ (c >> 1), k - 1> {};
		template <unsigned c> struct f<c, 0> { enum { value = c }; };

		#define A(x) B(x) B(x + 128)
		#define B(x) C(x) C(x +  64)
		#define C(x) D(x) D(x +  32)
		#define D(x) E(x) E(x +  16)
		#define E(x) F(x) F(x +   8)
		#define F(x) G(x) G(x +   4)
		#define G(x) H(x) H(x +   2)
		#define H(x) I(x) I(x +   1)
		#define I(x) f<x>::value ,

		constexpr unsigned crc_table[] = { A(0) };

		// Constexpr implementation and helpers
		constexpr PUInt32 crc32_impl(const PUInt8* p, size_t len, PUInt32 crc) {
			return len ?
				crc32_impl(p + 1, len - 1, (crc >> 8) ^ crc_table[(crc & 0xFF) ^ *p])
				: crc;
		}

		constexpr PUInt32 crc32(const PUInt8* data, size_t length) {
			return ~crc32_impl(data, length, ~0);
		}

		constexpr size_t strlen_c(const char* str) {
			return *str ? 1 + strlen_c(str + 1) : 0;
		}

		constexpr PUInt32 GUID(const char* str) {
			return crc32((uint8_t*)str, strlen_c(str));
		}

	}
}

//#define GUID(x) PolygonEngine::Core::CRC32(std::begin(x), std::end(x))

#endif