#ifndef STAGE_H_
#define STAGE_H_

#include <vector>

#include "../../../ObjManager/Obj/Obj.h"
#include "BlockManager/BlockManager.h"

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
	void CreateBlock(int stageId, int arrayX, int arrayY);

	std::vector<std::vector<int>> m_stageIds;

	BlockManager m_blockManager;

	float m_xScroll = 0.f;
	float m_yScroll = 0.f;
};

#endif // !STAGE_H_
