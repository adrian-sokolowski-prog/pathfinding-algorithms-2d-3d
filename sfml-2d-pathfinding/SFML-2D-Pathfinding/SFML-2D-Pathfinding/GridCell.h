#pragma once
#include <SFML/Graphics.hpp>

class GridCell
{
public:
	GridCell() = default;
	GridCell(sf::Color t_color, bool t_isWalkable, sf::Vector2f t_position, sf::Vector2i t_index);

	void RenderCell(sf::RenderWindow& t_window) const;

	bool IsWalkable() const;
	sf::Vector2f GetCellCenter() const;

	void SetIfWalkable(bool t_isWalkable);
	void SetColor(sf::Color t_color);

public:
	const sf::Vector2i m_index = sf::Vector2i(0, 0);
private:
	sf::RectangleShape m_cellShape;
	sf::Vector2f m_cellOrigin;
	
	bool m_isWalkable;
};