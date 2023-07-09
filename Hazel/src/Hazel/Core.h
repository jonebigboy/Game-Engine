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
