#pragma once

//한 타일의 규격은 32로 한다
#define TILESIZE 32

//타일 갯수 X Axis 20, Y Axis 20
#define TILEX 20
#define TILEY 20

//타일 총 사이즈 
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//타일셋(샘플타일) 갯수
#define SAMPLETILEX 20
#define SAMPLETILEY 9

//타일의 속성을 부여해봅시다
//타일 속성은 이넘으로 해도 무방하다

//예전에는 참 비트필드 많이 썻었는뎅... 메모리 쪼달려서
//요즘은 8기가 막 꽂혀나오고 막막...
#define ATTR_UNMOVE 0x00000001		//벽
#define ATTR_SWAMP	0x00000002		//이속 느려지는 타일
#define ATTR_POISON 0x00000004		//독 타일
#define ATTR_FROZEN 0x00000008		//빙결 타일


//지형에 대한 정의
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};
//오브젝트 에 대한 정의
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2,
	OBJ_NONE
};

//포지션 (맵을 로드해 왔을때 실제로 할당이 될 포지션영역)
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;
	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
};

struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

struct tagCurrentTile
{
	int x;
	int y;
};