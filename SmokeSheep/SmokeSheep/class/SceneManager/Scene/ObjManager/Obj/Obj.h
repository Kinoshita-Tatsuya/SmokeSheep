#ifndef OBJ_H_
#define OBJ_H_

#include "../../../../../GameLib/GameLib.h"

class Obj
{
public:
	Obj() :m_rGameLib(GameLib::GetInstance()),m_WND_SIZE(m_rGameLib.GetWndSize()) {}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual void Render() = 0;

protected:
	GameLib& m_rGameLib;

	const RectSize m_WND_SIZE = { 0,0 };
};

#endif // !OBJ_H_
