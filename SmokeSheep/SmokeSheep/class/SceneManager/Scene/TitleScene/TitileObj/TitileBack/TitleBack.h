#ifndef TITLE_BACK_H_
#define TITLE_BACK_H_

#include "../../../ObjManager/Obj/Obj.h"

class TitleBack :public Obj
{
public:
	TitleBack() 
	{
		Init();
	}
	
	~TitleBack()
	{
		m_rGameLib.ReleaseTex();
	}

	void Init();
	void Update() {}
	void Render();

};

#endif // !TITLE_BACK_H_
