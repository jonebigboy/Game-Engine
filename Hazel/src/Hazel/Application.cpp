#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 800);
		HZ_TRACE("Window Resize Event: width={0}, height={1}", e.GetWidth(), e.GetHeight());

		while (1) {


		};
	}

}

