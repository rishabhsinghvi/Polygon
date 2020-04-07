#ifndef POLYGON_CORE_EVENT_H
#define POLYGON_CORE_EVENT_H


namespace PolygonEngine
{
	namespace Core
	{
		struct PEvent
		{
			enum class Category
			{
				None,
				Application
			};

			enum class Type
			{
				None = 0,
				
				// Window Events
				WindowCloseEvent,
				
				// Keyboard Events
				KeyPressedEvent,
				KeyReleasedEvent,
				
				// Mouse Events
				MousePressedEvent,
				MouseReleasedEvent,
				MouseScrollEvent,
				MouseMovedEvent,
				
				// User-defined event 
				UserDefinedEvent
			};

		protected:

			Type m_Type = Type::None;
			Category m_Category = Category::Application;

		public:

			PEvent(Type type, Category category):
				m_Type(type), m_Category(category)
			{}

			inline Type GetType() const
			{
				return m_Type;
			}

			inline Category GetCategory() const
			{
				return m_Category;
			}
		};
	}
}


#define EVENT(x, y) PEvent(PEvent::Type::##x, PEvent::Category::##y)

#endif // POLYGON_CORE_EVENT_H