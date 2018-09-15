#pragma once
#include "gameNode.h"

class threadTest : public gameNode
{
private:
	image* _image;
	bool _running;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void threadProc();

	static DWORD WINAPI threadFunc(LPVOID lpParam);

	bool isGetRunning() { return _running; }

	threadTest();
	~threadTest();
};

