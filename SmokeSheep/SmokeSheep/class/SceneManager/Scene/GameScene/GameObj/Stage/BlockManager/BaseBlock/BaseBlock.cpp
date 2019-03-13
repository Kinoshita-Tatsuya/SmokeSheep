#include "BaseBlock.h"

void BaseBlock::Render()
{
	CustomVertex block[4];
	ObjData data;

	int x = m_blockData.m_arrayXNum;
	int y = m_blockData.m_arrayYNum;

	const float BLOCK_CENTER = m_blockScale * 2;

	data.m_center = { BLOCK_CENTER * x , BLOCK_CENTER * y ,0.f };
	data.m_halfScale = { m_blockScale , m_blockScale, 0.0f };

	m_rGameLib.CreateRect(block, data);

	m_rGameLib.Render(block, m_rGameLib.GetTex(m_blockData.m_ptextureKey));
}
