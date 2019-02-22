#ifndef TITLE_LOGO_H_
#define TITLE_LOGO_H_

#include "../../../ObjManager/Obj/Obj.h"

class TitleLogo :public Obj
{
public:
	TitleLogo()
	{
		Init();
	}

	~TitleLogo()
	{
		m_rGameLib.ReleaseTex();
	}

	void Init();
	void Update() {}
	void Render();

};

#endif // !TITLE_LOGO_H_
