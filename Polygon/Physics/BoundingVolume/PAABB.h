#ifndef POLYGON_AABB_H
#define POLYGON_AABB_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace PolygonEngine
{
	namespace Physics
	{
		using namespace PolygonEngine::Math;


		class POLYGON_ENGINE_API PAABB
		{
		private:
			PVector3 m_Min;
			PVector3 m_Max;

		public:

			PAABB() = default;

			PAABB(const PVector3& min, const PVector3& max);



		};
	}
}


#endif