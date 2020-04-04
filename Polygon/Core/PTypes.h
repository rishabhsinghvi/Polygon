#ifndef POLYGON_TYPES_H
#define POLYGON_TYPES_H

#include<string>
#include<memory>
#include<cstdint>
#include<vector>
#include<array>

namespace PolygonEngine
{
	
	/*
		Uses default std::allocator right now. 
		Change it to custom allocator later
	*/

#ifdef POLYGON_REAL_IS_DOUBLE
	using PReal = double;
#else
	using PReal = float;
#endif // POLYGON_REAL_IS_DOUBLE

	using PString = std::basic_string<char>;
	using PWString = std::basic_string<wchar_t>;

	template<typename T>
	using PUniquePtr = std::unique_ptr<T>;

	template<typename T>
	using PSharePtr = std::shared_ptr<T>;

	using PUInt8 = uint8_t;

	template<typename T>
	using PDynArray = std::vector<T>;

	template<typename T, size_t SIZE>
	using PStaticArray = std::array<T, SIZE>;

}

#endif