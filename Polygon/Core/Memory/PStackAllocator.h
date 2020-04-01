#ifndef POLYGON_STACK_ALLOCATOR_H
#define POLYGON_STACK_ALLOCATOR_H

#include "Core/Memory/PAllocator.h"

namespace PolygonEngine
{
	namespace Core
	{
		namespace Memory
		{
			class POLYGON_ENGINE_API StackAllocator : public Allocator
			{
			private:
				void* m_CurPtr = nullptr;
			public:

				StackAllocator();

				StackAllocator(std::size_t arenaSize);

				virtual ~StackAllocator();

				virtual void* Allocate(std::size_t numBytes, std::size_t alignment) override;

				virtual void Deallocate(void* ptr) override;

				void Reset();
			};
		}
	}
}

#endif