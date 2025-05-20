#pragma once

#include "Scene.h"

class SceneManager
{
public:
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	};

	void MoveScene(std::unique_ptr<Scene> t_nextScene) 
		{ m_currentScene = std::move(t_nextScene); };

	void UpdateCurrentScene(const sf::Time t_deltaTime) 
		{ m_currentScene->Update(t_deltaTime); };

	void RenderCurrentScene(sf::RenderWindow& t_window) 
		{ m_currentScene->Render(t_window); };

	void ProcessCurrentSceneEvents(const std::optional<sf::Event> t_event, sf::RenderWindow& t_window)
		{ m_currentScene->ProcessEvents(t_event, t_window); };

private:
	SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	std::unique_ptr<Scene> m_currentScene = nullptr;
};
