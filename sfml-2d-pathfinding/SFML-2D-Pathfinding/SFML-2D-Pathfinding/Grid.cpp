#include "Grid.h"
#include "Globals.h"
#include "Collision.h"

Grid::Grid()
{
	// Row Major Order ( column (x), row (y) )
	for (int row = 0; row < Globals::CELL_AMOUNT.y; ++row)
	{
		for (int column = 0; column < Globals::CELL_AMOUNT.x; ++column)
		{
			m_grid.emplace_back(GridCell(sf::Color::White,true,createCellPosition(column, row)));
		}
	}
}

void Grid::RenderGrid(sf::RenderWindow& t_window)
{
	for (const GridCell& cell : m_grid)
	{
		cell.RenderCell(t_window);
	}
}

bool Grid::IsMouseOnGrid(sf::Vector2i t_mousePosition)
{
	int gridWidth = Globals::CELL_AMOUNT.x * Globals::CELL_SIZE.x;
	int gridHeight = Globals::CELL_AMOUNT.y * Globals::CELL_SIZE.y;

	sf::IntRect gridBounds(sf::Vector2i{ 0, 0 }, sf::Vector2i{ gridWidth, gridHeight });

	return Collision::IsPointInRect(t_mousePosition, gridBounds);
}

void Grid::UpdateGridCell(sf::Vector2i t_mousePosition)
{
	switch (m_keyboardPressMode)
	{
	case InputType::KeyboardPressMode::StartStop:
		break;
	case InputType::KeyboardPressMode::Wall:
		switch (m_mouseClickMode)
		{
			case InputType::MouseClickMode::Left:
				m_grid[getGridIndexFromMouse(t_mousePosition)].SetIfWalkable(false);
				break;
			case InputType::MouseClickMode::Right:
				m_grid[getGridIndexFromMouse(t_mousePosition)].SetIfWalkable(true);
				break;
			case InputType::MouseClickMode::None:
				break;
		}
		break;
	case InputType::KeyboardPressMode::None:
		break;
	}
}

sf::Vector2f Grid::createCellPosition(int t_column, int t_row)
{
	sf::Vector2f nextCellPosition = sf::Vector2f(t_column * Globals::CELL_SIZE.x, t_row * Globals::CELL_SIZE.y);
	return nextCellPosition;
}

int Grid::getGridIndexFromMouse(sf::Vector2i t_mousePosition)
{
	int gridCellX = t_mousePosition.x / Globals::CELL_SIZE.x;
	int gridCellY = t_mousePosition.y / Globals::CELL_SIZE.y;
	return get1DGridIndexFrom2DIndex(gridCellX, gridCellY);
}

int Grid::get1DGridIndexFrom2DIndex(int t_column, int t_row)
{
	return (t_row * Globals::CELL_AMOUNT.x) + t_column;
}
