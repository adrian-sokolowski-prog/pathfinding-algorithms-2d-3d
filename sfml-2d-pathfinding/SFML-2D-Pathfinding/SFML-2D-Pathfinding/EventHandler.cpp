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

void EventHandler::operator()(const sf::Event::KeyPressed& t_event)
{
	if (t_event.code == sf::Keyboard::Key::B)
	{
		m_grid.ChangeKeyboardMode(InputType::KeyboardPressMode::StartStop);
	}
	else if (t_event.code == sf::Keyboard::Key::W)
	{
		m_grid.ChangeKeyboardMode(InputType::KeyboardPressMode::Wall);
	}
	else if (t_event.code == sf::Keyboard::Key::G)
	{
		m_grid.StartBFSAlgorithm();
	}
}
