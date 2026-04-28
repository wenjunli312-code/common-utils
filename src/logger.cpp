#include "common_utils/logger.h"

namespace common_utils {

std::shared_ptr<spdlog::logger> Logger::s_logger;

void Logger::init(const std::string& name) {
    s_logger = spdlog::stdout_color_mt(name);
    s_logger->set_level(spdlog::level::debug);
    s_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^%l%$] %v");
}

std::shared_ptr<spdlog::logger>& Logger::get() {
    if (!s_logger) {
        init();
    }
    return s_logger;
}

} // namespace common_utils
