#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace common_utils {

class Logger {
public:
    enum Level { DEBUG, INFO, WARN, ERROR };

    static void init(const std::string& name = "common_utils", Level level = DEBUG);
    static std::ostream& get(Level level = INFO);

private:
    static std::string s_name;
    static Level s_level;
    static std::string level_str(Level level);
};

inline std::string Logger::level_str(Level level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO:  return "INFO ";
        case WARN:  return "WARN ";
        case ERROR: return "ERROR";
        default:    return "UNKWN";
    }
}

inline void Logger::init(const std::string& name, Level level) {
    s_name = name;
    s_level = level;
}

inline std::ostream& Logger::get(Level level) {
    // Always output ERROR to cerr, WARN+ to cout
    if (level >= s_level) {
        auto& out = (level == ERROR) ? std::cerr : std::cout;
        out << "[" << level_str(level) << "] ";
        return out;
    }
    // Return a null stream that discards everything
    static std::ostream nullstream(nullptr);
    return nullstream;
}

} // namespace common_utils

#define CU_LOG_INFO(...)  ::common_utils::Logger::get(::common_utils::Logger::INFO) << __VA_ARGS__ << std::endl
#define CU_LOG_WARN(...)  ::common_utils::Logger::get(::common_utils::Logger::WARN) << __VA_ARGS__ << std::endl
#define CU_LOG_ERROR(...) ::common_utils::Logger::get(::common_utils::Logger::ERROR) << __VA_ARGS__ << std::endl
#define CU_LOG_DEBUG(...) ::common_utils::Logger::get(::common_utils::Logger::DEBUG) << __VA_ARGS__ << std::endl
