#include "PVector4.h"
#include "PMath.h"
#include "Core/PAssertion.h"

namespace PolygonEngine
{
	namespace Math
	{
		PVector4::PVector4(PReal x, PReal y, PReal z, PReal w) noexcept:
			x(x), y(y), z(z), w(w)
		{
		}

		PVector4::PVector4(const PVector4& other) noexcept:
			x(other.x), y(other.y), z(other.z), w(other.w)
		{
		}

		PVector4& PVector4::operator=(const PVector4& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;

			return *this;
		}

		PVector4& PVector4::operator+=(const PVector4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		PVector4& PVector4::operator-=(const PVector4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		PVector4& PVector4::operator*=(const PVector4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		PVector4& PVector4::operator/=(const PVector4& other)
		{
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.x, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.y, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.z, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.w, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");

			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		PVector4 PVector4::operator+(const PVector4& other) const
		{
			return PVector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		PVector4 PVector4::operator-(const PVector4& other) const
		{
			return PVector4(x - other.x, y - other.y, z - other.z, w - other.w);
		}

		PVector4 PVector4::operator*(const PVector4& other) const
		{
			return PVector4(x * other.x, y * other.y, z * other.z, w * other.w);
		}

		PVector4 PVector4::operator/(const PVector4& other) const
		{
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.x, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.y, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.z, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(other.w, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");

			return PVector4(x / other.x, y / other.y, z / other.z, w / other.w);
		}

		PVector4 PVector4::operator+(PReal scalar) const
		{
			return PVector4(x + scalar, y + scalar, z + scalar, w + scalar);
		}

		PVector4 PVector4::operator-(PReal scalar) const
		{
			return PVector4(x - scalar, y - scalar, z - scalar, w - scalar);
		}

		PVector4 PVector4::operator*(PReal scalar) const
		{
			return PVector4(x * scalar, y * scalar, z * scalar, w * scalar);
		}

		PVector4 PVector4::operator/(PReal scalar) const
		{
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(scalar, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");
			return PVector4(x / scalar, y / scalar, z / scalar, w / scalar);
		}

		bool PVector4::operator==(const PVector4& other) const
		{
			return POLYGON_REAL_EQUALS(x, other.x) && POLYGON_REAL_EQUALS(y, other.y) && POLYGON_REAL_EQUALS(z, other.z) 
				&& POLYGON_REAL_EQUALS(w, other.w);
		}

		PReal PVector4::GetLength() const
		{
			return ::sqrt(x * x + y * y + z * z + w * w);
		}

		void PVector4::Normalize()
		{
			auto length = GetLength();
			
			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(length, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");

			x /= length;
			y /= length;
			z /= length;
			w /= length;

		}

		PVector4 PVector4::GetNormalized() const
		{
			auto length = GetLength();

			POLYGON_ASSERT_ERROR(!POLYGON_REAL_EQUALS(length, 0.0), "[POLYGON MATH ERROR]: Divide by zero error!");

			return PVector4(x / length, y / length, z / length, w / length);
		}

		PReal PVector4::Dot(const PVector4& first, const PVector4& second)
		{
			return first.x * second.x + first.y * second.y + first.z * second.z + first.w * second.w;
		}
	}
}