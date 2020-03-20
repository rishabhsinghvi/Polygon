#ifndef POLYGON_RENDERING_CONTEXT_H
#define POLYGON_RENDERING_CONTEXT_H



namespace Polygon
{
	namespace Rendering
	{
		
		enum class RenderingPlatform
		{
			OpenGL
			// Add others later
		};

		class RenderingContext
		{
				
		};

		
		static RenderingContext g_RenderingContext;

		void CreateRenderingContext(RenderingPlatform platform);

		inline RenderingContext GetRenderingContext()
		{
			return g_RenderingContext;
		}
	}
}

#endif