#ifndef POLYGON_VECTOR3_H
#define POLYGON_VECTOR3_H

#include "Core/Core.h"
#include "PMath.h"

namespace PolygonEngine
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PVector3
		{
			PReal x, y, z;

		public:

			PVector3() = default;

			explicit PVector3(PReal x, PReal y, PReal z) noexcept;

			PVector3(const PVector3 & other) noexcept;

			PVector3& operator=(const PVector3 & other);

			PVector3& operator+=(const PVector3 & other);
			PVector3& operator-=(const PVector3 & other);
			PVector3& operator*=(const PVector3 & other);
			PVector3& operator/=(const PVector3 & other);

			PVector3 operator+(const PVector3 & other) const;
			PVector3 operator-(const PVector3 & other) const;
			PVector3 operator*(const PVector3 & other) const;
			PVector3 operator/(const PVector3 & other) const;

			PVector3 operator+(PReal scalar) const;
			PVector3 operator-(PReal scalar) const;
			PVector3 operator*(PReal scalar) const;
			PVector3 operator/(PReal scalar) const;

			PReal GetLength() const;

			void Normalize();
			PVector3 GetNormalized() const;

			static PReal Dot(const PVector3& first, const PVector3& second);

			static PVector3 Cross(const PVector3& first, const PVector3& second);

		};
	}
}

#endif