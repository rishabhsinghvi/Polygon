#include "PStackAllocator.h"

#include <cstdlib>

namespace PolygonEngine
{
	namespace Core
	{
		namespace Memory
		{
			StackAllocator::StackAllocator()
			{
				m_StartPtr = ::malloc(1024);
				m_CurPtr = m_StartPtr;
				m_ArenaSize = 1024;
			}

			StackAllocator::StackAllocator(std::size_t arenaSize)
			{
				m_StartPtr = ::malloc(arenaSize);
				m_CurPtr = m_StartPtr;
				m_ArenaSize = arenaSize;
			}

			StackAllocator::~StackAllocator()
			{
				::free(m_StartPtr);

				m_StartPtr = nullptr;
				m_CurPtr = nullptr;
				m_Allocations = 0;
				m_ArenaSize = 0;
			}



			void* StackAllocator::Allocate(std::size_t numBytes, std::size_t alignment)
			{
				

				// TODO
				return nullptr;

			}

			void StackAllocator::Deallocate(void* ptr)
			{
				// NOTHING
			}
			void StackAllocator::Reset()
			{
				m_CurPtr = m_StartPtr;
				m_Allocations = 0;
			}
		}
	}
}