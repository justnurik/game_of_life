#pragma once

namespace automata::game_of_life {

namespace rule {

// Use: GameRule{automata::GameTemplate::Dafault}
// GameTemplate implicit conversion GameRule
enum class GameTemplate {
  Default,  // game of life
  Umbrellas,
  BlinkingDiamonds,
  Snowflake,
  SquareWaves,
  FlashingSquares,
  Lol,
};

}  // namespace rule

}  // namespace automata::game_of_life
