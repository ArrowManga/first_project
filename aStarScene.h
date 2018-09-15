#pragma once
#include "gameNode.h"
#include "aStarTest.h"

class aStarScene : public gameNode
{
private:
	aStarTest* _ast;

public:
	aStarScene();
	~aStarScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

