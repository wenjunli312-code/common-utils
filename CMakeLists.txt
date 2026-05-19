cmake_minimum_required(VERSION 3.16)
project(common-utils VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# nlohmann_json is a header-only third-party library
# Found via CMAKE_PREFIX_PATH pointing to third_party/{platform}/nlohmann_json/
find_package(nlohmann_json CONFIG REQUIRED)

add_library(common_utils STATIC
    src/vector3.cpp
    src/matrix4x4.cpp
    src/logger.cpp
    src/config.cpp
)

target_link_libraries(common_utils PUBLIC nlohmann_json)

target_include_directories(common_utils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS common_utils
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
