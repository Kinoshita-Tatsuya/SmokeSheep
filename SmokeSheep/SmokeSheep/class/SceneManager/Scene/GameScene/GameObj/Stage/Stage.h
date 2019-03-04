#ifndef STAGE_H_
#define STAGE_H_

#include <vector>

#include "../../../ObjManager/Obj/Obj.h"
#include "STAGE_ID/STAGE_ID.h"

class Stage :public Obj
{
public:
	Stage()
	{
		Init();
	}

	~Stage()
	{

	}

	void Init();
	void Update();
	void Render();

private:
	void ReadStage(const char* pfileName);

	std::vector<std::vector<int>> m_stageIds;

	float m_xScroll = 0.f;
	float m_yScroll = 0.f;
};

#endif // !STAGE_H_
