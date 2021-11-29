#ifndef HEADERS_COLLISIONS_HPP_
#define HEADERS_COLLISIONS_HPP_

#include <iostream>

#include "Apple.hpp"
#include "Snake.hpp"
#include "../headers/Cell.hpp"

enum class Event { kMove, kGrow, kLose, kNothing };

class Collisions {
 private:
  Apple &apple_;
  Snake &snake_;
 public:

  Collisions() = delete;
  explicit Collisions(Snake &snake, Apple &apple);
  Event CheckCollisions();
 private:
  [[nodiscard]] bool ToHerSelf() const;
};

#endif //HEADERS_COLLISIONS_HPP_
