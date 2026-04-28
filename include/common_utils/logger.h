#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <string>

namespace common_utils {

class Logger {
public:
    static void init(const std::string& name = "common_utils");
    static std::shared_ptr<spdlog::logger>& get();

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};

} // namespace common_utils

#define CU_LOG_INFO(...)  ::common_utils::Logger::get()->info(__VA_ARGS__)
#define CU_LOG_WARN(...)  ::common_utils::Logger::get()->warn(__VA_ARGS__)
#define CU_LOG_ERROR(...) ::common_utils::Logger::get()->error(__VA_ARGS__)
#define CU_LOG_DEBUG(...) ::common_utils::Logger::get()->debug(__VA_ARGS__)
