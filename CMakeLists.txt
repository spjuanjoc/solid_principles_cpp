cmake_minimum_required(VERSION 3.15)

project(solid_principles_cpp VERSION 0.0.1 LANGUAGES CXX)

# Options
option(ENABLE_PCH         "Enable Precompiled Headers" False)
option(ENABLE_TESTS       "Enable tests" False)
option(ENABLE_COVERAGE    "Enable gcov coverage" False)
option(ENABLE_WARN_AS_ERR "Treat compiler warnings as errors" False)

set(SOURCES
    src/SRP/Journal.cpp
    src/OCP/Specification.cpp
    src/OCP/Filter.cpp
    src/LSP/Rectangle.cpp
    src/ISP/Printer.cpp
    src/ISP/Scanner.cpp
    src/ISP/Fax.cpp
    src/ISP/Document.cpp
    src/ISP/Machine.cpp
    src/DIP/Reporting/Reporting.cpp
    src/DIP/Logger/ConsoleLogger.cpp
    src/DIP/Car/Engine.cpp
    src/DIP/Car/Car.cpp
    src/main.cpp
)

# todo change to be a lib
#add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_executable(${PROJECT_NAME} ${SOURCES})

## Compiler options
include(cmake/CompilerOptions.cmake)
set_project_options(${PROJECT_NAME})

## Setup Conan
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
      "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP #[[BUILD missing]])

## Find third-party packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
find_package(fmt REQUIRED)

## conan_cmake_run https://github.com/selassje/eyeTracker/blob/master/CMakeLists.txt
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE include)
#target_sources(${PROJECT_NAME} ${SOURCES})

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
