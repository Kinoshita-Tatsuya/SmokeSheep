#ifndef OBJ_MANAGER_H_
#define OBJ_MANAGER_H_

#include <vector>

#include "Obj/Obj.h"

class ObjManager
{
public:
	void Init();

	void Update();

	void Render();

	void Register(Obj* pobj);

private:
	std::vector<Obj*> m_Obj;
};

#endif // ! OBJ_MANAGER_H_
