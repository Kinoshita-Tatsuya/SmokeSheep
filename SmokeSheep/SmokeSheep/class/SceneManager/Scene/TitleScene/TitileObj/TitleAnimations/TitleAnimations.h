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

	int m_animationCounts[TA_MAX] = { 0,0,0 };		//アニメーションの画像カウント
	ObjData m_animationDatas[TA_MAX];
};

#endif // !TITLE_ANIMATIONS_H_
