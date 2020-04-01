#ifndef POLYGON_QUARTERNION_H
#define POLYGON_QUARTERNION_H

#include "Core/Core.h"
#include "Math.h"
#include "Math/PVector3.h"

namespace PolygonEngine
{
	namespace Math
	{
		class PMat3;
	}
}


namespace PolygonEngine
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PQuaternion
		{

			PVector3 vec;
			PReal w;

			// The default constructor constructs a quaternion with x = 0, y = 0, z = 0, w = 1
			PQuaternion() noexcept;

			PQuaternion(const PQuaternion& other) noexcept;

			PQuaternion(PReal x, PReal y, PReal z, PReal w) noexcept;

			PQuaternion(const PVector3& vec, PReal scalar) noexcept;

			PQuaternion(const PMat3& mat);
			
			PQuaternion operator+(const PQuaternion& other) const;
			PQuaternion operator-(const PQuaternion& other) const;

			PQuaternion& operator+=(const PQuaternion& other);
			PQuaternion& operator-=(const PQuaternion& other);

			PQuaternion operator/(PReal scalar) const;


			PReal GetLength() const;
			PReal GetLengthSquared() const;

			PQuaternion GetInverse() const;

		};



	}
}

#endif