#pragma once
#include <Windows.h>
#include "loadrealbin.h"
#include "anim_tbl.h"
#include "field.h"
#include "tool.h"
#include <cstringt.h>
#include <atlstr.h>

#pragma comment(lib,"ws2_32.lib")

#define MAP_TILE_GRID_X1	-20
#define MAP_TILE_GRID_X2	+17		// �Z?????
#define MAP_TILE_GRID_Y1	-16
#define MAP_TILE_GRID_Y2	+21		// �Z?????

#define MAP_X_SIZE	(MAP_TILE_GRID_X2 - MAP_TILE_GRID_X1)
#define MAP_Y_SIZE	(MAP_TILE_GRID_Y2 - MAP_TILE_GRID_Y1)

#define MAP_SEE_FLAG	0x4000	

typedef struct MAPHEADER {
	char	szMagic[6];
	WORD	wID;
	char	szMapName[32];
	WORD	wWidth;
	WORD	wHeight;
}*LPMAPHEADER;


typedef struct MAPORIGIN {
	//	int		iTileDx;		//��ܽd�򪺥��Wtile��x pixel���t
	//	int		iTileDy;		//��ܽd�򪺥��Wtile��y pixel���t
	int		iTileX;
	int		iTileY;
	int		iViewStartX;	//�@ʾ���������ϵ�x
	int		iViewStartY;	 //�@ʾ���������ϵ�y
	int		iOriginTileX;	//��(0,0)tile�����Ͻ�x
	int		iOriginTileY;	//��(0,0)tile�����Ͻ�y
	LPWORD	lpwTileData;	//TILE���Y��
	LPWORD	lpwPartData;	 //PART���Y�Ϯ�
#ifdef _ANITILE			//ROG ADD �ӑB�ر� /����ӑB�ر��Y��
	LPWORD	lpwAniTileData;	//ANIT�����Y�Ϯ�
#endif
	LPDWORD	lpdwNpc;		//NPC���Y�� ��
	WORD	wUnitWidth;		//tile�Č���
	WORD	wUnitHeight;	//tile�ĸ߶�
	WORD	wTileW;			//�؈D�Č��� 
	WORD	wTileH;			//�؈D�ĸ߶�
	int		iZoom;			//�sС�ı���(2��Ļ�η�)
	int		iScrollX;		//ָ���Ŵ�rview������x
	int		iScrollY;		 //ָ���Ŵ�rview������y
	WORD	wSelSX;			//��ҷ�x������cx 
	WORD	wSelSY;			 //��ҷ�x������cy
	WORD	wSelEX;			 //��ҷ�x��ĽK�cx 
	WORD	wSelEY;			 //��ҷ�x��ĽK�cy 
}*LPMAPORIGIN;

void getRouteMap(void);
void getRouteData(int dir, int* x, int* y);
bool checkHitMap(int gx, int gy);
int getDirData(int, int, int, int);
BOOL readMap(int floor, int x1, int y1, int x2, int y2, unsigned short* tile, unsigned short* parts, unsigned short* event);
void readHitMap(int x1, int y1, int x2, int y2, unsigned short* tile, unsigned short* parts, unsigned short* event, unsigned short* hitMap);
void setMap(int floor, int gx, int gy);
void setWarpMap(int gx, int gy);
void initMap(void);
void drawMap(void);
void camGamenToMap(float sx, float sy, float* ex, float* ey);
void drawGrid(void);
void camMapToGamen(float sx, float sy, float* ex, float* ey);
void mapCheckSum();
void createMap(int fl, int maxx, int maxy);
void resetMap(void);
void test();
void turnAround(void);
char cnvServDir(int dir, int mode);
void _getMoveRoute2(void);
void shiftRouteMap(void);
BOOL CompareDir(int predir, int dir);
void ReloadMap(int gx, int gy);
BOOL ReadMapHeader(LPCTSTR filename, LPMAPHEADER mapheader);
BOOL ReadMapData(LPMAPORIGIN origin, LPCTSTR filename, int width, int height, int unitwidth, int unitheight);
void View2Tile(LPMAPORIGIN origin, int x, int y, int* rx, int* ry);
void SetOrigin(LPMAPORIGIN origin, int tx, int ty, int tw, int th, int w, int h);
void SetTileOrigin(LPMAPORIGIN origin, int x, int y);