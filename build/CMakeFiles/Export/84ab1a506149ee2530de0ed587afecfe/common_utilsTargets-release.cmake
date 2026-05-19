#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "common_utils::common_utils" for configuration "release"
set_property(TARGET common_utils::common_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(common_utils::common_utils PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcommon_utils.a"
  )

list(APPEND _cmake_import_check_targets common_utils::common_utils )
list(APPEND _cmake_import_check_files_for_common_utils::common_utils "${_IMPORT_PREFIX}/lib/libcommon_utils.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
