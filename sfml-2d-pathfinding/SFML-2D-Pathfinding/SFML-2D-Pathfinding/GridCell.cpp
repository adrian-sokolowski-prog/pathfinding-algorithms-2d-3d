#include "GridCell.h"
#include "Globals.h"

GridCell::GridCell(sf::Color t_color, bool t_isWalkable, sf::Vector2f t_position)
	: m_isWalkable(t_isWalkable)
{
    sf::Vector2f centerPos = t_position + (Globals::CELL_SIZE / 2.f);
    m_cellOrigin = centerPos;

    m_cellShape.setPosition(centerPos);
    m_cellShape.setOrigin(Globals::CELL_SIZE / 2.f);

    m_cellShape.setSize(sf::Vector2f(Globals::CELL_SIZE));
    m_cellShape.setFillColor(t_color);
}

GridCell& GridCell::GetCell()
{
	return *this;
}

void GridCell::RenderCell(sf::RenderWindow& t_window) const
{
	t_window.draw(m_cellShape);
}

bool GridCell::IsWalkable() const
{
    return m_isWalkable;
}

sf::Vector2f GridCell::GetCellCenter() const
{
    return m_cellOrigin;
}

void GridCell::SetIfWalkable(bool t_isWalkable)
{
    m_isWalkable = t_isWalkable;
    if (m_isWalkable)
    {
	    m_cellShape.setFillColor(sf::Color::White);
    }
    else if(!m_isWalkable)
    {
        m_cellShape.setFillColor(sf::Color::Black);
	}
}

void GridCell::SetColor(sf::Color t_color)
{
	m_cellShape.setFillColor(t_color);
}
