#include "Stage.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void Stage::Init()
{
	ReadStage("Stage/1-1.csv");
}

void Stage::Update()
{
	m_blockManager.Update();
}

void Stage::Render()
{
	m_blockManager.Render();
}

void Stage::ReadStage(const char* pfileName)
{
	std::ifstream ifs(pfileName);
	std::string str;

	int row = 0, column = 0;

	getline(ifs, str);

	replace(str.begin(), str.end(), ',', ' ');
	std::stringstream stageAllStream(str);

	stageAllStream >> row >> column;

	m_stageIds.resize(column);

	for (int i = 0;i < column;++i)
	{
		m_stageIds[i].resize(row);
	}

	int  y = 0;

	while (getline(ifs, str))
	{
		replace(str.begin(), str.end(), ',', ' ');
		std::stringstream stageStream(str);

		for (int x = 0;x != m_stageIds[y].size();++x)
		{
			stageStream >> m_stageIds[y][x];

			CreateBlock(m_stageIds[y][x], x, y);
		}

		++y;
	}
}

void Stage::CreateBlock(int stageId, int arrayX, int arrayY)
{
	bool canCreate = (stageId > STAGE::NONE) && (stageId < STAGE::BLOCK_MAX);

	if (canCreate)
	{
		STAGE::BLOCK_ID blockId = static_cast<STAGE::BLOCK_ID>(stageId);
		m_blockManager.Create(blockId, arrayX, arrayY);
	}
}
