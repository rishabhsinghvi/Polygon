#ifndef POLYGON_MATH_AABB_H
#define POLYGON_MATH_AABB_H

#include "Core/Core.h"
#include "PVector3.h"

namespace PolygonEngine
{
	namespace Math
	{
		// Forward declarations
		struct PLineSegment;
		struct PSphere;
		struct PPolygon;
		struct PFrustum;
		struct PCapsule;
		struct PTriangle;


		struct POLYGON_ENGINE_API PAABB
		{
			PVector3 m_Min;
			PVector3 m_Max;

			PAABB() = default;

			PAABB(const PVector3& min, const PVector3& max);

			PAABB(const PAABB& other);

			PAABB(PAABB&& other);

			PAABB& operator=(const PAABB& other);

			PVector3 Center() const;

			// Checks whether the AABB fully encloses the given objects
			bool Contains(const PVector3& point) const;
			bool Contains(const PAABB& aabb) const;
			bool Contains(const PSphere& sphere) const;
			bool Contains(const PLineSegment& line) const;
			bool Contains(const PPolygon& polygon) const;
			bool Contains(const PCapsule& capsule) const;
			bool Contains(const PTriangle& triangle) const;

			bool Intersects(const PAABB& aabb) const;
			bool Intersects(const PSphere& sphere) const;
			bool Intersects(const PLineSegment& line) const;
			bool Intersects(const PPolygon& polygon) const;
			bool Intersects(const PCapsule& capsule) const;
			bool Intersects(const PTriangle& triangle) const;
		};
	}
}

#endif