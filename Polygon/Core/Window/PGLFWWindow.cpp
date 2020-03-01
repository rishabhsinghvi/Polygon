#include "PGLFWWindow.h"

namespace Polygon
{
	namespace Core
	{
		namespace Window
		{
			PGLFWWindow::PGLFWWindow(const std::string& windowTitle, unsigned int width, unsigned int height) :
				PWindow(windowTitle, width, height)
			{
			}

			void PGLFWWindow::Update()
			{
				glfwSwapBuffers(m_WindowHandle);
				glfwPollEvents();
			}

			void* PGLFWWindow::GetWindowHandle() const
			{
				return static_cast<void*>(m_WindowHandle);
			}
		}
	}
}