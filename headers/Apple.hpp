//
// Created by pe2ch on 10.11.21.
//
#pragma once

#include <ctime>
#include <random>
#include <functional>
#include <QImage>

#include "../headers//WindowConstants.hpp"
#include "../headers/Cell.hpp"

class Apple {
 private:
  Cell cell_;
 public:
  Apple();
  [[nodiscard]] Cell GetCell() const;
  void SetNewApple();

};
