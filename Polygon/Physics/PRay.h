#ifndef POLYGON_PHYSICS_RAY_H
#define POLYGON_PHYSICS_RAY_H

#include "Core/Core.h"
#include "Math/PVector3.h"

namespace PolygonEngine
{
	namespace Physics
	{
		using namespace PolygonEngine::Math;
		class POLYGON_ENGINE_API PRay
		{
		private:
			PVector3 m_Origin;
			PVector3 m_Dir;

		public:

			PRay() = default;

			PRay(PVector3& origin, PVector3& dir);

			PRay(PReal orX, PReal orY, PReal orZ, PReal dirX, PReal dirY, PReal dirz);

			PRay(const PRay& other);

			const PVector3& GetOrigin() const;

			const PVector3& GetDirection() const;


		};
	}
}

#endif