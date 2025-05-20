#include "Game.h"
#include <optional>

void Game::Run()
{
	SceneManager::Instance().MoveScene(std::make_unique<SceneBFS>());

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

    while (m_window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        processEvents();

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            update(timePerFrame);
        }

        render();
    }

}

void Game::update(sf::Time t_deltaTime)
{
	SceneManager::Instance().UpdateCurrentScene(t_deltaTime);
}

void Game::processEvents()
{
    while (const std::optional event = m_window.pollEvent())
    {
        SceneManager::Instance().ProcessCurrentSceneEvents(event, m_window);

        if (event->is<sf::Event::Closed>())
        {
            m_window.close();
        }
    }
}

void Game::render()
{
	m_window.clear();

	SceneManager::Instance().RenderCurrentScene(m_window);

	m_window.display();
}
