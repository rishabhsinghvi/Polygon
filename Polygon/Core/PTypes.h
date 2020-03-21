#ifndef POLYGON_TYPES_H
#define POLYGON_TYPES_H

#include<string>
#include<memory>
#include<cstdint>.

namespace Polygon
{
	
	/*
		Uses default std::allocator right now. 
		Change it to custom allocator later
	*/


	using PString = std::basic_string<char>;
	using PWString = std::basic_string<wchar_t>;

	template<typename T>
	using PUniquePtr = std::unique_ptr<T>;

	template<typename T>
	using PSharePtr = std::shared_ptr<T>;

	using PUInt8 = uint8_t;

}

#endif