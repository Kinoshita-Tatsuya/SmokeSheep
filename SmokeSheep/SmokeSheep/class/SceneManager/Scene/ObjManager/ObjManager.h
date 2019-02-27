#ifndef OBJ_MANAGER_H_
#define OBJ_MANAGER_H_

#include <vector>

#include "Obj/Obj.h"

class ObjManager
{
public:
	ObjManager() {}

	~ObjManager()
	{
		Release();
	}
	
	void Init();

	void Update();

	void Render();

	void Register(Obj* pobj);

private:
	void Release();

	std::vector<Obj*> m_Obj;
};

#endif // ! OBJ_MANAGER_H_
