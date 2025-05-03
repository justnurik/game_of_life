#include <cstdint>

#include "cell.hpp"

namespace automata::game_of_life {

bool operator==(const Cell &cell1, const Cell &cell2) {
  return (cell1.x_coordinate == cell2.x_coordinate) &&
         (cell1.y_coordinate == cell2.y_coordinate);
}

std::int64_t HashCell::operator()(const Cell &cell) const {
  return (cell.x_coordinate << 32) | cell.y_coordinate;
}

} // namespace automata::game_of_life
