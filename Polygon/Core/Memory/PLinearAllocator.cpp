#include "PLinearAllocator.h"

namespace Polygon
{
	namespace Core
	{
		namespace Memory
		{
			LinearAllocator::LinearAllocator()
			{
				m_StartPtr = ::malloc(1024);
				m_CurPtr = m_StartPtr;
				m_ArenaSize = 1024;
			}

			LinearAllocator::LinearAllocator(std::size_t arenaSize)
			{
				m_StartPtr = ::malloc(arenaSize);
				m_CurPtr = m_StartPtr;
				m_ArenaSize = arenaSize;
			}

			LinearAllocator::~LinearAllocator()
			{
				::free(m_StartPtr);

				m_StartPtr = nullptr;
				m_CurPtr = nullptr;
				m_Allocations = 0;
				m_ArenaSize = 0;
			}

			void* LinearAllocator::Allocate(std::size_t numBytes, std::size_t alignment)
			{
				auto adjustment = Allocator::GetForwardAdjustment(m_CurPtr, alignment);

				return nullptr;
			}

			void LinearAllocator::Deallocate(void* ptr)
			{
			}

			void LinearAllocator::Reset()
			{
			}

			
		}
	}
}