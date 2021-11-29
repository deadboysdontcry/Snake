#ifndef HEADERS_SNAKEWINDOW_HPP_
#define HEADERS_SNAKEWINDOW_HPP_


#include <QKeyEvent>
#include <QWidget>
#include <QLabel>
#include <string>
#include <fstream>

#include "../headers/Collisions.hpp"
#include "../headers/Painter.hpp"

class SnakeWindow : public QWidget {
 private:
  int last_time_;
  int cur_time_;
  Apple apple_;
  Snake snake_;
  Painter painter_;
  int timer_id;
  Collisions collisions_;
  const int DELAY = 165;
  Event event_;

  int record_ = 0;
 public:
  explicit SnakeWindow(QWidget *parent = nullptr);

 protected:
  void timerEvent(QTimerEvent *) override;
  void keyPressEvent(QKeyEvent *) override;
  void paintEvent(QPaintEvent *) override;
 private:
  void SetNewRecord();
  void GameOver(QPainter &qp);
};

#endif //HEADERS_SNAKEWINDOW_HPP_
