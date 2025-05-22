#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GridCell.h"

class BFS
{
public:
	BFS(GridCell& t_startNode, GridCell& t_endNode, std::vector<GridCell>& t_grid);

	std::vector<GridCell*> GetPath() { return m_path; };
private:
	std::vector <GridCell*> findPath();

	bool indexIsValid(sf::Vector2i t_index) const;
	int getIndex(sf::Vector2i t_index) const;

private:
	GridCell& m_startNode;
	GridCell& m_endNode;
	std::vector<GridCell>& m_grid;
	std::vector<GridCell*> m_path;

	std::vector<sf::Vector2i> m_directions = {
	{1, 0},   // right
	{0, 1},   // down
	{-1, 0},  // left
	{0, -1}   // up
	};
};