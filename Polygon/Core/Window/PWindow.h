#ifndef POLYGON_WINDOW_WINDOW_H
#define POLYGON_WINDOW_WINDOW_H

#include "Core/Core.h"

#include <string>


namespace Polygon
{
	namespace Core
	{
		namespace Window
		{
			class POLYGON_ENGINE_API PWindow
			{
			protected:

				std::string m_WindowTitle;
				unsigned int m_Width;
				unsigned int m_Height;

			public:

				PWindow(const std::string& windowTitle, unsigned int width, unsigned int height);

				PWindow() = delete;


				virtual void Update() = 0;

				virtual void* GetWindowHandle() const = 0;

			};
		}
	}
}



#endif  // POLYGON_WINDOW_WINDOW_H