#ifndef POLYGON_MATH_PLANE_H
#define POLYGON_MATH_PLANE_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace PolygonEngine
{
	namespace Math
	{
		class POLYGON_ENGINE_API PPlane
		{
		private:
			PVector3 m_Normal;
			PReal m_Dist;

		public:

			PPlane() = default; 

			PPlane(PVector3 normal, PReal distance);

			PPlane(PReal nX, PReal nY, PReal nZ, PReal distance);

			PPlane(const PPlane& other);

		};
	}
}

#endif