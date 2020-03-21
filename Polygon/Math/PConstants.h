#ifndef POLYGON_MATH_CONSTANTS_H
#define POLYGON_MATH_CONSTANTS_H

#include "Math/PMath.h"

#include<limits>

namespace Polygon
{
	namespace Math
	{
		constexpr real_t P_PI = static_cast<real_t>(3.14159265358979);
		constexpr real_t P_GOLD_RATIO = static_cast<real_t>(1.6180339887498);
		constexpr real_t P_INFINITY = std::numeric_limits<real_t>::infinity();
		constexpr real_t P_MAX = std::numeric_limits<real_t>::max();
		constexpr real_t P_MIN = std::numeric_limits<real_t>::min();
		constexpr real_t P_NEG_INFINITY = -P_INFINITY;
		constexpr real_t P_EULER = static_cast<real_t>(2.71828182845);


	}
}

#endif