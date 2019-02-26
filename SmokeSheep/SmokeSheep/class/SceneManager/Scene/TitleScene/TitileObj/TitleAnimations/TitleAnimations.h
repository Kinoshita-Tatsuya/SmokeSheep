#ifndef TITLE_ANIMATIONS_H_
#define TITLE_ANIMATIONS_H_

#include "../../../ObjManager/Obj/Obj.h"

class TitleAnimations :public Obj
{
public:
	TitleAnimations()
	{
		Init();
	}

	~TitleAnimations()
	{

	}

	void Init();
	void Update() {}
	void Render();

private:
	enum CHARACTERS
	{
		TA_SHEEP,
		TA_GRANDMA,
		TA_MAX
	};

	void SheepAnimation();	
	void GrandmaAnimation();
	
	int m_animationCounts[TA_MAX] = { 0,0 };		//アニメーションの画像枚数カウント
	ObjData m_animationDatas[TA_MAX];				//アニメーションに必要なポリゴンデータ

	const TCHAR* m_filePath[TA_MAX] =
	{
		_T("Textures/Title/Animations/Sheep_Stand-by.png"),
		_T("Textures/Title/Animations/Grandmother_Stand-by.png")
	};

	const TCHAR* m_fileKeys[TA_MAX]=
	{
		_T("SheepAni"),
		_T("GrandmaAni")
	};

};

#endif // !TITLE_ANIMATIONS_H_
