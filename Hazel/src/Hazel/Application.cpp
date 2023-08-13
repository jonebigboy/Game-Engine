#include "hzpch.h"
#include "Application.h"
#include "Hazel/Events/Event.h"

#include <glad/glad.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Hazel {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));

	}

	void Application::OnEvent(Event& e)
	{

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) { 
			
			(*--it)->OnEvent(e);
			if(e.m_Handled)
				break;
		}

		HZ_CORE_INFO(e.ToString());
	}


	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverLayer(Layer* overlayer)
	{
		m_LayerStack.PushOverLayer(overlayer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		isRunning = false;
		return true;
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		//WindowResizeEvent e(1200, 800);
		//HZ_TRACE("Window Resize Event: width={0}, height={1}", e.GetWidth(), e.GetHeight());
		//HZ_TRACE(e.ToString());

		while (isRunning) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (auto layer : m_LayerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();

		};
	}


}

