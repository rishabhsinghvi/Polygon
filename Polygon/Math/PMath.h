#ifndef POLYGON_MATH_H
#define POLYGON_MATH_H

#include "PConstants.h"

#include<algorithm>
#include<cmath>

namespace PolygonEngine
{
	namespace Math
	{
		static bool IsApproxEqual(PReal x, PReal y)
		{
			PReal scale = std::max(std::abs(x), std::abs(y));
			return std::fabs(x - y) <= scale * (2 * P_EPSILON);
		}
	}
}

#define POLYGON_REAL_EQUALS(x, y) PolygonEngine::Math::IsApproxEqual(x, y)

#endif