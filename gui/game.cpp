#include "game.h"
#include <qwidget.h>
GameWindow::GameWindow(uint base, QWidget *parent)
    : QWidget(parent), label(new QLabel(QString::number(base), this)), game(base) {}