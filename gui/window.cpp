#include "window.h"

Window::Window(QWidget *parent)
    : QWidget{parent}, layout(new QVBoxLayout(this)),
      formLayout(new QFormLayout), formWidget(new QWidget),
      edit1(new QLineEdit("3")), button1(new QPushButton("Hayah!")),
      button2(new QPushButton("Exit")) {

  setWindowTitle("Sudoku 4D");
  // form = new QFormLayout(this);

  formLayout->addRow(tr("Base:"), edit1);
  formWidget->setLayout(formLayout);
  edit1->setValidator(new QIntValidator(2, 5, this));

  layout->addWidget(formWidget);
  layout->addWidget(button1);
  layout->addWidget(button2);

  connect(button1, SIGNAL(clicked()), this, SLOT(startButtonPressed()));
  connect(button2, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

}

void Window::startButtonPressed(){
    bool ok;
    uint base = edit1->text().toUInt(&ok);
    if(ok && 2 <= base && base <= 5){
        hide();
        game = new GameWindow(base);
        game->show();
    }
    
}