cmake_minimum_required(VERSION 3.16)
project(common-utils VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json CONFIG REQUIRED)

add_library(common_utils STATIC
    src/vector3.cpp
    src/matrix4x4.cpp
    src/logger.cpp
    src/config.cpp
)

# nlohmann_json is header-only. Instead of PUBLIC linking (which breaks export),
# we directly add its include directory.
target_include_directories(common_utils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
# For BUILD tree: add nlohmann_json include dir
get_target_property(_nlohmann_inc nlohmann_json INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(common_utils PUBLIC "${_nlohmann_inc}")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/common-utilsConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(TARGETS common_utils
    EXPORT common-utilsTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT common-utilsTargets
    FILE common-utilsTargets.cmake
    NAMESPACE common-utils::
    DESTINATION lib/cmake/common-utils
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/common-utilsConfigVersion.cmake"
    DESTINATION lib/cmake/common-utils
)

enable_testing()
add_subdirectory(tests)
