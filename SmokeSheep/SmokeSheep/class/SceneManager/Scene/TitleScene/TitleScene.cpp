#include "TitleScene.h"
#include "TitileObj/TitileBack/TitleBack.h"
#include "TitileObj/TitleLogo/TitleLogo.h"

TitleScene::TitleScene()
{
	m_objManager->Register(static_cast<Obj*>(new TitleBack()));
	m_objManager->Register(static_cast<Obj*>(new TitleLogo()));
}

TitleScene::~TitleScene()

{

}
