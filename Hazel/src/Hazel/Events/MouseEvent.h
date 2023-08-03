#pragma once

#include "Event.h"
#include <sstream>

namespace Hazel {

	class HAZEL_API MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(int x, int y)
			:m_MouseX(x), m_MouseY(y) {}
		inline int GetX() const { return m_MouseX; };
		inline int GetY() const { return m_MouseY; };

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class HAZEL_API MouseButtonEvent : public Event {
	public:
		inline int GetButtonCode() const { return m_ButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int buttoncode)
			:m_ButtonCode(buttoncode) {}

		int m_ButtonCode;
	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int buttoncode)
			:MouseButtonEvent(buttoncode){}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_ButtonCode;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed)

		class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
		{
		public:
			MouseButtonReleasedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_ButtonCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
		};
	
	};





}