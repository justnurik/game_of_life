#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

struct Button {
  sf::RectangleShape shape;
  sf::Text text;

  bool Clicked(const sf::Vector2f &);

  std::string ClickHandle();

  void ReleaseHandle();
};

struct Buttons {

  Buttons() { SetUp(); }

  std::vector<Button> buttons;
  float button_width;
  float button_margin_coeff;
  float button_height;
  float margin_top;
  float margin_left;
  float outline_thickness;
  size_t last_button_id;
  float margin;

  float text_margin_left;
  float text_margin_top;

  sf::Color font_color;
  size_t char_size;
  sf::Font font;

  void SetUp();

  void SetButton(const std::string &);

  void DrawButtons(sf::RenderWindow &);
};
