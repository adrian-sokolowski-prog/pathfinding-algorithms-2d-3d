#pragma once
#include <SFML/Graphics.hpp>

#include "SceneManager.h"
#include "SceneBFS.h"

class Game
{
public:
	Game() : m_window(sf::VideoMode({800,600}), "SFML Pathfinding") {};
	~Game() {};

	void Run();

private:
	void update(sf::Time t_deltaTime);
	void processEvents();
	void render();

private:
	sf::RenderWindow m_window;
};