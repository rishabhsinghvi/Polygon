#include "PVector2.h"

#include<cmath>

namespace PolygonEngine
{
	namespace Math
	{
		PVector2::PVector2():
			x(), y()
		{
		}

		PVector2::PVector2(PReal x, PReal y):
			x(x), y(y)
		{
			
		}

		PVector2::PVector2(const PVector2& other):
			x(other.x), y(other.y)
		{

		}

		PVector2& PVector2::operator=(const PVector2& other)
		{
			if (this == &other)
				return *this;

			x = other.x;
			y = other.y;

			return *this;
		}

		PVector2& PVector2::operator+=(const PVector2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		PVector2& PVector2::operator-=(const PVector2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		PVector2& PVector2::operator*=(const PVector2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		PVector2& PVector2::operator/=(const PVector2& other)
		{
			if (other.x == 0.0 || other.y == 0.0)
				return *this;

			x /= other.x;
			y /= other.y;

			return *this;
		}

		PVector2 PVector2::operator+(const PVector2& other)
		{
			return PVector2(x + other.x, y + other.y);
		}

		PVector2 PVector2::operator-(const PVector2& other)
		{
			return PVector2(x - other.x, y - other.y);
		}

		PVector2 PVector2::operator*(const PVector2& other)
		{
			return PVector2(x * other.x, y * other.y);
		}

		PVector2 PVector2::operator/(const PVector2& other)
		{
			if (other.x == 0.0 || other.y == 0.0)
				return *this;

			return PVector2(x / other.x, y / other.y);
		}

		PVector2 PVector2::operator+(PReal scalar)
		{
			return PVector2(x + scalar, y + scalar);
		}

		PVector2 PVector2::operator-(PReal scalar)
		{
			return PVector2(x - scalar, y - scalar);
		}

		PVector2 PVector2::operator*(PReal scalar)
		{
			return PVector2(x * scalar, y * scalar);
		}

		PVector2 PVector2::operator/(PReal scalar)
		{
			if (scalar == 0.0)
				return *this;

			return PVector2(x / scalar, y / scalar);
		}







		PReal PVector2::GetLength() const
		{
			return ::sqrt(x * x + y * y);
		}

		void PVector2::Normalize()
		{
			auto length = GetLength();
			if (length == 0.0)
				return;

			x /= length;
			y /= length;
		}

		PVector2 PVector2::GetNormalized() const
		{
			auto length = GetLength();
			if (length == 0.0)
				return *this;

			return PVector2(x / length, y / length);
		}

		PReal PVector2::Dot(const PVector2& first, const PVector2& second)
		{
			return first.x * second.x + first.y * second.y;
		}

		PReal& PVector2::operator[](unsigned int val)
		{
			switch (val)
			{
			case 0: return x; break;
			case 1: return y; break;
			default: return x;
			}
			
		}




















		







	}
}