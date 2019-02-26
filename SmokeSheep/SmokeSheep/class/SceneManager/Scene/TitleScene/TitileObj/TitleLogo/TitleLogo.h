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

private:
	const TCHAR* m_fileKeys = _T("Logo");
};

#endif // !TITLE_LOGO_H_
