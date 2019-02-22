#include "TitleBack.h"

void TitleBack::Init()
{
	m_rGameLib.CreateTex(_T("Back"), _T("Textures/Title/background_01_01.png"));
}

void TitleBack::Render()
{
	CustomVertex back[4];
	ObjData data;

	data.m_center = { m_WND_SIZE.m_x * 0.5f,m_WND_SIZE.m_y * 0.5f,0.0f };
	data.m_halfScale = { m_WND_SIZE.m_x * 0.5f,m_WND_SIZE.m_y * 0.5f, 0.0f };

	m_rGameLib.CreateRect(back, data);
	m_rGameLib.Render(back, m_rGameLib.GetTex(_T("Back")));
}
