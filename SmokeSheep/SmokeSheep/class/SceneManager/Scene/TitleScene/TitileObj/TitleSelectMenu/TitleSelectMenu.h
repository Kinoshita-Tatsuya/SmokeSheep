#ifndef TITLE_SELECT_MENU_H_
#define TITLE_SELECT_MENU_H_

#include "../../../ObjManager/Obj/Obj.h"

class TitleSelectMenu :public Obj
{
public:
	TitleSelectMenu()
	{
		Init();
	}

	~TitleSelectMenu()
	{

	}

	void Init();
	void Update();
	void Render();

};

#endif // !TITLE_SELECT_MENU_H_
