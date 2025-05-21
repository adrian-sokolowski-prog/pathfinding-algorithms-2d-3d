#pragma once
#include <SFML/Graphics.hpp>

namespace Globals
{
	inline constexpr int SCREEN_WIDTH = 1000;
	inline constexpr int SCREEN_HEIGHT = 800;

	inline constexpr sf::Vector2f CELL_SIZE = {20,20};
	inline constexpr sf::Vector2i CELL_AMOUNT = {50,40};
}