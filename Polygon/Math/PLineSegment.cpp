#include "PLineSegment.h"
#include "PAABB.h"

#include<utility>

namespace PolygonEngine
{
	namespace Math
	{
		PLineSegment::PLineSegment(const PVector3& start, const PVector3& end) noexcept:
			m_Start(start), m_End(end)
		{
		}

		PLineSegment::PLineSegment(const PLineSegment& line) noexcept:
			m_Start(line.m_Start), m_End(line.m_End)
		{
		}

		PLineSegment::PLineSegment(PLineSegment&& line) noexcept:
			m_Start(std::move(line.m_Start)), m_End(std::move(m_End))
		{
		}

		PLineSegment& PLineSegment::operator=(const PLineSegment& line) noexcept
		{
			m_Start = line.m_Start;
			m_End = line.m_End;

			return *this;
		}

		PVector3 PLineSegment::GetPoint(PReal d) const
		{
			return (1.0 - d) * m_Start + d * m_End;
		}

		PReal PLineSegment::GetLength() const
		{
			return (m_End - m_Start).GetLength();
		}

		PReal PLineSegment::GetLengthSquared() const
		{
			return (m_End - m_Start).GetLengthSquared();
		}

		bool PLineSegment::Intersects(const PAABB& aabb) const
		{
			return aabb.Intersects(*this);
		}



		











	}
}