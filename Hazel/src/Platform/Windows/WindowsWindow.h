#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel {

	
	class WindowsWindow :public Window {

	public:

		WindowsWindow(const WindowProps& props);

		virtual ~WindowsWindow();
		
		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Data.Width; }
		virtual inline unsigned int GetHeight() const override { return m_Data.Height; }

		virtual inline  void SetEventCallBack(const EventCallBackFn& callback) override { m_Data.EventCallBack = callback; }
		virtual void SetVSync(bool enabled);
		virtual bool IsVSync() const;

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:
		GLFWwindow* m_Windows;

		struct WindowsDate {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			EventCallBackFn EventCallBack;
		};

		WindowsDate m_Data;
	};


}
