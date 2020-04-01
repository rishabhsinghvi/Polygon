#ifndef POLYGON_ALLOCATOR_H
#define POLYGON_ALLOCATOR_H

#include "Core/Core.h"

#include <cstdlib>

namespace PolygonEngine
{
	namespace Core
	{
		namespace Memory
		{
			class POLYGON_ENGINE_API Allocator
			{
			protected:
				void* m_StartPtr = nullptr;
				std::size_t m_ArenaSize = 0;
				std::size_t m_Allocations = 0;

			public:

				virtual ~Allocator() = default; 

				virtual void* Allocate(std::size_t numBytes, std::size_t alignment) = 0;

				virtual void Deallocate(void* ptr) = 0;

				static std::size_t GetForwardAdjustment(void* address, std::size_t alignment);

			};
		}
	}
}

#endif