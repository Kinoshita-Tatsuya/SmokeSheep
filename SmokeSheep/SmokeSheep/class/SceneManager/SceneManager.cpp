#include "SceneManager.h"
#include "Scene/GameScene/GameScene.h"

void SceneManager::Update()
{
	Factory(m_nextScene);

	m_pScene->Update();
}

void SceneManager::Render()
{
	m_pScene->Render();
}

void SceneManager::Factory(SCENE_ID nextScene)
{
	if (m_currentScene == nextScene) return;

	m_currentScene = nextScene;

	switch (nextScene)
	{
	case SI_NONE:

		break;

	case SI_TITLE:
		delete m_Scene;

		m_Scene = new TitleScene();
		break;

	case SI_GAME:
		delete m_pScene;

		m_pScene = new GameScene();
		break;

	default:
		break;
	}
}

void SceneManager::StartScene(SCENE_ID scene)
{
	Factory(scene);
}
