set(TEST_NAME ${PROJECT_NAME}_AllTests)

file(GLOB_RECURSE TEST_SOURCE_FILES LIST_DIRECTORIES false *.test.cpp)
file(GLOB_RECURSE SOURCE_FILES LIST_DIRECTORIES false ../src/*.cpp)
#list(FILTER SOURCE_FILES EXCLUDE REGEX "../src/main.cpp")

add_executable(${TEST_NAME} ${TEST_SOURCE_FILES} ${SOURCE_FILES})
add_test(NAME ${TEST_NAME}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND ${TEST_NAME} -d yes --order lex
) # for ctest
add_definitions(-DGTEST_LANGUAGE_CXX11) # for gtest

## Compiler options
include(../cmake/CompilerOptions.cmake)
set_compiler_options(${TEST_NAME})

## Find third-party packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_BINARY_DIR})

find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

target_link_libraries(${TEST_NAME}
  PRIVATE pthread
  PRIVATE ${fmt_LIBRARIES}
  PRIVATE ${GTest_LIBRARIES}
)
target_include_directories(${TEST_NAME}
  PRIVATE ../include
  SYSTEM PRIVATE ${GTest_INCLUDES}
)
