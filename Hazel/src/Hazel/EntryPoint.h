#pragma once

#ifdef HZ_PLATFORM_WINDOWS // 定义平台

extern Hazel::Application* Hazel::CreateApplication();


int main(int argc, char** argv) {
	Hazel::Log::init();
	HZ_CORE_WARN("Init Log!");
	HZ_INFO("Hello!");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Hazel only support windows;
#endif
