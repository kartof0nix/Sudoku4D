cmake_minimum_required(VERSION 3.16)

project(sudoku VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(DEBUG "Enable debugging" OFF)
option(BUILD_GUI "Build GUI application" ON)


# Compile options
if (DEBUG)
add_compile_options(-g -fsanitize=address -fsanitize=undefined)
add_link_options(-fsanitize=address -fsanitize=undefined)
endif()
add_compile_options(-Wall -Wextra -Wpedantic -Wunused -Werror)


add_subdirectory(sudoku-lib)



## Testing

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  sudoku-tests
  test/sudoku-lib.cpp
)
target_link_libraries(sudoku-tests gtest_main sudoku-lib)
include(GoogleTest)

gtest_discover_tests(sudoku-tests)

