#include "PRay.h"


namespace PolygonEngine
{
	namespace Physics
	{
		PRay::PRay(PVector3& origin, PVector3& dir):
			m_Origin(origin), m_Dir(dir)
		{

		}

		PRay::PRay(PReal orX, PReal orY, PReal orZ, PReal dirX, PReal dirY, PReal dirZ):
			m_Origin(PVector3(orX, orY, orZ)), m_Dir(PVector3(dirX, dirY, dirZ))
		{
		}

		PRay::PRay(const PRay& other):
			m_Origin(other.m_Origin), m_Dir(other.m_Dir)
		{
		}

		const PVector3& PRay::GetOrigin() const
		{
			return m_Origin;
		}

		const PVector3& PRay::GetDirection() const
		{
			return m_Dir;
		}






	}
}