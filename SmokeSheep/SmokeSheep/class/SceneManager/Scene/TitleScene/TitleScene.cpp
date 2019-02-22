#include "TitleScene.h"
#include "TitileObj/TitileBack/TitleBack.h"

TitleScene::TitleScene()
{
	m_objManager->Register(static_cast<Obj*>(new TitleBack()));
}

TitleScene::~TitleScene()

{

}
