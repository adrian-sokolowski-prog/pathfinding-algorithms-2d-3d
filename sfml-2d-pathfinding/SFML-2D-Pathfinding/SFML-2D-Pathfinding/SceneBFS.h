#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Grid.h"

class SceneBFS : public Scene
{
public:
	SceneBFS();

	void Update(const sf::Time t_deltaTime) override;
	void Render(sf::RenderWindow& t_window) override;
	void ProcessEvents(const std::optional<sf::Event> t_event, sf::RenderWindow& t_window) override;
private:

private:
	Grid m_grid;
};
