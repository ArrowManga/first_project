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
	_background = new Image(L"������.png");
	_naruto = new Image(L"�̴ϳ�����.png");
	p1 = new Image(L"water.png");
	p2 = new Image(L"fire.png");
	p3 = new Image(L"water.png");
	p4 = new Image(L"fire.png");
	x = 0;
	y = 0;
	

	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

	SAFE_DELETE(_background);

}

//����
void playGround::update(void)
{
	gameNode::update();
	if (KEYMANAGER->isStayKeyDown('X'))
	{
		x++;
	}
	
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================

	drawPng(_background, 0, 0, _background->GetWidth() / 2, _background->GetHeight() / 2);
	drawPng(_naruto, 0, 0, _naruto->GetWidth() / 3, _naruto->GetHeight() /3);
	drawPng(p1, x, 0);
	//drawPng(p2, x, 0);
	//drawPng(p3, x, 0);
	//drawPng(p4, x, 0);
	//drawPng(p2, 0, 0);
	//90�� ȸ��
	_naruto->RotateFlip(Rotate90FlipNone);

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}

void playGround::drawPng(Image* img, int destX, int destY)
{
	Image* image = img;

	//DrawImage �Լ��� ���������� ��� �޸𸮸� �����ؼ� �ѷ��ֱ⶧����
	//�޸� ������ ���δ�, ���������� ������!

	_graphics->DrawImage(image, destX, destY);

	image = NULL;
	delete image;
}


void playGround::drawPng(Image* img, int destX, int destY, int scaleWidth, int scaleHeight)
{
	Image* image = img;

	//DrawImage �Լ��� ���������� ��� �޸𸮸� �����ؼ� �ѷ��ֱ⶧����
	//�޸� ������ ���δ�, ���������� ������!

	_graphics->DrawImage(image, destX, destY, scaleWidth, scaleHeight);

	image = NULL;
	delete image;
}