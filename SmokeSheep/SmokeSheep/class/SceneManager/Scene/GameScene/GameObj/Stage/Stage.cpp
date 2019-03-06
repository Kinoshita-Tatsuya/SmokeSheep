#include "Stage.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void Stage::Init()
{
	m_rGameLib.CreateTex(_T("block"), _T("Textures/Game/Block/block_2.png"));
	ReadStage("Stage/1-1.csv");
}

void Stage::Update()
{
	const float SCROOL_VALUE = 32.f;

	if (m_rGameLib.KeyboardIsHeld(DIK_A))
	{
		m_xScroll += SCROOL_VALUE;
	}

	if (m_rGameLib.KeyboardIsHeld(DIK_D))
	{
		m_xScroll += -SCROOL_VALUE;
	}

}

void Stage::Render()
{
	const float BLOCK_SCALE = 64.f;

	for (int y = 0;y != m_stageIds.size();++y)
	{
		for (int x = 0;x != m_stageIds[y].size();++x)
		{
			if (m_stageIds[y][x] == 0) continue;

			CustomVertex IdVertex[4];
			ObjData data;

			data.m_center = { (((BLOCK_SCALE * (x + 1))+ m_xScroll)),(BLOCK_SCALE * (y + 1)),0.0f };
			data.m_halfScale = { BLOCK_SCALE,BLOCK_SCALE,0.0f };

			m_rGameLib.CreateRect(IdVertex, data);
			m_rGameLib.Render(IdVertex, m_rGameLib.GetTex(_T("block")));
		}
	}
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
		}

		++y;
	}
}
