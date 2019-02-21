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

private:
	SceneManager()
	{
		
	}

	void Factory();

	Scene* m_Scene = nullptr;
	SCENE_ID m_currentScene;
	SCENE_ID m_nextScene;
};

#endif // !SCENE_MANAGER_H_
