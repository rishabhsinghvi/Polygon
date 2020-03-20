#include "PGLFWWindow.h"
#include "Core/Logger/PLogger.h"

namespace Polygon
{
	namespace Core
	{

		namespace Window
		{
			PGLFWWindow::PGLFWWindow(const std::string& windowTitle, unsigned int width, unsigned int height) :
				PWindow(windowTitle, width, height)
			{
				if (!glfwInit())
				{
					POLYGON_LOG_CRITICAL("Window: GLFW initialization failed!");
				}



			}

			void PGLFWWindow::Update()
			{
				//glfwSwapBuffers(m_WindowHandle);
				//glfwPollEvents();
			}

			void* PGLFWWindow::GetWindowHandle() const
			{
				return static_cast<void*>(m_WindowHandle);
			}
		}
	}
}