#include "PSceneNode.h"

namespace PolygonEngine
{
	namespace Rendering
	{
		const PSceneNode* PSceneNode::GetParent() const
		{
			return m_Parent;
		}

		const PDynArray<PSceneNode*>& PSceneNode::GetChildren() const
		{
			return m_Children;
		}

		void PSceneNode::SetParent(PSceneNode* parent)
		{
			m_Parent = parent;
		}
	}
}