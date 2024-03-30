cmake_minimum_required(VERSION 3.15)

project(solid_principles_cpp
  VERSION "0.2.2"
  DESCRIPTION "SOLID principles in C++"
  LANGUAGES CXX
)


# Options
option(ENABLE_COVERAGE    "Enable gcov coverage"              False)
option(ENABLE_PCH         "Enable Precompiled Headers"        False)
option(ENABLE_TESTS       "Enable tests"                      False)
option(ENABLE_WARN_AS_ERR "Treat compiler warnings as errors" False)


# GLOB source files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
# Exclude main.cpp since it's a library
#list(FILTER SOURCE_FILES EXCLUDE REGEX "src/main.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})


## Compiler options
include(cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})

## Setup Conan < 2.0
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD
    "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake"
  )
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_autodetect(settings)
conan_check(REQUIRED)
conan_cmake_run(CONANFILE conanfile.txt
  BASIC_SETUP NO_OUTPUT_DIRS
  BUILD missing
  SETTINGS ${settings}
)

## Find third-party packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_BINARY_DIR})
find_package(fmt REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE ${fmt_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE include)


## Check custom options
if(ENABLE_PCH) # Since CMake 3.15
  set(PC_HEADERS <vector> <string> <map> <utility> <algorithm> <cctype> <ostream> <memory> <sstream> <gtest/gtest.h>)
  target_precompile_headers(${PROJECT_NAME} INTERFACE ${PC_HEADERS})
  message("Pre compiled headers enabled")
endif()

if (ENABLE_TESTS)
  message(STATUS "Tests enabled")
  enable_testing() # Must be placed before add_subdirectory
  add_subdirectory(test)
endif ()


## Install commands
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION "/opt/${PROJECT_NAME}"
)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Juan Jose Castellanos <juancho.312@hotmail.com>")
include(CPack)
