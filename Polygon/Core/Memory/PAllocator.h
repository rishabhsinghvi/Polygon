#ifndef POLYGON_ALLOCATOR_H
#define POLYGON_ALLOCATOR_H

#include <cstddef>

namespace Polygon
{
	namespace Core
	{
		namespace Memory
		{
			class Allocator
			{
			public:

				virtual void* Allocate(std::size_t size, std::size_t alignment) = 0;

				virtual void Free(void* ptr) = 0;
			};
		}
	}
}

#endif