#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "../Singleton/Singleton.h"
#include "SCENE_ID/SCENE_ID.h"
#include "Scene/Scene.h"

class SceneManager:public Singleton<SceneManager>
{
public:
	friend class Singleton<SceneManager>;

	~SceneManager() {}

	void Update();

	void Render();

	inline void SetNextScene(SCENE_ID sceneId)
	{
		m_nextScene = sceneId;
	}

private:
	SceneManager()
	{
		StartScene(SI_TITLE);
	}

	void Factory(SCENE_ID nextScene);
	void StartScene(SCENE_ID scene);

	Scene* m_Scene = nullptr;
	SCENE_ID m_currentScene = SI_NONE;
	SCENE_ID m_nextScene = SI_NONE;
};

#endif // !SCENE_MANAGER_H_
