#ifndef POLYGON_VECTOR4_H
#define POLYGON_VECTOR4_H

#include "Core/PTypes.h"
#include "Core/Core.h"

namespace PolygonEngine
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PVector4
		{
			PReal x = 0.0, y = 0.0, z = 0.0, w = 0.0;

			PVector4() = default;

			explicit PVector4(PReal x, PReal y, PReal z, PReal w) noexcept;

			PVector4(const PVector4& other) noexcept;

			PVector4& operator=(const PVector4& other);

			PVector4& operator+=(const PVector4& other);
			PVector4& operator-=(const PVector4& other);
			PVector4& operator*=(const PVector4& other);
			PVector4& operator/=(const PVector4& other);

			PVector4 operator+(const PVector4& other) const;
			PVector4 operator-(const PVector4& other) const;
			PVector4 operator*(const PVector4& other) const;
			PVector4 operator/(const PVector4& other) const;

			PVector4 operator+(PReal scalar) const;
			PVector4 operator-(PReal scalar) const;
			PVector4 operator*(PReal scalar) const;
			PVector4 operator/(PReal scalar) const;

			bool operator==(const PVector4& other) const;

			PReal GetLength() const;

			void Normalize();
			PVector4 GetNormalized() const;

			static PReal Dot(const PVector4& first, const PVector4& second);
		};
	}
}

#endif // POLYGON_VECTOR4_H