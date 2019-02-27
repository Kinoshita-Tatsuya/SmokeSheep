#include "TitleScene.h"
#include "TitileObj/TitileBack/TitleBack.h"
#include "TitileObj/TitleLogo/TitleLogo.h"
#include "TitileObj/TitleAnimations/TitleAnimations.h"
#include "TitileObj/TitleSelectMenu/TitleSelectMenu.h"

TitleScene::TitleScene()
{
	m_pobjManager->Register(static_cast<Obj*>(new TitleBack()));
	m_pobjManager->Register(static_cast<Obj*>(new TitleLogo()));
	m_pobjManager->Register(static_cast<Obj*>(new TitleAnimations()));
	m_pobjManager->Register(static_cast<Obj*>(new TitleSelectMenu()));
}

TitleScene::~TitleScene()

{

}
