#ifndef POLYGON_OPENGL_RENDER_CONTEXT_H
#define POLYGON_OPENGL_RENDER_CONTEXT_H

#include "Core/Core.h"
#include "Rendering/PRenderContext.h"

namespace Polygon
{
	namespace Rendering
	{
		class POLYGON_ENGINE_API POpenGLRenderContext : public PRenderContext
		{
		public:
			POpenGLRenderContext(PRenderPlatform platform):
				PRenderContext(platform)
			{}

			virtual void SetupRenderContext() override;
		};
	}
}

#endif