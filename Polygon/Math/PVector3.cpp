#include "PVector3.h"

#include<cmath>

namespace PolygonEngine
{
	namespace Math
	{
		PVector3::PVector3(PReal x, PReal y, PReal z) noexcept:
			x(x), y(y), z(z)
		{
		}

		PVector3::PVector3(const PVector3& other) noexcept:
			x(other.x), y(other.y), z(other.z)
		{
		}

		PVector3& PVector3::operator=(const PVector3& other)
		{
			if (this == &other)
				return *this;

			x = other.x;
			y = other.y;
			z = other.z;

			return *this;
		}

		PVector3& PVector3::operator+=(const PVector3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		PVector3& PVector3::operator-=(const PVector3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		PVector3& PVector3::operator*=(const PVector3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		PVector3& PVector3::operator/=(const PVector3& other)
		{
			if (other.x == 0.0 || other.y == 0.0 || other.z == 0.0)
				return *this;

			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		PVector3 PVector3::operator+(const PVector3& other) const
		{
			return PVector3(x + other.x, y + other.y, z + other.z);
		}

		PVector3 PVector3::operator-(const PVector3& other) const
		{
			return PVector3(x - other.x, y - other.y, z - other.z);
		}

		PVector3 PVector3::operator*(const PVector3& other) const
		{
			return PVector3(x * other.x, y * other.y, z * other.z);
		}

		PVector3 PVector3::operator/(const PVector3& other) const
		{
			if (other.x == 0.0 || other.y == 0.0 || other.z == 0)
				return *this;

			return PVector3(x / other.x, y / other.y, z / other.z);
		}

		PVector3 PVector3::operator+(PReal scalar) const
		{
			return PVector3(x + scalar, y + scalar, z + scalar);
		}

		PVector3 PVector3::operator-(PReal scalar) const
		{
			return PVector3(x - scalar, y - scalar, z - scalar);
		}

		PVector3 PVector3::operator*(PReal scalar) const
		{
			return PVector3(x * scalar, y * scalar, z * scalar);
		}

		PVector3 PVector3::operator/(PReal scalar) const
		{
			if (scalar == 0.0)
				return *this;

			return PVector3(x / scalar, y / scalar, z / scalar);
		}

		PReal PVector3::GetLength() const
		{
			return ::sqrt(x * x + y * y + z * z);
		}

		void PVector3::Normalize()
		{
			auto length = GetLength();
			if (length == 0)
				return;

			x /= length;
			y /= length;
			z /= length;
		}

		PVector3 PVector3::GetNormalized() const
		{
			auto length = GetLength();
			if (length == 0.0)
				return *this;

			return PVector3(x / length, y / length, z / length);
		}

		PReal PVector3::Dot(const PVector3& first, const PVector3& second)
		{
			return first.x * second.x + first.y * second.y + first.z * second.z;
		}

		PVector3 PVector3::Cross(const PVector3& first, const PVector3& second)
		{
			return PVector3(first.y * second.z - first.z * second.y,
				first.z * second.x - first.x * second.z,
				first.x * second.y - first.y * second.x);
		}
	}
}