#include "../headers/Apple.hpp"

Apple::Apple() {
  SetNewApple();
}

void Apple::SetNewApple() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist_x(0, WindowConstants::cells_x_cnt - 1),
      dist_y(0, WindowConstants::cells_y_cnt - 1);
  cell_ = {dist_x(mt), dist_y(mt)};
}

Cell Apple::GetCell() const {
  return cell_;
}