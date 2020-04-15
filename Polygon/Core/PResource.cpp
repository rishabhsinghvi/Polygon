#include "PResource.h"

namespace PolygonEngine
{
	namespace Core
	{
		PResource::PResource():
			m_ResourceType(RESOURCE_TYPE_UNKNOWN)
		{
		}

		PResource::PResource(RESOURCE_TYPE resourceType):
			m_ResourceType(resourceType)
		{
		}

		PResource::RESOURCE_STATUS PResource::GetResourceStatus() const
		{
			return m_ResourceStatus;
		}


	}
}
