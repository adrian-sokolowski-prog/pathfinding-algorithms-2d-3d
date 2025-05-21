#pragma once
#include <SFML/Graphics.hpp>

namespace Collision
{
	inline bool IsPointInRect(sf::Vector2i t_point, sf::IntRect t_rect){ return t_rect.contains(t_point); }

};