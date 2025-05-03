#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>

#include "../../data_presentation/game_config.hpp"
#include "icalculator.hpp"

namespace automata::game_of_life {

namespace executor {

// Set => Calculate => Take the result
// All calculations take place in one thread
class ParallelCalculator : public ICalculator {
public:
  /////////////////////////////////////////////////////

  // One-shot [or if the game configuration has changed]
  void Set(GameConfig *config) override;

  // Clear result
  void Clear() override;

  // Calc result
  void Calc(SetCells *status_quo) override;

  // Set result into [where]
  void Update(SetCells *where) override;

  /////////////////////////////////////////////////////

private:
  void CellProcessing(std::size_t thread_id, Cell cell, CellState is_alive);

  /////////////////////////////////////////////////////

private:
  SetCells *set_{nullptr};
  std::atomic_uint64_t thread_id_{0};

  // todo:
  static constexpr std::uint64_t max_thread_count_ = 1'000;
  std::array<SetCells, max_thread_count_> split_responce_;

  // Calculate result
  SetCells result;

  // Game config
  GameConfig *config_{nullptr};
};

} // namespace executor

} // namespace automata::game_of_life
