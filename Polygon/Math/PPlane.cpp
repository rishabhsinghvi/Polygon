#include "PPlane.h"

namespace PolygonEngine
{
	namespace Math
	{
		PPlane::PPlane(PVector3 normal, PReal distance):
			m_Normal(normal), m_Dist(distance)
		{
		}

		PPlane::PPlane(PReal nX, PReal nY, PReal nZ, PReal distance):
			m_Normal(PVector3(nX, nY, nZ)), m_Dist(distance)
		{
		}

		PPlane::PPlane(const PPlane& other):
			m_Normal(other.m_Normal), m_Dist(other.m_Dist)
		{
		}


	}
}