#ifndef HEADERS_CELL_HPP_
#define HEADERS_CELL_HPP_

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

#endif //HEADERS_CELL_HPP_
