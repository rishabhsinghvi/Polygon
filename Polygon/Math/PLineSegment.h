#ifndef POLYGON_MATH_LINE_SEGMENT_H
#define POLYGON_MATH_LINE_SEGMENT_H

#include "Core/Core.h"
#include "PVector3.h"

namespace PolygonEngine
{
	namespace Math
	{
		/// Forward declare
		struct PAABB;

		struct POLYGON_ENGINE_API PLineSegment
		{
			PVector3 m_Start;
			PVector3 m_End;

			PLineSegment() = default;

			PLineSegment(const PVector3& start, const PVector3& end) noexcept;
			PLineSegment(const PLineSegment& line) noexcept;
			PLineSegment(PLineSegment&& line) noexcept;
			
			PLineSegment& operator=(const PLineSegment& line) noexcept;

			PVector3 GetPoint(PReal d) const;

			PReal GetLength() const;
			PReal GetLengthSquared() const;

			bool Intersects(const PAABB& aabb) const;
			
		};
	}
}

#endif