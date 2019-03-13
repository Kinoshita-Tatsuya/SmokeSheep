#include "GameScene.h"
#include "GameObj/Stage/Stage.h"
#include "GameObj/Player/Player.h"

GameScene::GameScene()
{
	m_pobjManager->Register(static_cast<Obj*>(new Stage()));
	m_pobjManager->Register(static_cast<Obj*>(new Player()));
}

GameScene::~GameScene()
{

}
