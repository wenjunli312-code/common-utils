#include "common_utils/config.h"

#include <fstream>
#include <sstream>

namespace common_utils {

Config::Config(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Cannot open config file: " + filepath);
    file >> data_;
}

Config Config::fromString(const std::string& json_str) {
    Config cfg;
    cfg.data_ = nlohmann::json::parse(json_str);
    return cfg;
}

bool Config::has(const std::string& key) const {
    try {
        resolve(key);
        return true;
    } catch (...) {
        return false;
    }
}

const nlohmann::json& Config::resolve(const std::string& key) const {
    const nlohmann::json* node = &data_;
    std::string segment;
    std::istringstream ss(key);
    while (std::getline(ss, segment, '.')) {
        if (!node->is_object() || !node->contains(segment))
            throw std::runtime_error("Config key not found: " + key);
        node = &(*node)[segment];
    }
    return *node;
}

} // namespace common_utils
