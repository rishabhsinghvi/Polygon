#include "PPlane.h"

namespace Polygon
{
	namespace Math
	{
		PPlane::PPlane(PVector3 normal, real_t distance):
			m_Normal(normal), m_Dist(distance)
		{
		}

		PPlane::PPlane(real_t nX, real_t nY, real_t nZ, real_t distance):
			m_Normal(PVector3(nX, nY, nZ)), m_Dist(distance)
		{
		}

		PPlane::PPlane(const PPlane& other):
			m_Normal(other.m_Normal), m_Dist(other.m_Dist)
		{
		}


	}
}