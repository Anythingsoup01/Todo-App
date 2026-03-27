#pragma once

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace Todo {
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetAPILogger() { return s_APILogger; }
		inline static Ref<spdlog::logger>& GetCLILogger() { return s_CLILogger; }
	private:
		inline static Ref<spdlog::logger> s_APILogger;
		inline static Ref<spdlog::logger> s_CLILogger;
	};
}


#ifdef TD_DEBUG

// Core Log Macros
#define TD_API_CRITICAL(...)             ::Todo::Log::GetAPILogger()->critical(__VA_ARGS__)
#define TD_API_ERROR(...)                ::Todo::Log::GetAPILogger()->error(__VA_ARGS__)
#define TD_API_WARN(...)                 ::Todo::Log::GetAPILogger()->warn(__VA_ARGS__)
#define TD_API_INFO(...)                 ::Todo::Log::GetAPILogger()->info(__VA_ARGS__)
#define TD_API_TRACE(...)                ::Todo::Log::GetAPILogger()->trace(__VA_ARGS__)

// Client Log Macros
#define TD_CLI_CRITICAL(...)             ::Todo::Log::GetCLILogger()->critical(__VA_ARGS__)
#define TD_CLI_ERROR(...)                ::Todo::Log::GetCLILogger()->error(__VA_ARGS__)
#define TD_CLI_WARN(...)                 ::Todo::Log::GetCLILogger()->warn(__VA_ARGS__)
#define TD_CLI_INFO(...)                 ::Todo::Log::GetCLILogger()->info(__VA_ARGS__)
#define TD_CLI_TRACE(...)                ::Todo::Log::GetCLILogger()->trace(__VA_ARGS__)
#elif TD_RELEASE || TD_DIST
// Core Log Macros
#define TD_API_CRITICAL(...)
#define TD_API_ERROR(...)
#define TD_API_WARN(...)
#define TD_API_INFO(...)
#define TD_API_TRACE(...)

// Client Log Macros
#define TD_CLI_CRITICAL(...)             ::Todo::Log::GetCLILogger()->critical(__VA_ARGS__)
#define TD_CLI_ERROR(...)                ::Todo::Log::GetCLILogger()->error(__VA_ARGS__)
#define TD_CLI_WARN(...)                 ::Todo::Log::GetCLILogger()->warn(__VA_ARGS__)
#define TD_CLI_INFO(...)                 ::Todo::Log::GetCLILogger()->info(__VA_ARGS__)
#define TD_CLI_TRACE(...)                ::Todo::Log::GetCLILogger()->trace(__VA_ARGS__)

#endif // TD_DEBUG

