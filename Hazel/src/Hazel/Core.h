#pragma once

//define something

#ifdef HZ_PLATFORM_WINDOWS // ����ƽ̨
	#ifdef HZ_BULID_DLL //����ʹ�õ������DLL
		#define HAZEL_API __declspec(dllexport) 
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif

#else
	#error Hazel only support windows;
#endif

#define BIT(x) (1<<(x))
