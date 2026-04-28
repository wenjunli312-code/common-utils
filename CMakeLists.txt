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
