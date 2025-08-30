#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QIntValidator>
#include <qlabel.h>
#include <qtmetamacros.h>
#include "sudoku.hpp"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(uint base, QWidget *parent = nullptr);
private:
    QLabel *label;
    sudokuGame game;
    QTableWidget table;

signals:
};

#endif // GAME_H
