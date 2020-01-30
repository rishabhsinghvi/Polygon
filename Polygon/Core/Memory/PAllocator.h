#ifndef POLYGON_ALLOCATOR_H
#define POLYGON_ALLOCATOR_H

#include "Core.h"

#include <cstddef>

namespace Polygon
{
    namespace Core
    {
        namespace Memory
        {
            struct POLYGON_ENGINE_API Allocator
            {
                virtual ~Allocator();
                
                virtual void* Allocate(std::size_t numBytes, std::size_t alignment) = 0;

                virtual void Free(void* freePtr) = 0;
            }
        }
    }
}


#endif