#include "PGUID.h"

#include <algorithm>

namespace PolygonEngine
{
	namespace Core
	{
		PStaticArray<PUInt32, TABLE_SIZE> GenerateCRCTable()
		{

			PStaticArray<PUInt32, TABLE_SIZE> table;
			const auto polynomial = PUInt32{ 0xEDB88320uL };

			std::generate(std::begin(table), std::end(table), [&]() {
				static PUInt8 n = 0;
				auto c = n;
				for (auto i = 0; i < 8; i++)
				{
					c = (c >> 1) ^ ((c & 0x1u) ? polynomial : 0);
				}
				n++;
				return c;
				});

			return table;
		}

		
	}
}