#ifndef POLYGON_MATH_PLANE_H
#define POLYGON_MATH_PLANE_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace Polygon
{
	namespace Math
	{
		class POLYGON_ENGINE_API PPlane
		{
		private:
			PVector3 m_Normal;
			real_t m_Dist;

		public:

			PPlane() = default; 

			PPlane(PVector3 normal, real_t distance);

			PPlane(real_t nX, real_t nY, real_t nZ, real_t distance);

			PPlane(const PPlane& other);


		};
	}
}

#endif