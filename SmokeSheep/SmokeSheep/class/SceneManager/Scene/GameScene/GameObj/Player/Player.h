#ifndef PLAYER_H_
#define PLAYER_H_

#include <d3dx9.h>

#include "../../../ObjManager/Obj/Obj.h"

class Player :public Obj
{
public:
	Player()
	{
		Init();
	}

	~Player()
	{

	}

	void Init();
	void Update();
	void Render();

private:
	void UpdateVelocity();

	void WaitStateRender();
	void WorkStateRender();

	enum MOTION
	{
		WAIT,
		WORK,
		ROLL,
		MOTION_MAX
	};

	enum DIRECTION
	{
		LEFT,
		RIGHT
	};

	const float m_IMAGE_SIZE_MAX = 2048.f;
	const TCHAR* m_pIMAGE_FILE_KEY = _T("player");
	const TCHAR* m_pIMAGE_FILE_PATH = _T("Textures/Game/Player/chara.png");

	int m_animationCounts[MOTION_MAX];

	D3DXVECTOR2 m_pos;
	D3DXVECTOR2 m_velocity;
	D3DXVECTOR2 m_movement;
	DIRECTION   m_direction;
	MOTION		m_motion;
};

#endif // !PLAYER_H_
