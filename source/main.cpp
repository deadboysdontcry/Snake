#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QTime>

#include "../headers/SnakeWindow.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  SnakeWindow window;

  window.setWindowTitle("Snake");
  window.show();

  return app.exec();
}
