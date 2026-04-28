#include "common_utils/config.h"
#include <cassert>
#include <string>

using common_utils::Config;

int main() {
    auto cfg = Config::fromString(R"({
        "app": {
            "name": "demo",
            "version": 2
        },
        "debug": true
    })");

    assert(cfg.has("app.name"));
    assert(cfg.get<std::string>("app.name") == "demo");
    assert(cfg.get<int>("app.version") == 2);
    assert(cfg.get<bool>("debug") == true);
    assert(!cfg.has("nonexistent"));
    assert(cfg.getOr<std::string>("missing", "default") == "default");

    return 0;
}
