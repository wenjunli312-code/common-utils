get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)
include(CMakeFindDependencyMacro)
find_dependency(nlohmann_json REQUIRED)
if(NOT TARGET common-utils::common-utils)
  add_library(common-utils::common-utils INTERFACE IMPORTED)
  set_target_properties(common-utils::common-utils PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${PACKAGE_PREFIX_DIR}/include")
  target_link_libraries(common-utils::common-utils INTERFACE
    nlohmann_json
    "${PACKAGE_PREFIX_DIR}/lib/libcommon_utils.a")
endif()
