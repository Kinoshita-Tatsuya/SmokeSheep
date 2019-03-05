#include "BlockManager.h"

#include "BaseBlock/GrassBlock/GrassBlock.h"

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

		break;

	case STAGE::GRASS:
		baseBlock = new GrassBlock(data);

		break;

	case STAGE::GROUND_NIGHT:
		
		break;

	case STAGE::GRASS_NIGHT:
		
		break;

	case STAGE::ICE:
		
		break;

	case STAGE::SNOW:
		
		break;

	case STAGE::IVY:
	
		break;

	case STAGE::DIE:
		
		break;

	case STAGE::GOAR:
		
		break;

	default:
		break;
	}
}
