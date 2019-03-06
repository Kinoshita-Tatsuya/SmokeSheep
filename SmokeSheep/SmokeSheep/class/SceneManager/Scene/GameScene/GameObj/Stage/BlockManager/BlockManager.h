#ifndef BLOCK_MANAGER_H_
#define BLOCK_MANAGER_H_

#include <vector>

#include "../../../../../../../GameLib/GameLib.h"
#include "../STAGE_ID/STAGE_ID.h"
#include "BaseBlock/BaseBlock.h"

class BlockManager
{
public:
	BlockManager() :m_rgameLib(GameLib::GetInstance())
	{
		Init();
	}

	~BlockManager()
	{
		m_rgameLib.ReleaseTex();
	}

	void Init();
	void Update();
	void Render();
	
	void Create(STAGE::BLOCK_ID blockId, int arrayX, int arrayY);

private:
	std::vector<BaseBlock*> m_blocks;

	const TCHAR* m_ptextureKey[STAGE::BLOCK_MAX] =
	{
		_T(""),
		_T("ground"),
		_T("grass"),
		_T("groundNight"),
		_T("grassNight"),
		_T("ice"),
		_T("snow"),
		_T("ivy"),
		_T("die"),
		_T("goar")
	};

	const TCHAR* m_ptexturePath[STAGE::BLOCK_MAX] =
	{
		_T(""),
		_T("Textures/Game/Block/block_1.png"),
		_T("Textures/Game/Block/block_2.png"),
		_T("Textures/Game/Block/block_3.png"),
		_T("Textures/Game/Block/block_4.png"),
		_T("Textures/Game/Block/block_5.png"),
		_T("Textures/Game/Block/block_6.png"),
		_T("Textures/Game/Block/block_7.png"),
		_T("Textures/Game/Block/deth.png"),
		_T("Textures/Game/Block/goar.png")
	};

	GameLib& m_rgameLib;
};

#endif // !BLOCK_MANAGER_H_
