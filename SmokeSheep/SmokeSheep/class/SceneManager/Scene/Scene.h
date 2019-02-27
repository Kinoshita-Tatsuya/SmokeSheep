#ifndef SCENE_H_
#define SCENE_H_

#include <windows.h>

#include "ObjManager/ObjManager.h"

class Scene
{
public:
	Scene() 
	{
		m_pobjManager = new ObjManager();
	}

	~Scene() 
	{
		delete m_pobjManager;
	}

	virtual void Init()
	{
		m_pobjManager->Init();
	}

	virtual void Update()
	{
		m_pobjManager->Update();
	}

	virtual void Render()
	{
		m_pobjManager->Render();
	}

protected:
	ObjManager* m_pobjManager = nullptr;
};

#endif // !SCENE_H_
