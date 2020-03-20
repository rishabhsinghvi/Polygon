#ifndef POLYGON_PHYSICS_RAY_H
#define POLYGON_PHYSICS_RAY_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace Polygon
{
	namespace Physics
	{
		using namespace Polygon::Math;
		class POLYGON_ENGINE_API PRay
		{
		private:
			PVector3 m_Origin;
			PVector3 m_Dir;

		public:

			PRay() = default;

			PRay(PVector3& origin, PVector3& dir);

			PRay(real_t orX, real_t orY, real_t orZ, real_t dirX, real_t dirY, real_t dirz);

			PRay(const PRay& other);

			const PVector3& GetOrigin() const;

			const PVector3& GetDirection() const;


		};
	}
}

#endif