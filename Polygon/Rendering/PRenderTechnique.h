#ifndef POLYGON_RENDER_TECHNIQUE_H
#define POLYGON_RENDER_TECHNIQUE_H

namespace Polygon
{
	namespace Rendering
	{
		enum PRenderTechnique
		{
			// Render to a depth buffer
			RENDER_TECH_DEPTH = 1 << 0,

			// Deferred rendering
			RENDER_TECH_DEFERRED = 1 << 1,

			// Forward rendering, for transparent objects
			RENDER_TECH_FORWARD = 1 << 2
		};
	}
}

#endif // POLYGON_RENDER_TECHNIQUE_H
