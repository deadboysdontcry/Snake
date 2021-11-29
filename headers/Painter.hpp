//
// Created by pe2ch on 11.11.21.
//

#ifndef UNTITLED22_HEADERS_PAINTER_HPP_
#define UNTITLED22_HEADERS_PAINTER_HPP_

#include <QWidget>
#include <QPainter>

#include "Apple.hpp"
#include "Snake.hpp"

class Painter {
 private:
  Snake &snake_;
  Apple &apple_;
 public:

  Painter(Snake &snake, Apple &apple);
  void DrawApple(QPainter &qp);
  void DrawSnake(QPainter &qp);
  void FillBackGround(QPainter &qp);
};

#endif //UNTITLED22_HEADERS_PAINTER_HPP_
