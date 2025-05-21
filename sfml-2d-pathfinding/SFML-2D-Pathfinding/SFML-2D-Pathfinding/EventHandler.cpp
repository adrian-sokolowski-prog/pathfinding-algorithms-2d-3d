#include "EventHandler.h"
#include "InputTypes.h"

void EventHandler::operator()(const sf::Event::MouseButtonPressed& t_event)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

	if (t_event.button == sf::Mouse::Button::Left)
	{
		if (m_grid.IsMouseOnGrid(mousePos))
		{
			m_grid.ChangeMouseMode(InputType::MouseClickMode::Left);
			m_grid.UpdateGridCell(mousePos);
		}
	}
	else if( t_event.button == sf::Mouse::Button::Right)
	{
		if (m_grid.IsMouseOnGrid(mousePos))
		{
			m_grid.ChangeMouseMode(InputType::MouseClickMode::Right);
			m_grid.UpdateGridCell(mousePos);
		}
	}
}
