#include "Polygon/Polygon.h"
#include "Core/Logger/PLogger.h"
#include "Rendering/PRenderContext.h"

namespace PolygonEngine
{
	PolygonEngine::PolygonEngine()
	{
		POLYGON_LOG_INFO("[POLYGON ENGINE]: Starting Engine.");
		Init();
	}

	void PolygonEngine::Init()
	{
		if (m_Initialzed)
			return;

		m_Initialzed = true;

		POLYGON_LOG_INFO("[POLYGON ENGINE]: Initializing all subsystems.");

	}




}