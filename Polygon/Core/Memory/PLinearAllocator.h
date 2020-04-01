#ifndef POLYGON_LINEAR_ALLOCATOR_H
#define POLYGON_LINEAR_ALLOCATOR_H

#include "Core/Core.h"
#include "PAllocator.h"

namespace PolygonEngine
{
	namespace Core
	{
		namespace Memory
		{
			class POLYGON_ENGINE_API LinearAllocator : public Allocator
			{
			private:
				void* m_CurPtr = nullptr;

			public:

				LinearAllocator();

				LinearAllocator(std::size_t arenaSize);

				~LinearAllocator();

				virtual void* Allocate(std::size_t numBytes, std::size_t alignment) override;

				virtual void Deallocate(void* ptr) override;

				void Reset();

			};
		}
	}
}

#endif // POLYGON_LINEAR_ALLOCATOR_H