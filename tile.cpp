#include "stdafx.h"
#include "tile.h"
#include "aStarTest.h"

//∏‚πˆ ¿Ã¥œº»∂Û¿Ã¡Ó
tile::tile()
	: _totalCost(0), _costFromStart(0),
	_costToGoal(0), _parentNode(NULL), 
	_idX(0), _idY(0)
{
}


tile::~tile()
{

}

HRESULT tile::init(int idX, int idY)
{
	_color = RGB(250, 150, 0);
	_brush = CreateSolidBrush(_color);
	_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	_center = PointMake(idX * TILEWIDTH + (TILEWIDTH / 2),
		idY * TILEHEIGHT + (TILEHEIGHT / 2));

	_idX = idX;
	_idY = idY;

	_rc = RectMakeCenter(_center.x, _center.y, TILEWIDTH, TILEHEIGHT);

	return S_OK;
}

void tile::release()
{
	DeleteObject(_brush);
	DeleteObject(_pen);
}

void tile::update()	
{

}

void tile::render()	
{
	SelectObject(getMemDC(), (HBRUSH)_brush);
	FillRect(getMemDC(), &_rc, _brush);

	SelectObject(getMemDC(), (HPEN)_pen);
	RectangleMake(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
}
