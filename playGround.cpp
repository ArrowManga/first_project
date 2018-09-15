#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	_graphics = new Graphics(getMemDC());
	_background = new Image(L"나루토.png");
	_naruto = new Image(L"미니나루토.png");
	p1 = new Image(L"water.png");
	p2 = new Image(L"fire.png");
	p3 = new Image(L"water.png");
	p4 = new Image(L"fire.png");
	x = 0;
	y = 0;
	

	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

	SAFE_DELETE(_background);

}

//연산
void playGround::update(void)
{
	gameNode::update();
	if (KEYMANAGER->isStayKeyDown('X'))
	{
		x++;
	}
	
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================

	drawPng(_background, 0, 0, _background->GetWidth() / 2, _background->GetHeight() / 2);
	drawPng(_naruto, 0, 0, _naruto->GetWidth() / 3, _naruto->GetHeight() /3);
	drawPng(p1, x, 0);
	//drawPng(p2, x, 0);
	//drawPng(p3, x, 0);
	//drawPng(p4, x, 0);
	//drawPng(p2, 0, 0);
	//90도 회전
	_naruto->RotateFlip(Rotate90FlipNone);

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}

void playGround::drawPng(Image* img, int destX, int destY)
{
	Image* image = img;

	//DrawImage 함수는 지속적으로 계속 메모리를 복사해서 뿌려주기때문에
	//메모리 스택이 쌓인다, 지역변수로 써주자!

	_graphics->DrawImage(image, destX, destY);

	image = NULL;
	delete image;
}


void playGround::drawPng(Image* img, int destX, int destY, int scaleWidth, int scaleHeight)
{
	Image* image = img;

	//DrawImage 함수는 지속적으로 계속 메모리를 복사해서 뿌려주기때문에
	//메모리 스택이 쌓인다, 지역변수로 써주자!

	_graphics->DrawImage(image, destX, destY, scaleWidth, scaleHeight);

	image = NULL;
	delete image;
}