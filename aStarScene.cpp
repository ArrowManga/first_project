#include "stdafx.h"
#include "aStarScene.h"


aStarScene::aStarScene()
{
}


aStarScene::~aStarScene()
{

}

HRESULT aStarScene::init()
{
	_ast = new aStarTest;
	_ast->init();

	return S_OK;
}

void aStarScene::release()
{

}

void aStarScene::update() 
{
	_ast->update();
}

void aStarScene::render() 
{
	_ast->render();
}
