#ifndef BASE_BLOCK_H_
#define BASE_BLOCK_H_

#include "../../../../../ObjManager/Obj/Obj.h"
#include "BlockData/BlockData.h"

class BaseBlock :public Obj
{
public:
	BaseBlock(BlockData blockData) :
		m_blockData(blockData)
		{
		}

	virtual ~BaseBlock()
	{
	}

	virtual void Init() {};
	virtual void Update() {};
	virtual void Render();		//継承先で変わる可能性があるのでvirtualにする

protected:
	const float m_blockScale = 64.f;
	BlockData m_blockData;
};

#endif // !BASE_BLOCK_H_
