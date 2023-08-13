#pragma once

//define something

#ifdef HZ_PLATFORM_WINDOWS // 定义平台
	#ifdef HZ_BULID_DLL //定义使用的是输出DLL
		#define HAZEL_API __declspec(dllexport) 
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif

#else
	#error Hazel only support windows;
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) {if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<(x))
