cmake_minimum_required(VERSION 3.16)
project(common-utils VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch nlohmann_json (header-only) automatically
include(FetchContent)
if(NOT nlohmann_json_FOUND)
    FetchContent_Declare(
        nlohmann_json_source
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/nlohmann-json-3.11.3.tar.gz
        URL_HASH SHA256=4a09422990488e27f3c1e1d3f3a0e0c6d7f1e3f0c7b1a3c4e5f6a7b8c9d0e1f2
    )
    FetchContent_MakeAvailable(nlohmann_json_source)
endif()

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
        nlohmann_json::nlohmann_json
)

install(TARGETS common_utils
    EXPORT common_utils_targets
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/common_utils
    DESTINATION include
)

# CMake config for downstream find_package
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/common_utilsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/common-utilsConfig.cmake
    INSTALL_DESTINATION lib/cmake/common-utils
)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/common-utilsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/common-utilsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/common-utilsConfigVersion.cmake
    DESTINATION lib/cmake/common-utils
)
install(EXPORT common_utils_targets
    FILE common_utilsTargets.cmake
    NAMESPACE common_utils::
    DESTINATION lib/cmake/common-utils
)

# Tests
enable_testing()
add_subdirectory(tests)
