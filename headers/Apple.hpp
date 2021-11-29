#ifndef HEADERS_APPLE_HPP_
#define HEADERS_APPLE_HPP_

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

#endif //HEADERS_APPLE_HPP_
