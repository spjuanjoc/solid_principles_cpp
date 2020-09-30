cmake_minimum_required(VERSION 3.15)

project(solid_principles_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Options
option(ENABLE_PCH         "Enable Precompiled Headers" FALSE)
option(ENABLE_TESTS       "Enable tests" FALSE)
option(ENABLE_CONAN       "Enable Conan" FALSE)
option(ENABLE_WARN_AS_ERR "Treat compiler warnings as errors" FALSE)
option(ENABLE_COVERAGE    "Enable gcov coverage" FALSE)

# standard compiler warnings
set(GCC_OPTIONS
    -Wall
    )

if(ENABLE_WARN_AS_ERR)
  set(GCC_OPTIONS ${GCC_OPTIONS} -Werror)
endif()

# Compiler
if(MSVC)
  set(PROJECT_OPTIONS ${MSVC_WARNINGS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  set(PROJECT_OPTIONS ${CLANG_WARNINGS})
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(ENABLE_COVERAGE)
    message("Using gcov")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage ")
  endif()

  set(GCC_OPTIONS ${GCC_OPTIONS}
      -O0
      -g
  )
  set(PROJECT_OPTIONS ${GCC_OPTIONS})
else()
  message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
endif()

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

# ---
# target instructions must be set after add_executable or add_library instructions

target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})

# target_compile_features(starter_cpp PRIVATE cxx_lambda_init_captures)

# Get the headers
set(INCLUDES include)
include_directories(PUBLIC ${INCLUDES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})

# Custom Options
if(ENABLE_PCH)
  # Since CMake 3.15
  set(PC_HEADERS <vector> <string> <map> <utility> <algorithm> <cctype> <ostream> <memory> <sstream>)
  if (ENABLE_CONAN)
    set(PC_HEADERS ${PC_HEADERS} <gtest/gtest.h>)
  endif()

  target_precompile_headers(${PROJECT_NAME} INTERFACE ${PC_HEADERS})
  message("Pre compiled headers enabled")
endif()

if(ENABLE_TESTS)
  enable_testing()
  add_subdirectory(test)
elseif()
  message("Tests not included")
endif()

if (ENABLE_CONAN)
  #    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  #    conan_basic_setup(TARGETS)
  #    conan_target_link_libraries(${PROJECT_NAME}
  #        CONAN_PKG::boost_signals2
  #        )
  #  message("Libs ${CONAN_LIBS}" )
  #  message("Dir ${CMAKE_BINARY_DIR}")
endif ()
