#include "SceneManager.h"

void SceneManager::Update()
{
	Factory();

	m_Scene->Update();
}

void SceneManager::Render()
{
	m_Scene->Render();
}

void SceneManager::Factory()
{
	if (m_currentScene == m_nextScene) return;

	m_currentScene = m_nextScene;

	switch (m_nextScene)
	{
	case SI_GAME:
		delete m_Scene;

		m_Scene;

		break;

	default:
		break;
	}
}
