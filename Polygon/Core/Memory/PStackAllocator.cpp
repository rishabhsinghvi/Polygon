#include "PStackAllocator.h"
#include "PLogger.h"
#include "PAssertion.h"

#include <cstdlib>

namespace Polygon
{
    namespace Core
    {
        namespace Memory
        {
            StackAllocator::StackAllocator()
            {
                // Allocates 1KB of memory by default
                m_StartPtr = ::malloc(1024);         
                m_CurPtr = m_StartPtr;        
            }

            StackAllocator::StackAllocator(std::size_t arenaSize);
            {
                m_StartPtr = ::malloc(arenaSize);
                m_CurPtr = m_StartPtr;
            }

            StackAllocator::~StackAllocator()
            {
                POLYGON_ASSERT_ERROR(m_StartPtr != nullptr, "STACKALLOCATOR: m_StartPtr was nullptr when trying to free memory.")
                ::free(m_StartPtr);
                m_StartPtr = nullptr;
                m_CurPtr = nullptr;
                m_Allocations = 0;
            }

            void* Allocate(std::size_t numBytes, std::size_t alignment) override
            {
                POLYGON_ASSERT_ERROR(numBytes > 0, "STACKALLOCATOR: Requested allocation must be greater than 0");
                POLYGON_ASSERT_ERROR(alignment > 0, "STACKALLOCATOR: Requested alignment must be greater than 0.");
                POLYGON_ASSERT_ERROR((alignment & (alignment - 1))==0, "STACKALLOCATOR: Requested alignment must be a power of 2.");

                // TODO

                m_Allocations += 1;
            }


            void Free(void* ptr) override
            {
                // NOTHING. 
            }


            void Reset()
            {
                POLYGON_ASSERT_ERROR(m_StartPtr != nullptr, "STACKALLOCATOR: Attempting to reset an unalloacted arena of memory.");

                m_CurPtr = m_StartPtr;
                m_Allocations = 0;                
            }


        }
    }
}