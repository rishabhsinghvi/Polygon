#include "PRenderContext.h"
#include "Platform/OpenGL/POpenGLRenderContext.h"

namespace Polygon
{
	namespace Rendering
	{
		PRenderContext::PRenderContext(PRenderPlatform platform):
			m_RenderPlatform(platform)
		{
		
		}

		PRenderPlatform PRenderContext::GetRenderPlatform() const
		{
			return m_RenderPlatform;
		}



		/*
			CreateRenderContext receives an unsigned 8-bit integer, which represents the type of rendering platform stored in config file
			0 - OpenGL
			1 - Vulkan
			2 - DirectX11
			3 - DirectX12
		*/
		PUniquePtr<PRenderContext> RenderContextFactory::CreateRenderContext(PUInt8 platform)
		{
			switch (platform)
			{
			case 0:
				return std::make_unique<POpenGLRenderContext>(PRenderPlatform::OpenGL);

			// Add more later
			default: 
				// ASSERT(false)
			}
		}

	}
}