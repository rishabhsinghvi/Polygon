#include "PCapsule.h"

#include<utility>

namespace PolygonEngine
{
	namespace Math
	{
		PCapsule::PCapsule(const PVector3& start, const PVector3& end, PReal radius):
			m_Start(start), m_End(end), m_Radius(radius)
		{
		}

		PCapsule::PCapsule(const PCapsule& capsule):
			m_Start(capsule.m_Start), m_End(capsule.m_End), m_Radius(capsule.m_Radius)
		{
		}

		PCapsule::PCapsule(PCapsule&& capsule):
			m_Start(std::move(capsule.m_Start)), m_End(std::move(capsule.m_End)), m_Radius(capsule.m_Radius)
		{
		}




	}
}
