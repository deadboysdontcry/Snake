#include "../headers/Collisions.hpp"

Collisions::Collisions(Snake &snake, Apple &apple) : snake_(snake), apple_(apple) {}

Event Collisions::CheckCollisions() {
  Cell front = snake_.GetFront();
  if (front.x == -1 || front.y == -1 || front.x == WindowConstants::cells_x_cnt ||
      front.y == WindowConstants::cells_y_cnt || ToHerSelf()) {
    return Event::kLose;
  } else {
    if (front.x == apple_.GetCell().x && front.y == apple_.GetCell().y) {
      return Event::kGrow;
    } else return Event::kMove;
  }
}

bool Collisions::ToHerSelf() const {
  auto t = snake_.GetSnakeCells();
  if (t.count(snake_.GetFront()) > 1)
    return true;
  return false;
}
