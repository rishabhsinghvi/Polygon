#ifndef POLYGON_BODY_H
#define POLYGON_BODY_H

#include "Math/PVector3.h"

namespace Polygon
{
	using BodyID = unsigned int;
	namespace Physics
	{
		namespace Body
		{
			class PBody
			{
			protected:
				BodyID m_ID; 

			};
		}
	}
}

#endif