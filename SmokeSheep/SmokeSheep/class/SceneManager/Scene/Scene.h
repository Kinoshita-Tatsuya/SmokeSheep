#ifndef SCENE_H_
#define SCENE_H_

#include <windows.h>

#include "ObjManager/ObjManager.h"

class Scene
{
public:
	Scene() 
	{
		m_objManager = new ObjManager();
	}

	virtual ~Scene() {}

	virtual void Init()
	{
		m_objManager->Init();
	}

	virtual void Update()
	{
		m_objManager->Update();
	}

	virtual void Render()
	{
		m_objManager->Render();
	}

private:
	ObjManager* m_objManager = nullptr;
};

#endif // !SCENE_H_
