//
// Created by pe2ch on 11.11.21.
//
#include "../headers/Painter.hpp"

using namespace WindowConstants;

Painter::Painter(Snake &snake, Apple &apple) : apple_(apple), snake_(snake) {}

void Painter::DrawApple(QPainter &qp) {
  Cell cell = apple_.GetCell();
  qp.drawImage(cell.x * cell_size, cell.y * cell_size, APPLE_IMG);
}

void Painter::DrawSnake(QPainter &qp) {
  auto st = snake_.GetSnakeCells();
  auto head = snake_.GetFront();
  qp.drawImage(head.x * cell_size, head.y * cell_size, SNAKE_HEAD_IMG);
  for (const auto &item: st) {
    if (item != head)
      qp.drawImage(item.x * cell_size, item.y * cell_size, SNAKE_TAIL_IMG);
  }
}

void Painter::FillBackGround(QPainter &qp) {
  for (int i = 0; i < cells_x_cnt; i++) {
    for (int j = 0; j < cells_y_cnt; j++) {
      qp.drawImage(i * cell_size, j * cell_size, BACKGROUND_IMG);
    }
  }
}