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
		m_rGameLib.ReleaseTex();
	}

	void Init();
	void Update();
	void Render();

private:

	void SignRender();
	void FontRender();

	enum MENU_ICONS
	{
		MO_LEFT_SIGN,
		MO_RIGHT_SIGN,
		MO_LEFT_FONT,
		MO_RIGHT_FONT,
		MO_MAX
	};

	const TCHAR* m_filePathAndKeys[MO_MAX][2]=
	{
		_T("startSign"),	_T("Textures/Title/SelectIcons/StartFirstBoard.png"),
		_T("endSign"),		_T("Textures/Title/SelectIcons/endboard.png"),
		_T("startFont"),	_T("Textures/Title/SelectIcons/start.png"),
		_T("endFont"),		_T("Textures/Title/SelectIcons/end.png")
	};

	bool m_isStart = true;		//始めるかどうか
};

#endif // !TITLE_SELECT_MENU_H_
