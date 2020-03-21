#ifndef POLYGON_AABB_H
#define POLYGON_AABB_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace Polygon
{
	namespace Physics
	{
		using namespace Polygon::Math;

		class POLYGON_ENGINE_API AABB
		{
		private:
			PVector3 m_Min;
			PVector3 m_Max;

		public:

			AABB() = default;

			AABB(const PVector3& min, const PVector3& max);


		};
	}
}


#endif