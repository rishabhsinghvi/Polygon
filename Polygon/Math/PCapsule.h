#ifndef POLYGON_MATH_CAPSULE_H
#define POLYGON_MATH_CAPSULE_H

#include "Core/Core.h"
#include "PVector3.h"

namespace PolygonEngine
{
	namespace Math
	{
		struct POLYGON_ENGINE_API PCapsule
		{
			PVector3 m_Start;
			PVector3 m_End;
			PReal m_Radius;

			PCapsule() = default;

			PCapsule(const PVector3& start, const PVector3& end, PReal radius);
			PCapsule(const PCapsule& capsule);
			PCapsule(PCapsule&& capsule);



			
		};
	}
}

#endif