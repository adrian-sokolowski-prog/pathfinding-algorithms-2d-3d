#pragma once
#include <SFML/Graphics.hpp>

#include "SceneManager.h"
#include "SceneBFS.h"
#include "Globals.h"

class Game
{
public:
	Game() : m_window(sf::VideoMode({Globals::SCREEN_WIDTH,Globals::SCREEN_HEIGHT}), "SFML Pathfinding") {};
	~Game() {};

	void Run();

private:
	void update(sf::Time t_deltaTime);
	void processEvents();
	void render();

private:
	sf::RenderWindow m_window;
};