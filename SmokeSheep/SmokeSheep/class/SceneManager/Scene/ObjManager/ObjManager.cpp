#include "ObjManager.h"

void ObjManager::Init()
{
	for (Obj* pi : m_Obj)
	{
		pi->Init();
	}
}

void ObjManager::Update()
{
	for (Obj* pi : m_Obj)
	{
		pi->Update();
	}
}

void ObjManager::Render()
{
	for (Obj* pi : m_Obj)
	{
		pi->Render();
	}
}

void ObjManager::Register(Obj* pobj)
{
	m_Obj.push_back(pobj);
}

void ObjManager::Release()
{
	for (Obj* pi : m_Obj)
	{
		delete pi;
	}

	m_Obj.clear();
	m_Obj.shrink_to_fit();
}
