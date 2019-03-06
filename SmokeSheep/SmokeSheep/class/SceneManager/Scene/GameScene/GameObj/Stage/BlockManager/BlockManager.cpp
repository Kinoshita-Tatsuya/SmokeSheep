#include "BlockManager.h"

#include "BaseBlock/GroundBlock/GroundBlock.h"
#include "BaseBlock/GrassBlock/GrassBlock.h"
#include "BaseBlock/GroundNightBlock/GroundNightBlock.h"
#include "BaseBlock/GrassNightBlock/GrassNightBlock.h"
#include "BaseBlock/IceBlock/IceBlock.h"
#include "BaseBlock/SnowBlock/SnowBlock.h"
#include "BaseBlock/IvyBlock/IvyBlock.h"

void BlockManager::Init()
{
	for (int i = 0;i < STAGE::BLOCK_MAX;++i)
	{
		m_rgameLib.CreateTex(m_ptextureKey[i], m_ptexturePath[i]);
	}
}

void BlockManager::Update()
{

}

void BlockManager::Render()
{

}

void BlockManager::Create(STAGE::BLOCK_ID blockId, int arrayX, int arrayY)
{
	BlockData data;
	BaseBlock* baseBlock = nullptr;

	data.m_arrayXNum = arrayX;
	data.m_arrayYNum = arrayY;
	data.m_ptextureKey = m_ptextureKey[blockId];

	switch (blockId)
	{
	case STAGE::NONE:

		break;

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
		
		break;

	case STAGE::GOAR:
		
		break;

	default:
		break;
	}
}
