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
#define MAP_TILE_GRID_X2	+17		// ?????
#define MAP_TILE_GRID_Y1	-16
#define MAP_TILE_GRID_Y2	+21		// ?????

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
	//	int		iTileDx;		//陪ボ絛瞅オtileずx pixel畉
	//	int		iTileDy;		//陪ボ絛瞅オtileずy pixel畉
	int		iTileX;
	int		iTileY;
	int		iViewStartX;	//顯示範圍的左上的x
	int		iViewStartY;	 //顯示範圍的左上的y
	int		iOriginTileX;	//第(0,0)tile的左上角x
	int		iOriginTileY;	//第(0,0)tile的左上角y
	LPWORD	lpwTileData;	//TILE的資料
	LPWORD	lpwPartData;	 //PART的資料
#ifdef _ANITILE			//ROG ADD 動態地表 /加入動態地表資料
	LPWORD	lpwAniTileData;	//ANIT的資料
#endif
	LPDWORD	lpdwNpc;		//NPC資料 
	WORD	wUnitWidth;		//tile的寬度
	WORD	wUnitHeight;	//tile的高度
	WORD	wTileW;			//地圖的寬度 
	WORD	wTileH;			//地圖的高度
	int		iZoom;			//縮小的倍數(2的幕次方)
	int		iScrollX;		//指定放大時view的左上x
	int		iScrollY;		 //指定放大時view的左上y
	WORD	wSelSX;			//拖曳選擇的起點x 
	WORD	wSelSY;			 //拖曳選擇的起點y
	WORD	wSelEX;			 //拖曳選擇的終點x 
	WORD	wSelEY;			 //拖曳選擇的終點y 
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