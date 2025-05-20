#pragma once
#include "SFML/Graphics.hpp"

class Scene
{
public:
	virtual void Update(const sf::Time t_deltaTime) = 0;
	virtual void Render(sf::RenderWindow& t_window) = 0;
	virtual void ProcessEvents(const std::optional<sf::Event> t_event, sf::RenderWindow& t_window) = 0;
};