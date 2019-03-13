#include "Player.h"

void Player::Init()
{
	m_rGameLib.CreateTex(m_pIMAGE_FILE_KEY, m_pIMAGE_FILE_PATH);
	const float START_POSX = 64.f * 3.f;
	const float START_POSY = 64.f * 9.5f;
	m_pos.x = START_POSX;
	m_pos.y = START_POSY;
	m_direction = RIGHT;
}

void Player::Update()
{
	m_motion = WAIT;
	UpdateVelocity();
	
	m_pos +=  m_movement;
}

void Player::Render()
{
	WaitStateRender();
	WorkStateRender();
}

void Player::UpdateVelocity()
{
	const float ACCELERARION_SCALAR = 2.f;
	const float ACCELERARION_MAX = 6.f;

	if (m_rGameLib.KeyboardIsHeld(DIK_D))
	{
		//制限をかけている
		m_velocity.x = (m_velocity.x > ACCELERARION_MAX) ? ACCELERARION_MAX : m_velocity.x + ACCELERARION_SCALAR;
		m_direction = RIGHT;
		m_motion = WORK;
	}
	
	if (m_rGameLib.KeyboardIsHeld(DIK_A))
	{
		//制限をかけている
		m_velocity.x = (m_velocity.x < -ACCELERARION_MAX) ? -ACCELERARION_MAX : m_velocity.x - ACCELERARION_SCALAR;
		m_direction = LEFT;
		m_motion = WORK;
	}

	const float DECELERATION_SCALAR = 1.f;
	
	if (m_velocity.x != 0)
	{
		m_velocity.x += (DECELERATION_SCALAR * ((m_direction == RIGHT) ? -1 : +1));
	}

	if (m_direction == RIGHT)
	{
		//制限をかけている
		m_velocity.x = (m_velocity.x < 0) ? 0 : m_velocity.x;
	}
	else if (m_direction == LEFT)
	{
		//制限をかけている
		m_velocity.x = (m_velocity.x > 0) ? 0 : m_velocity.x;
	}
	
	m_movement.x = m_velocity.x;
}

void Player::WaitStateRender()
{
	if (m_motion != WAIT) return;

	CustomVertex player[4];
	ObjData data;

	const D3DXVECTOR2 scale = { 130.f / 2.f,120.f / 2.f };

	data.m_center = { m_pos.x,m_pos.y,0.f };
	data.m_halfScale = { scale.x,scale.y,0.f };

	const int NUMBER_OF_IMAGES = 4;			//画像の切り取り数
	const float IMAGE_SIZE = 135.f;			//統合ファイルの1枚の画像のサイズ

	static int nextImageCount = 0;	//次のアニメーション画像に行くためのフレームカウント
	nextImageCount += 1;

	if (nextImageCount > 13)
	{
		m_animationCounts[WAIT] = (m_animationCounts[WAIT] == NUMBER_OF_IMAGES - 1) ? 0 : ++m_animationCounts[WAIT];
		nextImageCount = 0;
	}

	const float FIRST_TU = IMAGE_SIZE / m_IMAGE_SIZE_MAX;

	if (m_direction == RIGHT)
	{
		data.m_texUV.m_startTU = FIRST_TU * m_animationCounts[WAIT];
		data.m_texUV.m_endTU = FIRST_TU * (m_animationCounts[WAIT] + 1);
	}
	else
	{
		data.m_texUV.m_startTU = FIRST_TU * (m_animationCounts[WAIT] + 1);
		data.m_texUV.m_endTU = FIRST_TU * m_animationCounts[WAIT];
	}

	data.m_texUV.m_endTV = 120.f / m_IMAGE_SIZE_MAX;

	m_rGameLib.CreateRect(player, data);

	m_rGameLib.Render(player, m_rGameLib.GetTex(m_pIMAGE_FILE_KEY));
}

void Player::WorkStateRender()
{
	if (m_motion != WORK) return;

	CustomVertex player[4];
	ObjData data;

	const D3DXVECTOR2 scale = { 135.f / 2.f,120.f / 2.f };

	data.m_center = { m_pos.x ,m_pos.y ,0.f };
	data.m_halfScale = { scale.x,scale.y,0.f };

	const int NUMBER_OF_IMAGES = 6;			//画像の切り取り数
	const float IMAGE_SIZE = 135.f;			//統合ファイルの1枚の画像のサイズ

	static int nextImageCount = 0;	//次のアニメーション画像に行くためのフレームカウント
	nextImageCount += 1;

	if (nextImageCount > 10)
	{
		m_animationCounts[WORK] = (m_animationCounts[WORK] == NUMBER_OF_IMAGES - 1) ? 0 : ++m_animationCounts[WORK];
		nextImageCount = 0;
	}
	
	const float FIRST_TU = (IMAGE_SIZE * 4.f) / m_IMAGE_SIZE_MAX;	//4は統合ファイルの四枚目以降のためにかけている
	const float RANGE_TU = IMAGE_SIZE / m_IMAGE_SIZE_MAX;

	if (m_direction == RIGHT)
	{
		data.m_texUV.m_startTU = FIRST_TU + (RANGE_TU * m_animationCounts[WORK]);
		data.m_texUV.m_endTU = FIRST_TU + (RANGE_TU * (m_animationCounts[WORK] + 1));
	}
	else
	{
		data.m_texUV.m_startTU = FIRST_TU + (RANGE_TU * (m_animationCounts[WORK] + 1));
		data.m_texUV.m_endTU = FIRST_TU + (RANGE_TU * m_animationCounts[WORK]);
	}

	data.m_texUV.m_endTV = 120.f / m_IMAGE_SIZE_MAX;

	m_rGameLib.CreateRect(player, data);

	m_rGameLib.Render(player, m_rGameLib.GetTex(m_pIMAGE_FILE_KEY));
}
