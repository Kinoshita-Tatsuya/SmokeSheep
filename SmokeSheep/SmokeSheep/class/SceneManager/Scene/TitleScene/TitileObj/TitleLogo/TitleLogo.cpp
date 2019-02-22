#include "TitleLogo.h"

void TitleLogo::Init()
{
	m_rGameLib.CreateTex(_T("Logo"), _T("Textures/Title/title_logo_01.png"));
}

void TitleLogo::Render()
{
	CustomVertex back[4];
	ObjData data;

	data.m_center = { m_WND_SIZE.m_x * 0.5f,m_WND_SIZE.m_y * 0.3f,0.0f };
	data.m_halfScale = { m_WND_SIZE.m_x * 0.35f,m_WND_SIZE.m_y * 0.3f, 0.0f };

	m_rGameLib.CreateRect(back, data);
	m_rGameLib.Render(back, m_rGameLib.GetTex(_T("Logo")));
}
