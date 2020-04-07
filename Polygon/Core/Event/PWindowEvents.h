#ifndef POLYGON_WINDOW_EVENTS_H
#define POLYGON_WINDOW_EVENTS_H

#include "Core/Event/PEvent.h"

namespace Polygon
{
	namespace Core
	{
		struct PWindowCloseEvent : public PEvent
		{
			PWindowCloseEvent():
				EVENT(WindowCloseEvent, Application)
			{}
		};
	}
}

#endif // POLYGON_WINDOW_EVENTS_H
