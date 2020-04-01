#ifndef POLYGON_SCENE_NODE_H
#define POLYGON_SCENE_NODE_H

#include "Core/Core.h"
#include "Core/PTypes.h"

namespace PolygonEngine
{
	namespace Rendering
	{
		class POLYGON_ENGINE_API PSceneNode
		{
		public:
			enum class Type
			{
				Base,
				Geometry,
				Transform
			};
		protected:
			
			PSceneNode* m_Parent = nullptr;
			PDynArray<PSceneNode*> m_Children;

			Type m_Type = Type::Base;

			// Checks to see whether any transformations applied to the parent node
			// is inherited. Default is true.
			bool m_ApplyParentTransformations = true;

		public:

			PSceneNode() = default;

			const PSceneNode* GetParent() const;

			const PDynArray<PSceneNode*>& GetChildren() const;

			void SetParent(PSceneNode* parent);

			template<typename ... Args>
			void CreateChild(Type type, Args&& ... args)
			{
				// TODO
			}
		};
	}
}

#endif