#pragma once
#include <SFML/Graphics.hpp>

class GridCell
{
public:
	GridCell() = default;
	GridCell(sf::Color t_color, bool t_isWalkable, sf::Vector2f t_position);

	GridCell& GetCell();

	void RenderCell(sf::RenderWindow& t_window) const;

	bool IsWalkable() const;
	sf::Vector2f GetCellCenter() const;

	void SetIfWalkable(bool t_isWalkable);
	void SetColor(sf::Color t_color);


private:
	sf::RectangleShape m_cellShape;
	sf::Vector2f m_cellOrigin;
	
	bool m_isWalkable;
};