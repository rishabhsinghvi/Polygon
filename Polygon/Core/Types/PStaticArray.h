#ifndef POLYGON_CORE_TYPES_STATIC_ARRAY_H
#define POLYGON_CORE_TYPES_STATIC_ARRAY_H

#include<array>

namespace PolygonEngine
{
	template<typename T, size_t SIZE>
	using PStaticArray = std::array<T, SIZE>;
}

#endif