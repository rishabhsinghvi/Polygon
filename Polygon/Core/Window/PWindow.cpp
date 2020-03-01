#include "PWindow.h"

namespace Polygon
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