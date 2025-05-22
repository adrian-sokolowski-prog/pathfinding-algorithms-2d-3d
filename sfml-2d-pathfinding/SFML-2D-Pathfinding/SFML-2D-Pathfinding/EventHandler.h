#pragma once

#include <SFML/Graphics.hpp>

#include "Grid.h"

class EventHandler
{
public:
	EventHandler(sf::RenderWindow& t_window, Grid& t_grid) : m_window(t_window), m_grid(t_grid) {}

	void operator()(const sf::Event::MouseButtonPressed& t_event);

	void operator()(const sf::Event::KeyPressed& t_event);

	// Generic catch all for unused events
	template <typename T>
	void operator()(const T&) const {}

private:
	sf::RenderWindow& m_window;
	Grid& m_grid;
};