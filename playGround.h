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
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	
	void drawPng(Image* img, int destX, int destY);
	void drawPng(Image* img, int destX, int destY, int scaleWidth, int scaleHeight);


	playGround();
	~playGround();
};

