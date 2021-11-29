//
// Created by pe2ch on 10.11.21.
//

#pragma once
#include <queue>
#include <unordered_set>

#include "WindowConstants.hpp"
#include "../headers/Cell.hpp"

enum class Direction { kUp, kDown, kLeft, kRight };

class Snake {

 private:
  bool isGrowed = false;
  int snake_size_;
  std::queue<Cell> tail_;
  std::unordered_multiset<Cell> snake_cells_;
  Direction dir_;
 public:
  Snake();
  void Move();
  void SetDirection(Direction dir);
  const std::unordered_multiset<Cell> &GetSnakeCells() const;
  void Grow();
  std::size_t GetSize();
  [[nodiscard]] Cell GetFront() const;
  Direction GetDirection() const;
};
