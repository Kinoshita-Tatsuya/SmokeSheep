#ifndef STAGE_H_
#define STAGE_H_

#include <vector>
#include <tchar.h>

#include "../../../ObjManager/Obj/Obj.h"
#include "STAGE_ID/STAGE_ID.h"

class Stage :public Obj
{
public:
	Stage();
	~Stage();

	void Init();
	void Update();
	void Render();

private:
	void ReadStage(const char* pfileName);

	std::vector<std::vector<STAGE::ID>> m_stageIds;
};

#endif // !STAGE_H_
