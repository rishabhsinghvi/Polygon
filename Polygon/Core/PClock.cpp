#include "PClock.h"
#include "PLogger.h"

#include<thread>

namespace PolygonEngine
{
	namespace Core
	{
		PClock::PClock():
			m_StartTime(std::chrono::high_resolution_clock::now())
		{
			POLYGON_LOG_INFO("[POLYGON]: [CLOCK] - Created clock with no frame limit.");
		}


		PClock::PClock(PUInt16 maxFrames) :
			m_FrameLimit(1000.0 / static_cast<PReal>(maxFrames)),
			m_StartTime(std::chrono::high_resolution_clock::now())
		{
			POLYGON_LOG_INFO("[POLYGON]: [CLOCK] - Created clock with frame limit {0}", maxFrames);
		}


		PClock::~PClock()
		{
			if (m_FrameLimit)
			{
				auto end = std::chrono::high_resolution_clock::now();
				auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_StartTime).count();

				if (dur < *m_FrameLimit)
				{
					std::this_thread::sleep_for(std::chrono::duration<PReal, std::milli>(*m_FrameLimit - dur));
				}
			}
		}

		void PClock::Reset()
		{
			m_StartTime = std::chrono::high_resolution_clock::now();
		}

	}
}