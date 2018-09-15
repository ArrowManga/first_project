#include "stdafx.h"
#include "threadTest.h"


threadTest::threadTest()
{
}


threadTest::~threadTest()
{

}

DWORD WINAPI threadTest::threadFunc(LPVOID lpParam)
{
	threadTest* tt = (threadTest*)lpParam;

	while (tt->isGetRunning())
	{
		tt->threadProc();
		Sleep(1); //�̰ž����� ���� ����¦�� �� ������
	}

	return 0;
}


HRESULT threadTest::init()
{
	_running = false;

	_image = IMAGEMANAGER->addImage("��ģ��", "angryBird.bmp", 50, 50, true, RGB(255, 0, 255));
	_image->setX(WINSIZEX / 2 - 350);
	_image->setY(WINSIZEY / 2);

	return S_OK;
}

void threadTest::release()
{

}

void threadTest::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_running = true;

		DWORD threadID = 0;
		//������� �����Ű�� �ݾ��ش�
		CloseHandle(CreateThread(NULL, 0, threadFunc, (void*)this, NULL, &threadID));
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		_running = false;
	}
}

void threadTest::render() 
{
	_image->render(getMemDC());
}


void threadTest::threadProc()
{
	//�̹����� ��ǥ ������ 1�� �����ϴ� ������!
	_image->setX(_image->getX() + 1);
}


