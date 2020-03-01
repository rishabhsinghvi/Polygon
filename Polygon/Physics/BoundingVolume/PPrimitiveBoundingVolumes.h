#ifndef POLYGON_PRIMITIVE_BOUNDING_VOLUMES_H
#define POLYGON_PRIMITIVE_BOUNDING_VOLUMES_H

#include "Math/PVector3.h"
#include "Math/PMath.h"

namespace Polygon
{
	namespace Physics
	{
		namespace BoundingVolume
		{
			using namespace Polygon::Math;

			struct PBoundingSphere
			{
				PVector3 m_Center;
				real_t m_Radius;
			};


			struct PAxisBoundingBox
			{
				PVector3 m_Center;
				PVector3 m_HalfExtents;
			};






			
		}
	}
}


#endif  // POLYGON_PRIMITIVE_BOUNDING_VOLUMES_H