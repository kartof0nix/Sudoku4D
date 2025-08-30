#ifndef WINDOW_H
#define WINDOW_H

#include "game.h"
#include <QApplication>
#include <QFormLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <qtmetamacros.h>

class Window : public QWidget {
  Q_OBJECT
public:
  explicit Window(QWidget *parent = nullptr);

private:
  QVBoxLayout *layout;
  QFormLayout *formLayout;
  QWidget *formWidget;
  QLineEdit *edit1;
  QPushButton *button1;
  QPushButton *button2;
  GameWindow *game = nullptr;
signals:
private slots:
  void startButtonPressed();
};

#endif // WINDOW_H
