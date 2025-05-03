#include <atomic>
#include <cstddef>
#include <vector>

#include <oneapi/tbb/parallel_for.h>

#include "p_calculator.hpp"

namespace automata::game_of_life {

namespace executor {

////////////////////////////////////////////////////////////////////////////////////

void ParallelCalculator::Set(GameConfig *config) { config_ = config; }

void ParallelCalculator::CellProcessing(std::size_t thread_id, Cell cell,
                                        CellState is_alive) {
  std::size_t living_count = 0;

  for (const auto &[x_offset, y_offset] : config_->rule.neighbors) {
    Cell neighbor;

    if (config_->is_endless_board) {
      neighbor.x_coordinate = cell.x_coordinate + x_offset;
      neighbor.y_coordinate = cell.y_coordinate + y_offset;

    } else {
      neighbor.x_coordinate =
          (cell.x_coordinate + x_offset + config_->rows_count) %
          config_->rows_count;
      neighbor.y_coordinate =
          (cell.y_coordinate + y_offset + config_->columns_count) %
          config_->columns_count;
    }

    if (set_->contains(neighbor)) {
      ++living_count;
    }
  }

  if (config_->rule.WillCellSurvive(is_alive, living_count) ==
      CellState::alive) {
    split_responce_[thread_id].emplace(cell);
  }
}

void ParallelCalculator::Clear() {
  auto thread_count = thread_id_.load();

  for (std::size_t i = 0; i < thread_count; ++i) {
    split_responce_[i].clear();
  }

  thread_id_.store(0);
  result.clear();
}

void ParallelCalculator::Calc(SetCells *status_quo) {
  set_ = status_quo;

  //! Copy O(n)
  std::vector shared_data(set_->begin(), set_->end());

  tbb::parallel_for(
      tbb::blocked_range<size_t>(0, set_->size(), 1000),
      [&](const auto &range) {
        std::size_t thread_id = thread_id_.fetch_add(1);

        for (std::size_t iter = range.begin(); iter < range.end(); ++iter) {
          auto cell = shared_data[iter];

          CellProcessing(thread_id, cell, /*is_alive=*/CellState::alive);

          for (const auto &[x_offset, y_offset] : config_->rule.neighbors) {
            if (config_->is_endless_board) {
              CellProcessing(
                  /*thread_id=*/thread_id,
                  /*cell=*/
                  {cell.x_coordinate + x_offset, cell.y_coordinate + y_offset},
                  /*is_alive=*/CellState::dead);
            } else {
              CellProcessing(
                  /*thread_id=*/thread_id,
                  /*cell=*/
                  {(cell.x_coordinate + x_offset + config_->rows_count) %
                       config_->rows_count,
                   (cell.y_coordinate + y_offset + config_->columns_count) %
                       config_->columns_count},
                  /*is_alive=*/CellState::dead);
            }
          }
        }
      });

  //! O(n)
  auto thread_count = thread_id_.load();
  for (std::size_t i = 0; i < thread_count; ++i) {
    result.merge(std::move(split_responce_[i]));
  }
}

void ParallelCalculator::Update(SetCells *where) { *where = std::move(result); }

////////////////////////////////////////////////////////////////////////////////////

} // namespace executor

} // namespace automata::game_of_life
