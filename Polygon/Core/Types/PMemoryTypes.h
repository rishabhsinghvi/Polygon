#ifndef POLYGON_CORE_TYPES_INT_TYPES_H
#define POLYGON_CORE_TYPES_INT_TYPES_H

#include<memory>

namespace PolygonEngine
{
	template<typename T>
	using PUniquePtr = std::unique_ptr<T>;

	template<typename T>
	using PSharePtr = std::shared_ptr<T>;
}


#endif