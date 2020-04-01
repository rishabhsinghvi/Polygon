#ifndef POLYGON_VECTOR2_H
#define POLYGON_VECTOR2_H

#include "Core/Core.h"
#include "PMath.h"

namespace PolygonEngine
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PVector2
		{

			PReal x, y;

		public:

			explicit PVector2() noexcept;

			explicit PVector2(PReal x, PReal y) noexcept;

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

			PVector2 operator+(PReal scalar);
			PVector2 operator-(PReal scalar);
			PVector2 operator*(PReal scalar);
			PVector2 operator/(PReal scalar);

			PReal GetLength() const;

			void Normalize();
			PVector2 GetNormalized() const;

			static PReal Dot(const PVector2& first, const PVector2& second);

			
			PReal& operator[](unsigned int val);


		};
	}
}



#endif