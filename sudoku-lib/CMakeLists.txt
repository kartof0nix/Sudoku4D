add_library(sudoku-lib sudoku.cpp)
target_include_directories(sudoku-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)