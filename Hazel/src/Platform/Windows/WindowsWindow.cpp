#include "hzpch.h"
#include "WindowsWindow.h"

#include "Hazel\Events\ApplicationEvent.h"
#include "Hazel\Events\KeyEvent.h"
#include "Hazel\Events\MouseEvent.h"

#include <glad\glad.h>


namespace Hazel {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props /* = WindowProps() */) {
		return new WindowsWindow(props);
	}

	Hazel::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	Hazel::WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void Hazel::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();


		glfwSwapBuffers(m_Windows);
	}

	void Hazel::WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) {
			glfwSwapInterval(1);
		}else {
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool Hazel::WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void Hazel::WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		HZ_CORE_INFO("Create window {0} {1} {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {

			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Already init GLFW");
			s_GLFWInitialized = true;

		}
		m_Windows = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Windows); //上下文调用opengl
		
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
		
		glfwSetWindowUserPointer(m_Windows, &m_Data); //用于回调

		SetVSync(true);
		//Set GLFW CallBack
		glfwSetWindowSizeCallback(m_Windows, [](GLFWwindow* window, int width, int height) {
			WindowsDate& data=  *(WindowsDate*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			WindowResizeEvent event(width, height);
			data.EventCallBack(event);
		});

		glfwSetWindowCloseCallback(m_Windows, [](GLFWwindow* window) {
			WindowsDate& data = *(WindowsDate*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallBack(event);
		});

		glfwSetKeyCallback(m_Windows, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowsDate& data = *(WindowsDate*)glfwGetWindowUserPointer(window);

			switch (action)
			{

			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallBack(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallBack(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallBack(event);
				break;
			}
			}
		});

		glfwSetMouseButtonCallback(m_Windows, [](GLFWwindow* window, int button, int action, int mods) {
			WindowsDate& data = *(WindowsDate*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallBack(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallBack(event);
				break;
			}
			}

		});

		glfwSetScrollCallback(m_Windows, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowsDate& data = *(WindowsDate*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
			data.EventCallBack(event);

		});

		glfwSetCursorPosCallback(m_Windows, [](GLFWwindow* window, double xpos, double ypos) {
			WindowsDate& data = *(WindowsDate*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((int)xpos, (int)ypos);
			data.EventCallBack(event);
		});

	}

	void Hazel::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Windows);
	}

}

