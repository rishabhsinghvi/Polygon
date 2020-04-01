#ifndef POLYGON_GEOMETRY_NODE_H
#define POLYGON_GEOMETRY_NODE_H

#include "Core/Core.h"
#include "Core/PTypes.h"
#include "Rendering/Scene/PSceneNode.h"


namespace PolygonEngine
{
	namespace Rendering
	{
		using namespace PolygonEngine::Physics;
		class POLYGON_ENGINE_API PGeometryNode : public PSceneNode
		{
		private:
			
			// For frustum culling tests
			PAABB m_BoundingBox;


		public:

			

		};
	}
}

#endif