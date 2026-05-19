# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/src/src/common-utils/build/_deps/nlohmann_json_source-src")
  file(MAKE_DIRECTORY "/src/src/common-utils/build/_deps/nlohmann_json_source-src")
endif()
file(MAKE_DIRECTORY
  "/src/src/common-utils/build/_deps/nlohmann_json_source-build"
  "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix"
  "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix/tmp"
  "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix/src/nlohmann_json_source-populate-stamp"
  "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix/src"
  "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix/src/nlohmann_json_source-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix/src/nlohmann_json_source-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/src/src/common-utils/build/_deps/nlohmann_json_source-subbuild/nlohmann_json_source-populate-prefix/src/nlohmann_json_source-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
