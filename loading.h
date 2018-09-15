#pragma once
#include "gameNode.h"
#include "progressBar.h"

enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,		//이미지 초기화 방식 1
	LOAD_KIND_IMAGE_1,		//이미지 초기화 방식 2
	LOAD_KIND_IMAGE_2,		//이미지 초기화 방식 3
	LOAD_KIND_FRAMEIMAGE_0,	//프레임 이미지 초기화 방식 1
	LOAD_KIND_FRAMEIMAGE_1,	//프레임 이미지 초기화 방식 2
	LOAD_KIND_SOUND,		//사운드 초기화 방식
	LOAD_KIND_END
};

struct tagImageResource
{
	string keyName;			//이미지 키 값
	const char* fileName;	//파일 이름
	float x, y;				//좌표
	int width, height;		//크기
	int frameX, frameY;		//프레임이미지 일떄 프레임 장 수
	bool trans;				
	COLORREF transColor;
};

class loadItem
{
private:
	LOAD_KIND			_kind;
	tagImageResource	_imageResource;
	
public:
	HRESULT initForImage(string keyName, int width, int height);
	HRESULT initForImage(string keyName, const char* fileName, int width, int height, BOOL trans = FALSE,
		COLORREF transColor = FALSE);
	HRESULT initForImage(string keyName, const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT initForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);

	LOAD_KIND getLoadingKind(void) { return _kind; }

	tagImageResource getImageResource() { return _imageResource; }

	loadItem();
	~loadItem();
};

class loading : public gameNode
{
private:
	typedef vector<loadItem*>			arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItemIter;

private:
	arrLoadItem _vLoadItem;
	image* _background;
	progressBar* _loadingBar;

	int _currentGauge;			//로딩 게이지

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void loadImage(string keyName, int width, int height);
	void loadImage(string keyName, const char* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);
	void loadImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);
	void loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);
	void loadFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);

	BOOL loadingDone();

	vector<loadItem*> getLoadItem() { return _vLoadItem; }

	loading();
	~loading();
};

