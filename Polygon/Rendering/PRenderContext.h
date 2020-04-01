#ifndef POLYGON_RENDER_CONTEXT_H
#define POLYGON_RENDER_CONTEXT_H

#include "Core/Core.h"
#include "Core/PTypes.h"

namespace PolygonEngine
{
	namespace Rendering
	{
		enum class PRenderPlatform
		{
			Base,
			OpenGL,
			Vulkan,
			DirectX11,
			DirectX12
			// Add more later
		};

		class POLYGON_ENGINE_API PRenderContext
		{
		private:
			PRenderPlatform m_RenderPlatform = PRenderPlatform::Base;

		public:

			PRenderContext() = default;

			PRenderContext(PRenderPlatform platform);

			virtual void SetupRenderContext(void* windowHandle) = 0;

			PRenderPlatform GetRenderPlatform() const;

		};


		class RenderContextFactory
		{
			static PUniquePtr<PRenderContext> CreateRenderContext(PUInt8 platform);
		};

	}
}

#endif  // POLYGON_RENDER_CONTEXT_H