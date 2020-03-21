#include "PRay.h"


namespace Polygon
{
	namespace Physics
	{
		PRay::PRay(PVector3& origin, PVector3& dir):
			m_Origin(origin), m_Dir(dir)
		{

		}

		PRay::PRay(real_t orX, real_t orY, real_t orZ, real_t dirX, real_t dirY, real_t dirZ):
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