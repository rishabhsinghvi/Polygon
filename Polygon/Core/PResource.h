#ifndef POLYGON_CORE_RESOURCE_H
#define POLYGON_CORE_RESOURCE_H

#include "Core/Core.h"
#include "Core/Types/PString.h"
#include "Core/Utils/PGUID.h"
#include "Core/Types/PIntTypes.h"

namespace PolygonEngine
{
	namespace Core
	{
		class POLYGON_ENGINE_API PResource
		{
		public:
			enum RESOURCE_STATUS
			{
				// Resource created, but not yet loaded into memory
				RESOURCE_CREATED = 0,

				// Resource loaded in memory, and ready to use
				RESOURCE_LOADED = 1,

				// Resource unloaded from memory, but still exists and data be reloaded if desired
				RESOURCE_UNLOADED = 2  
			};

			enum RESOURCE_TYPE
			{
				RESOURCE_TYPE_UNKNOWN = 0,

				RESOURCE_TYPE_TEXTURE,

				RESOURCE_TYPE_MESH,

				RESOURCE_TYPE_AUDIO,

				RESOURCE_TYPE_SCRIPT,

				RESOURCE_TYPE_MATERIAL
			};

		protected:
			// GUID of the resource
			PUInt32 m_GUID;

			// Name of the resource; is initially the same m_Path, but can be changed 
			PString m_ResourceName;

			// Path to the resource
			PString m_Path;

			// Current status of the resource
			RESOURCE_STATUS m_ResourceStatus;
			
			// Type of resource - the base class will always have an unknown resource type
			RESOURCE_TYPE m_ResourceType = RESOURCE_TYPE_UNKNOWN;
		
		public:
			
			PResource();

			PResource(RESOURCE_TYPE resourceType);

			RESOURCE_STATUS GetResourceStatus() const;
		};
	}
}

#endif