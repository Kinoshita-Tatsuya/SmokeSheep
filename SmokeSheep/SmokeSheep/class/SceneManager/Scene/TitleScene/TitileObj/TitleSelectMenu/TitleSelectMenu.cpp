#include "TitleSelectMenu.h"
#include "../../../../SceneManager.h"

void TitleSelectMenu::Init()
{
	m_rGameLib.CreateTex(m_filePathAndKeys[MO_LEFT_SIGN][0], m_filePathAndKeys[MO_LEFT_SIGN][1]);
	m_rGameLib.CreateTex(m_filePathAndKeys[MO_RIGHT_SIGN][0], m_filePathAndKeys[MO_RIGHT_SIGN][1]);
	m_rGameLib.CreateTex(m_filePathAndKeys[MO_LEFT_FONT][0], m_filePathAndKeys[MO_LEFT_FONT][1]);
	m_rGameLib.CreateTex(m_filePathAndKeys[MO_RIGHT_FONT][0], m_filePathAndKeys[MO_RIGHT_FONT][1]);
}

void TitleSelectMenu::Update()
{
	if (m_rGameLib.KeyboardIsPressed(DIK_LEFT))
	{
		m_isStart = true;
	}

	if (m_rGameLib.KeyboardIsPressed(DIK_RIGHT))
	{
		m_isStart = false;
	}

	if (!m_rGameLib.KeyboardIsPressed(DIK_RETURN)) return;
	
	SceneManager& rsceneManager = SceneManager::GetInstance();

	if (m_isStart)
	{
		rsceneManager.SetNextScene(SI_GAME);
	}
	else
	{
		exit(0);	//正常終了させる
	}
}

void TitleSelectMenu::Render()
{
	SignRender();
	FontRender();
}

void TitleSelectMenu::SignRender()
{
	const float EXPAND_SCALE = 1.15f;

	for (int i = 0;i < 2;++i)
	{
		ObjData data[2];
		data[i].m_center = { m_WND_SIZE.m_x * (0.33f + (i * 0.33f)),m_WND_SIZE.m_y * 0.8f,0.0f };
		data[i].m_halfScale = { m_WND_SIZE.m_x * 0.15f, m_WND_SIZE.m_y * 0.15f,0.0f };

		if (m_isStart)
		{
			data[0].m_halfScale *= EXPAND_SCALE;
		}
		else
		{
			data[1].m_halfScale *= EXPAND_SCALE;
		}

		CustomVertex signBoard[4];

		m_rGameLib.CreateRect(signBoard, data[i]);
		m_rGameLib.Render(signBoard, m_rGameLib.GetTex(m_filePathAndKeys[i][0]));
	}
}

void TitleSelectMenu::FontRender()
{
	const float EXPAND_SCALE = 1.15f;

	for (int i = 0;i < 2;++i)
	{
		ObjData data[2];
		data[i].m_center = { m_WND_SIZE.m_x * (0.34f + (i * 0.35f)),m_WND_SIZE.m_y * 0.8f,0.0f };
		data[i].m_halfScale = { m_WND_SIZE.m_x * 0.1f, m_WND_SIZE.m_y * 0.1f,0.0f };

		if (m_isStart)
		{
			data[0].m_halfScale *= EXPAND_SCALE;
		}
		else
		{
			data[1].m_halfScale *= EXPAND_SCALE;
		}

		CustomVertex font[4];

		m_rGameLib.CreateRect(font, data[i]);
		m_rGameLib.Render(font, m_rGameLib.GetTex(m_filePathAndKeys[i + 2][0]));
	}
}
