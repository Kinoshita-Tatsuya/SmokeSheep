#include "GameScene.h"
#include "GameObj/Stage/Stage.h"

GameScene::GameScene()
{
	m_pobjManager->Register(static_cast<Obj*>(new Stage()));
}

GameScene::~GameScene()
{

}
