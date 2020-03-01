#ifndef POLYGON_VECTOR3_H
#define POLYGON_VECTOR3_H

#include "Core/Core.h"
#include "PMath.h"

namespace Polygon
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PVector3
		{
			real_t x, y, z;

		public:

			PVector3() = default;

			explicit PVector3(real_t x, real_t y, real_t z) noexcept;

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

			PVector3 operator+(real_t scalar) const;
			PVector3 operator-(real_t scalar) const;
			PVector3 operator*(real_t scalar) const;
			PVector3 operator/(real_t scalar) const;

			real_t GetLength() const;

			void Normalize();
			PVector3 GetNormalized() const;

			static real_t Dot(const PVector3& first, const PVector3& second);

			static PVector3 Cross(const PVector3& first, const PVector3& second);

		};
	}
}

#endif