#include "PRenderingContext.h"

namespace Polygon
{
	namespace Rendering
	{
		void CreateRenderingContext(RenderingPlatform platform)
		{
			switch (platform)
			{
			case RenderingPlatform::OpenGL:
				g_RenderingContext = RenderingContext();
			}
		}
	}
}