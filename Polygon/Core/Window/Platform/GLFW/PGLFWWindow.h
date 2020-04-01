#ifndef POLYGON_WINDOW_GLFW_WINDOW_H
#define POLYGON_WINDOW_GLFW_WINDOW_H

#include "Vendor/GLFW/glfw3.h"

#include "Core/Core.h"
#include "Core/Window/PWindow.h"

namespace PolygonEngine
{
	namespace Core
	{
		namespace Window
		{
			class POLYGON_ENGINE_API PGLFWWindow : public PWindow
			{
			private:
				GLFWwindow* m_WindowHandle = nullptr;

			public:

				PGLFWWindow(const std::string& windowTitle, unsigned int width, unsigned int height);

				PGLFWWindow(const PGLFWWindow& window) = delete;

				virtual void Update() override;

				virtual void* GetWindowHandle() const override;

			};

		}
	}
}


#endif // POLYGON_WINDOW_GLFW_WINDOW_H