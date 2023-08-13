#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/LayerStack.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();

		~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* overlayer);
	private:

		bool OnWindowClose(WindowCloseEvent& e);

		bool isRunning = true;

		std::unique_ptr<Window> m_Window;

		LayerStack m_LayerStack;

	};
	//在客户端中定义
	Application* CreateApplication();
}



