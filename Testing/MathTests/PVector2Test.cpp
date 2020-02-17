#include "Catch2/catch.hpp"

#include "Math/PVector2.h"

using namespace Polygon::Math;

constexpr float EPSILON = 1e-10;

TEST_CASE("Default Constructor Works", "[PVector2]")
{
	PVector2 vec;
	REQUIRE(vec.x == 0.0);
	REQUIRE(vec.y == 0.0);
}

TEST_CASE("Parameterized Constructor Works", "[PVector2]")
{
	PVector2 vec(5.0f, 2.0f);
	REQUIRE(vec.x == 5.0f);
	REQUIRE(vec.y == 2.0f);
}



