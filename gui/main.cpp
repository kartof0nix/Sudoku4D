#include <QApplication>
// #include "slider.h"
#include "window.h"
#include <iostream>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    uint base = 3;
    Window window;
    window.show();
    
    int return_code = app.exec();

    std::cout << "Base " << base << '\n';
    return return_code;
}