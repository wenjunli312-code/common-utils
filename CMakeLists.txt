cmake_minimum_required(VERSION 3.16)
project(common-utils VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)

add_library(common_utils STATIC
    src/vector3.cpp
    src/matrix4x4.cpp
    src/logger.cpp
    src/config.cpp
)

target_include_directories(common_utils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(common_utils
    PUBLIC
        spdlog::spdlog
        nlohmann_json::nlohmann_json
)

install(TARGETS common_utils
    EXPORT common_utils_targets
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/common_utils
    DESTINATION include
)

# Tests
enable_testing()
add_subdirectory(tests)
