#ifndef POLYGON_CORE_CLOCK_H
#define POLYGON_CORE_CLOCK_H

#include "Core/Core.h"
#include "Core/Types/PTypes.h"
#include "Core/Types/PIntTypes.h"

#include<optional>
#include<chrono>

namespace PolygonEngine
{
	namespace Core
	{
		class POLYGON_ENGINE_API PClock
		{
		private:
			// Optional frame limit
			std::optional<PReal> m_FrameLimit = std::nullopt;
			
			//  Time when the clock was started
			std::chrono::high_resolution_clock::time_point m_StartTime;

		public:
			
			PClock();

			PClock(PUInt16 maxFrames);

			~PClock();

			void Reset();
		};
	}
}

#endif