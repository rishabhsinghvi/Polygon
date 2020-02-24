#ifndef POLYGON_QUARTERNION_H
#define POLYGON_QUARTERNION_H

#include "Core/Core.h"
#include "Math.h"
#include "Math/PVector3.h"

namespace Polygon
{
	namespace Math
	{
		class PMat3;
	}
}


namespace Polygon
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PQuaternion
		{

			PVector3 vec;
			real_t w;

			// The default constructor constructs a quaternion with x = 0, y = 0, z = 0, w = 1
			PQuaternion() noexcept;

			PQuaternion(const PQuaternion& other) noexcept;

			PQuaternion(real_t x, real_t y, real_t z, real_t w) noexcept;

			PQuaternion(const PVector3& vec, real_t scalar) noexcept;

			PQuaternion(const PMat3& mat);
			
			PQuaternion operator+(const PQuaternion& other) const;
			PQuaternion operator-(const PQuaternion& other) const;

			PQuaternion& operator+=(const PQuaternion& other);
			PQuaternion& operator-=(const PQuaternion& other);

			PQuaternion operator/(real_t scalar) const;


			real_t GetLength() const;
			real_t GetLengthSquared() const;

			PQuaternion GetInverse() const;

		};



	}
}

#endif