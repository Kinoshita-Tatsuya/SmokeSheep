#include "BaseBlock.h"

void BaseBlock::Render()
{
	CustomVertex block[4];
	ObjData data;

	int x = m_blockData.m_arrayXNum;
	int y = m_blockData.m_arrayYNum;

	data.m_center = { m_blockScale * x , m_blockScale * y ,0.f };
	data.m_halfScale = { m_blockScale , m_blockScale, 0.0f };

	m_rGameLib.CreateRect(block, data);

	m_rGameLib.Render(block, m_rGameLib.GetTex(m_blockData.m_ptextureKey));
}
