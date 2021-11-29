//
// Created by pe2ch on 10.11.21.
//

#ifndef UNTITLED22_HEADERS_CELL_HPP_
#define UNTITLED22_HEADERS_CELL_HPP_

#include <tuple>

struct Cell {
  int x, y;
};

bool operator!=(const Cell &c1, const Cell &c2);

bool operator==(const Cell &c1, const Cell &c2);

bool operator<(const Cell &c1, const Cell &c2);

template<>
struct std::hash<Cell> {
  std::size_t operator()(Cell const &cell) const noexcept;
};

#endif //UNTITLED22_HEADERS_CELL_HPP_
