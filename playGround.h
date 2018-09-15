#pragma once
#include "gameNode.h"
#include "threadTest.h"


class playGround : public gameNode
{
private:
	Graphics* _graphics;
	Image* _background;
	Image* _naruto;
	Image* p1;
	Image* p2;
	Image* p3;
	Image* p4;
	int x, y;
	
public:
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수

	
	void drawPng(Image* img, int destX, int destY);
	void drawPng(Image* img, int destX, int destY, int scaleWidth, int scaleHeight);


	playGround();
	~playGround();
};

