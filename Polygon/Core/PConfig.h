#ifndef POLYGON_CORE_CONFIG_H
#define POLYGON_CORE_CONFIG_H

#include "Core/Core.h"
#include "Core/Types/PString.h"
#include "Core/Types/PMap.h"

namespace PolygonEngine
{
	namespace Core
	{
		class POLYGON_ENGINE_API PConfig
		{
		private:
			PUnorderedMap<PString, PString> m_ConfigData;

		public:
			
		};
	}
}

#endif