#ifndef POLYGON_H
#define POLYGON_H


#include "Core/Core.h"

namespace PolygonEngine
{
	class POLYGON_ENGINE_API PolygonEngine
	{
	private:
		bool m_Initialzed = false;

	public:
		PolygonEngine();

		void Init();
	};
}


#endif