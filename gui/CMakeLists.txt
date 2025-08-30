# GUI Compilation

find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)
qt_standard_project_setup()

qt_add_executable(sudoku-gui
main.cpp window.cpp game.cpp 
)


target_link_libraries(sudoku-gui PRIVATE sudoku-lib Qt6::Core Qt6::Widgets)
  