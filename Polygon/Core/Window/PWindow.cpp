#include "PWindow.h"

namespace PolygonEngine
{
	namespace Core
	{
		namespace Window
		{
			PWindow::PWindow(const std::string& windowTitle, unsigned int width, unsigned int height):
				m_WindowTitle(windowTitle), m_Width(width), m_Height(height)
			{
				// EMPTY
			}
		}
	}
}