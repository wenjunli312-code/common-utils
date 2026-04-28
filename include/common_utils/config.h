#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <stdexcept>

namespace common_utils {

class Config {
public:
    // Load config from a JSON file path.
    explicit Config(const std::string& filepath);

    // Load config from a JSON string.
    static Config fromString(const std::string& json_str);

    // Returns true if the key exists (supports dot-notation: "section.key").
    bool has(const std::string& key) const;

    // Get value by key (supports dot-notation: "section.key").
    // Throws std::runtime_error if not found.
    template <typename T>
    T get(const std::string& key) const {
        return resolve(key).get<T>();
    }

    // Get value with a default fallback.
    template <typename T>
    T getOr(const std::string& key, T default_val) const {
        try {
            return resolve(key).get<T>();
        } catch (...) {
            return default_val;
        }
    }

    const nlohmann::json& raw() const { return data_; }

private:
    Config() = default;
    const nlohmann::json& resolve(const std::string& key) const;

    nlohmann::json data_;
};

} // namespace common_utils
