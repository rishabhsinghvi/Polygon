#ifndef POLYGON_MATH_SPHERE_H
#define POLYGON_MATH_SPHERE_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace PolygonEngine
{
	namespace Math
	{
		struct PAABB;

		struct POLYGON_ENGINE_API PSphere
		{
			PVector3 m_Center;
			PReal m_Radius;

			PSphere() = default;

			PSphere(const PVector3& center, PReal radius) noexcept;
			PSphere(PReal radius) noexcept;
			PSphere(PReal cX, PReal cY, PReal cZ, PReal radius) noexcept;

			PSphere(const PSphere& other) noexcept;
			PSphere(PSphere&& other) noexcept;

			PSphere& operator=(const PSphere& other) noexcept;

			bool Contains(const PVector3& point);

			bool Intersects(const PSphere& sphere);
			bool Intersects(const PAABB& aabb);

		};
	}
}

#endif