#ifndef POLYGON_CORE_TYPES_MAP_H
#define POLYGON_CORE_TYPES_MAP_H

#include <unordered_map>
#include <map>

namespace PolygonEngine
{
	template<typename K, typename V>
	using PUnorderedMap = std::unordered_map<K, V>;

	template<typename K, typename V>
	using POrderedMap = std::map<K, V>;
}

#endif