#include "PQuaternion.h"
#include "PMat3.h"

#include<cmath>

namespace Polygon
{
	namespace Math
	{
		PQuaternion::PQuaternion() noexcept:
			vec(), w(1.0)
		{
		
		}

		PQuaternion::PQuaternion(const PQuaternion& other) noexcept:
			w(other.w)
		{
			vec.x = other.vec.x;
			vec.y = other.vec.y;
			vec.z = other.vec.z;
		}

		PQuaternion::PQuaternion(real_t x, real_t y, real_t z, real_t w) noexcept:
			vec(std::move(PVector3(x, y, z))), w(w)
		{

		}

		PQuaternion::PQuaternion(const PVector3& vec, real_t scalar) noexcept:
			vec(vec), w(scalar)
		{

		}

		PQuaternion::PQuaternion(const PMat3& mat)
		{
			//TODO!
		}

		PQuaternion PQuaternion::operator+(const PQuaternion& other) const
		{
			return PQuaternion(vec.x + other.vec.x, vec.y + other.vec.y, vec.z + other.vec.z, w + other.w);
		}

		PQuaternion PQuaternion::operator-(const PQuaternion& other) const
		{
			return PQuaternion(vec.x - other.vec.x, vec.y - other.vec.y, vec.z - other.vec.z, w - other.w);
		}

		PQuaternion& PQuaternion::operator+=(const PQuaternion& other)
		{
			vec.x += other.vec.x;
			vec.y += other.vec.y;
			vec.z += other.vec.z;
			w += other.w;

			return *this;
		}

		PQuaternion& PQuaternion::operator-=(const PQuaternion& other)
		{
			vec.x -= other.vec.x;
			vec.y -= other.vec.y;
			vec.z -= other.vec.z;
			w -= other.w;

			return *this;
		}

		PQuaternion PQuaternion::operator/(real_t scalar) const
		{
			if (scalar == 0.0)
				return *this;

			return PQuaternion(vec / scalar, w / scalar);
		}

		real_t PQuaternion::GetLength() const
		{
			return ::sqrt(GetLengthSquared());
		}

		real_t PQuaternion::GetLengthSquared() const
		{
			return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + w * w;
		}

		PQuaternion PQuaternion::GetInverse() const
		{
			return PQuaternion(vec * static_cast<real_t>(-1.0), w) / GetLengthSquared();
		}



	}
}