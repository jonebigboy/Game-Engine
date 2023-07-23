#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory> //����ָ��

namespace Hazel {

	//��Ϊ��h�ļ����ҵ��˶��壬�����������﷢�֣�û���ҵ������ı�����
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
