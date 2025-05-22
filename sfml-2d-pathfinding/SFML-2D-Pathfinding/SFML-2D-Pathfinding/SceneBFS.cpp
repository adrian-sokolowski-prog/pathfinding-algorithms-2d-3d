#include "SceneBFS.h"
#include "EventHandler.h"

SceneBFS::SceneBFS()
{
	m_grid = Grid();
}

void SceneBFS::Update(const sf::Time t_deltaTime)
{
}

void SceneBFS::Render(sf::RenderWindow& t_window)
{
	m_grid.RenderGrid(t_window);
}

void SceneBFS::ProcessEvents(const std::optional<sf::Event> t_event, sf::RenderWindow& t_window)
{
	if(!t_event.has_value())
		return;

	EventHandler eventHandler = EventHandler(t_window, m_grid);
	t_event->visit(eventHandler);
	
}
