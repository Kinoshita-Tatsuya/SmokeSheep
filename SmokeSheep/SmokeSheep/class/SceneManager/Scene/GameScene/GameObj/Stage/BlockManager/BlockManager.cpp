#include "BlockManager.h"

#include "BaseBlock/GroundBlock/GroundBlock.h"
#include "BaseBlock/GrassBlock/GrassBlock.h"
#include "BaseBlock/GroundNightBlock/GroundNightBlock.h"
#include "BaseBlock/GrassNightBlock/GrassNightBlock.h"
#include "BaseBlock/IceBlock/IceBlock.h"
#include "BaseBlock/SnowBlock/SnowBlock.h"
#include "BaseBlock/IvyBlock/IvyBlock.h"
#include "BaseBlock/DieBlock/DieBlock.h"
#include "BaseBlock/GoarBlock/GoarBlock.h"

void BlockManager::Init()
{
	for (int i = 0;i < STAGE::BLOCK_MAX;++i)
	{
		m_rgameLib.CreateTex(m_ptextureKey[i], m_ptexturePath[i]);
	}

	for (BaseBlock* pI : m_blocks)
	{
		pI->Init();
	}
}

void BlockManager::Update()
{
	for (BaseBlock* pI : m_blocks)
	{
		pI->Update();
	}
}

void BlockManager::Render()
{
	for (BaseBlock* pI: m_blocks)
	{
		pI->Render();
	}
}

void BlockManager::Create(STAGE::BLOCK_ID blockId, int arrayX, int arrayY)
{
	if (blockId == STAGE::NONE) return; //何もないから作る必要がない

	BlockData data;
	BaseBlock* baseBlock = nullptr;

	data.m_arrayXNum = arrayX;
	data.m_arrayYNum = arrayY;
	data.m_ptextureKey = m_ptextureKey[blockId];

	switch (blockId)
	{
	case STAGE::GROUND:
		baseBlock = new GroundBlock(data);

		break;

	case STAGE::GRASS:
		baseBlock = new GrassBlock(data);

		break;

	case STAGE::GROUND_NIGHT:
		baseBlock = new GroundNightBlock(data);

		break;

	case STAGE::GRASS_NIGHT:
		baseBlock = new GrassNightBlock(data);

		break;

	case STAGE::ICE:
		baseBlock = new IceBlock(data);

		break;

	case STAGE::SNOW:
		baseBlock = new SnowBlock(data);

		break;

	case STAGE::IVY:
		baseBlock = new IvyBlock(data);

		break;

	case STAGE::DIE:
		baseBlock = new DieBlock(data);

		break;

	case STAGE::GOAR:
		baseBlock = new GoarBlock(data);
		break;

	default:
		break;
	}

	m_blocks.push_back(baseBlock);
}

void BlockManager::Release()
{
	for (BaseBlock* pi : m_blocks)
	{
		delete pi;
		pi = nullptr;
	}
}
