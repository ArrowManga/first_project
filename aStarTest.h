#pragma once
#include "gameNode.h"
#include "tile.h"
#include <vector>
#include <string>

#define TILEWIDTH 32
#define TILEHEIGHT 32

#define TILENUMX (WINSIZEX / TILEWIDTH)
#define TILENUMY (WINSIZEY / TILEHEIGHT)

class aStarTest : public gameNode
{
private:
	//전체 타일 담을 벡터
	vector<tile*>			_vTotalList;
	vector<tile*>::iterator _viTotalList;

	//갈 수 있는 타일 담을 벡터
	vector<tile*>			_vOpenList;
	vector<tile*>::iterator _viOpenList;
	
	//가장 가까운 경로를 담을 벡터
	vector<tile*>			_vCloseList;
	vector<tile*>::iterator _viCloseList;

	tile* _startTile;
	tile* _endTile;
	tile* _currentTile;

	int _count;
	bool _start;

public:
	aStarTest();
	~aStarTest();

	HRESULT init();
	//타일 셋팅 함수
	void setTiles();
	//갈 수 있는 길을 찾아 담아줄 함수
	vector<tile*> addOpenList(tile* currentTile);

	//길 찾는 함수
	void pathFinder(tile* currentTile);

	void release();
	void update();
	void render();
};

