#ifndef POLYGON_MATH_CONSTANTS_H
#define POLYGON_MATH_CONSTANTS_H

#ifdef POLYGON_REAL_IS_DOUBLE
using PReal = double;
#else
using PReal = float;
#endif

#include<limits>

namespace PolygonEngine
{
	namespace Math
	{
		constexpr PReal P_PI = static_cast<PReal>(3.14159265358979);
		constexpr PReal P_GOLD_RATIO = static_cast<PReal>(1.6180339887498);
		constexpr PReal P_INFINITY = std::numeric_limits<PReal>::infinity();
		constexpr PReal P_MAX = std::numeric_limits<PReal>::max();
		constexpr PReal P_MIN = std::numeric_limits<PReal>::min();
		constexpr PReal P_NEG_INFINITY = -P_INFINITY;
		constexpr PReal P_EULER = static_cast<PReal>(2.71828182845);
		constexpr PReal P_EPSILON = std::numeric_limits<PReal>::epsilon();
	}
}

#endif