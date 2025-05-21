#pragma once

#include <SFML/Graphics.hpp>
#include "GridCell.h"
#include "InputTypes.h"

class Grid
{
public:
	Grid();
	
	void RenderGrid(sf::RenderWindow& t_window);

	bool IsMouseOnGrid(sf::Vector2i t_mousePosition);
	void UpdateGridCell(sf::Vector2i t_mousePosition);

	void ChangeMouseMode(InputType::MouseClickMode t_mouseClickType) { m_mouseClickMode = t_mouseClickType; }
	void ChangeKeyboardMode(InputType::KeyboardPressMode t_keyboardPressType) { m_keyboardPressMode = t_keyboardPressType; }

private:
	sf::Vector2f createCellPosition(int t_row, int t_column);
	int getGridIndexFromMouse(sf::Vector2i t_mousePosition);
	int get1DGridIndexFrom2DIndex(int t_row, int t_column);
private:
	std::vector<GridCell> m_grid;

	InputType::MouseClickMode m_mouseClickMode = InputType::MouseClickMode::None;
	InputType::KeyboardPressMode m_keyboardPressMode = InputType::KeyboardPressMode::Wall;

};