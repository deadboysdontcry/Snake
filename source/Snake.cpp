//
// Created by pe2ch on 10.11.21.
//

#include "../headers/Snake.hpp"

Snake::Snake() {
  dir_ = Direction::kRight;
  snake_size_ = 3;
  int x = WindowConstants::cells_x_cnt / 2;
  int y = WindowConstants::cells_y_cnt / 2;
  tail_.push({x+2*WindowConstants::cell_size, y});
  tail_.push({x+WindowConstants::cell_size, y});
  tail_.push({x, y});


  Cell cur_cell = {x, y};
  snake_cells_.insert(cur_cell);
  snake_cells_.insert({x+WindowConstants::cell_size, y});
  snake_cells_.insert({x+ 2 * WindowConstants::cell_size, y});
}

std::size_t Snake::GetSize() {
  return snake_size_;
}

void Snake::Move() {
  Cell cur_cell = tail_.back();
  switch (dir_) {
    case Direction::kUp : {
      cur_cell.y--;
    }
      break;
    case Direction::kDown : {
      cur_cell.y++;
    }
      break;
    case Direction::kLeft : {
      cur_cell.x--;
    }
      break;
    case Direction::kRight : {
      cur_cell.x++;
    }
      break;
  }
  tail_.push(cur_cell);
  snake_cells_.insert(cur_cell);
  if (!isGrowed) {
    cur_cell = tail_.front();
    tail_.pop();
    snake_cells_.erase(snake_cells_.find(cur_cell));
  } else {
    isGrowed = false;
  }
}

void Snake::SetDirection(Direction dir) {
  dir_ = dir;
}

const std::unordered_multiset<Cell> &Snake::GetSnakeCells() const {
  return snake_cells_;
}

void Snake::Grow() {
  snake_size_++;
  isGrowed = true;
}

Cell Snake::GetFront() const {
  return tail_.back();
}

Direction Snake::GetDirection() const {
  return dir_;
}
