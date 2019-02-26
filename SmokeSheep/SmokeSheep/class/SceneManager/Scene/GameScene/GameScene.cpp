#include "GameScene.h"
#include "GameObj/Stage/Stage.h"

GameScene::GameScene()
{
	m_objManager->Register(static_cast<Obj*>(new Stage()));
}

GameScene::~GameScene()
{

}
