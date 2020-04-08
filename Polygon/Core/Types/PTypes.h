#ifndef POLYGON_TYPES_H
#define POLYGON_TYPES_H


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

	

	

	

}

#endif