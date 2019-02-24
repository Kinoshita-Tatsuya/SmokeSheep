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
		TA_BIRD,
		TA_MAX
	};

	void SheepAnimation();	
	void GrandmaAnimation();
	//void BirdAnimation();

	int m_animationCounts[TA_MAX] = { 0,0,0 };		//アニメーションの画像枚数カウント
	ObjData m_animationDatas[TA_MAX];				//アニメーションに必要なポリゴンデータ

	const TCHAR* m_filePathAndKeys[TA_MAX][2] =
	{
		_T("SheepAni"),		_T("Textures/Title/Animations/Sheep_Stand-by.png"),
		_T("GrandmaAni"),	_T("Textures/Title/Animations/Grandmother_Stand-by.png"),
		_T("BirdAni"),		_T("Textures/Title/Animations/Bird.png")
	};

};

#endif // !TITLE_ANIMATIONS_H_
