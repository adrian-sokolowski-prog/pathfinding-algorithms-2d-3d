#include "Grid.h"
#include "Globals.h"
#include "Collision.h"
#include "BFS.h"

Grid::Grid()
{
	// Row Major Order ( column (x), row (y) )
	for (int y = 0; y < Globals::CELL_AMOUNT.y; ++y)
	{
		for (int x = 0; x < Globals::CELL_AMOUNT.x; ++x)
		{
			m_grid.emplace_back(GridCell(sf::Color::White,true,createCellPosition(x, y),sf::Vector2i{x,y}));
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
		switch (m_mouseClickMode)
		{
		case InputType::MouseClickMode::Left:
			m_grid[getGridIndexFromMouse(t_mousePosition)].SetIfWalkable(true);
			m_grid[getGridIndexFromMouse(t_mousePosition)].SetColor(sf::Color::Red);
			m_startCell = &m_grid[getGridIndexFromMouse(t_mousePosition)];
			break;
		case InputType::MouseClickMode::Right:
			m_grid[getGridIndexFromMouse(t_mousePosition)].SetIfWalkable(true);
			m_grid[getGridIndexFromMouse(t_mousePosition)].SetColor(sf::Color::Magenta);
			m_endCell = &m_grid[getGridIndexFromMouse(t_mousePosition)];
			break;
		case InputType::MouseClickMode::None:
			break;
		}
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

void Grid::StartBFSAlgorithm()
{
	BFS bfs(*m_startCell, *m_endCell,m_grid);

	std::vector<GridCell*> path = bfs.GetPath();
	for (GridCell* cell : path)
	{
		cell->SetColor(sf::Color::Green);
	}
}

sf::Vector2f Grid::createCellPosition(int t_x, int t_y)
{
	sf::Vector2f nextCellPosition = sf::Vector2f(t_x * Globals::CELL_SIZE.x, t_y * Globals::CELL_SIZE.y);
	return nextCellPosition;
}

int Grid::getGridIndexFromMouse(sf::Vector2i t_mousePosition)
{
	int gridCellX = t_mousePosition.x / Globals::CELL_SIZE.x;
	int gridCellY = t_mousePosition.y / Globals::CELL_SIZE.y;
	return get1DGridIndexFrom2DIndex(gridCellX, gridCellY);
}

int Grid::get1DGridIndexFrom2DIndex(int t_x, int t_y)
{
	// Multiply rows by column amount and add column index to get 1d Index
	return (t_y * Globals::CELL_AMOUNT.x) + t_x;
}
