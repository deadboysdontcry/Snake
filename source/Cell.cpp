//
// Created by pe2ch on 10.11.21.
//

#include "../headers/Cell.hpp"

bool operator!=(const Cell &c1, const Cell &c2) {
  return (c1.y != c2.y || c2.x != c1.x);
}

bool operator==(const Cell &c1, const Cell &c2) {
  return !(c1 != c2);
}

bool operator<(const Cell &c1, const Cell &c2) {
  return std::tie(c1.x, c1.y) < std::tie(c2.x, c2.y);
}

std::size_t std::hash<Cell>::operator()(Cell const &cell) const noexcept {
  std::size_t h1 = std::hash<int>{}(cell.x);
  std::size_t h2 = std::hash<int>{}(cell.y);
  return h1 ^ (h2 << 1); // or use boost::hash_combine
}