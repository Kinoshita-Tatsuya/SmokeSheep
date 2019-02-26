#include "TitleAnimations.h"

void TitleAnimations::Init()
{
	m_rGameLib.CreateTex(m_fileKeys[TA_SHEEP], m_filePath[TA_SHEEP]);
	m_rGameLib.CreateTex(m_fileKeys[TA_GRANDMA], m_filePath[TA_GRANDMA]);
}

void TitleAnimations::Render()
{
	SheepAnimation();
	GrandmaAnimation();
}

void TitleAnimations::SheepAnimation()
{
	CustomVertex sheep[4];

	m_animationDatas[TA_SHEEP].m_center = { m_WND_SIZE.m_x * 0.15f,m_WND_SIZE.m_y * 0.9f, 0.0f };
	m_animationDatas[TA_SHEEP].m_halfScale = { m_WND_SIZE.m_x * 0.05f, m_WND_SIZE.m_y * 0.25f , 0.0f };

	float& startTU = m_animationDatas[TA_SHEEP].m_texUV.m_startTU;
	float& endTU = m_animationDatas[TA_SHEEP].m_texUV.m_endTU;
	
	const int NUMBER_OF_IMAGES = 4;			//画像の切り取り数
	const float IMAGE_SIZE = 250.f;			//統合ファイルの1枚の画像のサイズ
	const float MAX_IMAGE_SIZE = 2048.f;	//画像の大きさ
	
	static int nextImageCount = 0;	//次のアニメーション画像に行くためのフレームカウント
	nextImageCount += 1;

	if (nextImageCount == 13)
	{
		m_animationCounts[TA_SHEEP] = (m_animationCounts[TA_SHEEP] == NUMBER_OF_IMAGES - 1) ? 0 : ++m_animationCounts[TA_SHEEP];
		nextImageCount = 0;
	}

	const float FIRST_TU = IMAGE_SIZE / MAX_IMAGE_SIZE;

	startTU = FIRST_TU * m_animationCounts[TA_SHEEP];
	endTU = FIRST_TU * (m_animationCounts[TA_SHEEP] + 1);
	m_animationDatas[TA_SHEEP].m_texUV.m_endTV = 512.f / MAX_IMAGE_SIZE;

	m_rGameLib.CreateRect(sheep, m_animationDatas[TA_SHEEP]);

	m_rGameLib.Render(sheep, m_rGameLib.GetTex(m_fileKeys[TA_SHEEP]));
}

void TitleAnimations::GrandmaAnimation()
{
	CustomVertex grandma[4];

	m_animationDatas[TA_GRANDMA].m_center = { m_WND_SIZE.m_x * 0.85f,m_WND_SIZE.m_y * 0.95f, 0.0f };
	m_animationDatas[TA_GRANDMA].m_halfScale = { m_WND_SIZE.m_x * 0.05f, m_WND_SIZE.m_y * 0.25f , 0.0f };

	float& startTU = m_animationDatas[TA_GRANDMA].m_texUV.m_startTU;
	float& endTU = m_animationDatas[TA_GRANDMA].m_texUV.m_endTU;

	const int NUMBER_OF_IMAGES = 4;			//画像の切り取り数
	const float IMAGE_SIZE = 125.f;			//統合ファイルの1枚の画像のサイズ
	const float MAX_IMAGE_SIZE = 2048.f;	//画像の大きさ

	static int nextImageCount = 0;	//次のアニメーション画像に行くためのフレームカウント
	nextImageCount += 1;

	if (nextImageCount == 13)
	{
		m_animationCounts[TA_GRANDMA] = (m_animationCounts[TA_GRANDMA] == NUMBER_OF_IMAGES - 1) ? 0 : ++m_animationCounts[TA_GRANDMA];
		nextImageCount = 0;
	}
	
	const float FIRST_TU = IMAGE_SIZE / MAX_IMAGE_SIZE;

	startTU = FIRST_TU * m_animationCounts[TA_GRANDMA];
	endTU = FIRST_TU * (m_animationCounts[TA_GRANDMA] + 1);
	m_animationDatas[TA_GRANDMA].m_texUV.m_endTV = 256.f / MAX_IMAGE_SIZE;

	m_rGameLib.CreateRect(grandma, m_animationDatas[TA_GRANDMA]);

	m_rGameLib.Render(grandma, m_rGameLib.GetTex(m_fileKeys[TA_GRANDMA]));
}
