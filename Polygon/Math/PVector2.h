#ifndef POLYGON_VECTOR2_H
#define POLYGON_VECTOR2_H

#include "Core/Core.h"

namespace Polygon
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PVector2
		{

#ifdef POLYGON_MATH_USE_DOUBLE
			using real_t = double;
#else
			using real_t = float;
#endif

			real_t x, y;

		public:

			explicit PVector2() noexcept;

			explicit PVector2(real_t x, real_t y) noexcept;

			PVector2(const PVector2& other) noexcept;

			PVector2& operator=(const PVector2& other);
			
			PVector2& operator+=(const PVector2& other);
			PVector2& operator-=(const PVector2& other);
			PVector2& operator*=(const PVector2& other);
			PVector2& operator/=(const PVector2& other);

			PVector2 operator+(const PVector2& other);
			PVector2 operator-(const PVector2& other);
			PVector2 operator*(const PVector2& other);
			PVector2 operator/(const PVector2& other);

			PVector2 operator+(real_t scalar);
			PVector2 operator-(real_t scalar);
			PVector2 operator*(real_t scalar);
			PVector2 operator/(real_t scalar);

			real_t GetLength() const;

			void Normalize();
			PVector2 GetNormalized() const;

			static real_t Dot(const PVector2& first, const PVector2& second);

			
			real_t& operator[](unsigned int val);


		};
	}
}



#endif