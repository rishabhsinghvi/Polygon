#ifndef POLYGON_STACK_ALLOCATOR_H
#define POLYGON_STACK_ALLOCATOR_H

#include "Core.h"
#include "PAllocator.h"

#include <cstdint>

namespace Polygon
{
    namespace Core
    {
        namespace Memory
        {
            class POLYGON_ENGINE_API StackAllocator: public Allocator
            {
            private:
                void* m_StartPtr = nullptr;
                void* m_CurPtr = nullptr;
                uint16_t m_Allocations = 0;
            
            public:

                StackAllocator();

                StackAllocator(std::size_t arenaSize);

                virtual ~StackAllocator();

                virtual void Allocate(std::size_t numBytes, std::size_t alignment) override;

                virtual void Free(void* freePtr) override;

                void Reset();

            }
        }
    }
}

#endif