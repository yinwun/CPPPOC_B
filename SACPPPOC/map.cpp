#include "map.h"
#include "math2.h"
#include<stdio.h>
#include "PC.h"
#include<direct.h>
#include "loadrealbin.h"


enum
{
	MOUSE_CURSOR_MODE_NORMAL,
	MOUSE_CURSOR_MODE_MOVE
};

int moveStackGx, moveStackGy;
int nowGx, nowGy;
short moveLastDir = -1;
short moveRouteCnt = 0;
#define MOVE_MAX	100
int mapAreaX1, mapAreaY1, mapAreaX2, mapAreaY2;
short moveRoute[MOVE_MAX];
short moveRouteGx[MOVE_MAX];
short moveRouteGy[MOVE_MAX];
int mapAreaWidth, mapAreaHeight;
unsigned short hitMap[MAP_X_SIZE * MAP_Y_SIZE];
float nowVx, nowVy, nowSpdRate;
int nextGx, nextGy;
#define GRID_SIZE		64
float nowX = (float)nowGx * GRID_SIZE, nowY = (float)nowGy * GRID_SIZE;
BOOL moveStackFlag = FALSE;
short moveRouteCnt2 = 0;
BOOL offlineFlag = FALSE;
int nowFloor;
int oldGx = -1, oldGy = -1;
BOOL mapEmptyFlag;
int nowFloorGxSize, nowFloorGySize;
int oldNextGx = -1, oldNextGy = -1;
short mouseCursorMode = MOUSE_CURSOR_MODE_NORMAL;

short nowEncountPercentage;	// ???????
short nowEncountExtra;		// ????????
short minEncountPercentage;	// ????????
short maxEncountPercentage;	// ????????
short sendEnFlag;			// EN???????????
short encountNowFlag;		// ????????

int eventId = 0;			// ??????ID
short eventWarpSendFlag;	// ???????????
short eventWarpSendId;		// ??????????ID
short eventEnemySendFlag;	// ???????????????
short eventEnemySendId;		// ??????????????ID
short eventEnemyFlag;		// ????????????
short etcEventFlag = 0;
short vsLookFlag;			// ?????

unsigned int mouseLeftPushTime;
unsigned int beforeMouseLeftPushTime;

BOOL warpEffectFlag = FALSE;
BOOL warpEffectStart = FALSE;	// ?????????
BOOL warpEffectOk = FALSE;		// ?????????ＯＫ

short fastDrawTileFlag = 1;
int amountXFastDraw = 0, amountYFastDraw = 0;
int nowXFastDraw, nowYFastDraw;
int baseXFastDraw, baseYFastDraw;
int amountXFastDraw2 = 0, amountYFastDraw2 = 0;
int nowXFastDraw2, nowYFastDraw2;
int baseXFastDraw2, baseYFastDraw2;
#define SEARCH_AREA		11		// ????????????????????

int transmigrationEffectFlag;
int transEffectPaletteStatus;
unsigned int transEffectPaletteAfterWaitTime;

int DISPLACEMENT_X = 160;
int DISPLACEMENT_Y = 120;
int DEF_APPSIZEX = 800;
int DEF_APPSIZEY = 600;

int SCREEN_WIDTH_CENTER = DEF_APPSIZEX / 2;
int SCREEN_HEIGHT_CENTER = DEF_APPSIZEY / 2;
float viewPointX;
float viewPointY;
int viewOffsetX = SCREEN_WIDTH_CENTER;
int viewOffsetY = SCREEN_HEIGHT_CENTER;

short wnCloseFlag = 0;
BOOL loginFlag;
int mouseMapX, mouseMapY;
int mouseMapGx, mouseMapGy;

#define ADRNBIN_DIR		"E:\\Game\\shiqiso107\\shiqiso\\data\\adrn_138.bin" 
#define REALBIN_DIR		"E:\\Game\\shiqiso107\\shiqiso\\data\\real_138.bin" 

#define MOVE_MAX2	2			// ???????????
short moveRoute2[MOVE_MAX2];

static unsigned short crctab16[] =	/*	crc  ??????		*/
{
		0x0000,  0x1021,  0x2042,  0x3063,  0x4084,  0x50a5,  0x60c6,  0x70e7,
		0x8108,  0x9129,  0xa14a,  0xb16b,  0xc18c,  0xd1ad,  0xe1ce,  0xf1ef,
		0x1231,  0x0210,  0x3273,  0x2252,  0x52b5,  0x4294,  0x72f7,  0x62d6,
		0x9339,  0x8318,  0xb37b,  0xa35a,  0xd3bd,  0xc39c,  0xf3ff,  0xe3de,
		0x2462,  0x3443,  0x0420,  0x1401,  0x64e6,  0x74c7,  0x44a4,  0x5485,
		0xa56a,  0xb54b,  0x8528,  0x9509,  0xe5ee,  0xf5cf,  0xc5ac,  0xd58d,
		0x3653,  0x2672,  0x1611,  0x0630,  0x76d7,  0x66f6,  0x5695,  0x46b4,
		0xb75b,  0xa77a,  0x9719,  0x8738,  0xf7df,  0xe7fe,  0xd79d,  0xc7bc,
		0x48c4,  0x58e5,  0x6886,  0x78a7,  0x0840,  0x1861,  0x2802,  0x3823,
		0xc9cc,  0xd9ed,  0xe98e,  0xf9af,  0x8948,  0x9969,  0xa90a,  0xb92b,
		0x5af5,  0x4ad4,  0x7ab7,  0x6a96,  0x1a71,  0x0a50,  0x3a33,  0x2a12,
		0xdbfd,  0xcbdc,  0xfbbf,  0xeb9e,  0x9b79,  0x8b58,  0xbb3b,  0xab1a,
		0x6ca6,  0x7c87,  0x4ce4,  0x5cc5,  0x2c22,  0x3c03,  0x0c60,  0x1c41,
		0xedae,  0xfd8f,  0xcdec,  0xddcd,  0xad2a,  0xbd0b,  0x8d68,  0x9d49,
		0x7e97,  0x6eb6,  0x5ed5,  0x4ef4,  0x3e13,  0x2e32,  0x1e51,  0x0e70,
		0xff9f,  0xefbe,  0xdfdd,  0xcffc,  0xbf1b,  0xaf3a,  0x9f59,  0x8f78,
		0x9188,  0x81a9,  0xb1ca,  0xa1eb,  0xd10c,  0xc12d,  0xf14e,  0xe16f,
		0x1080,  0x00a1,  0x30c2,  0x20e3,  0x5004,  0x4025,  0x7046,  0x6067,
		0x83b9,  0x9398,  0xa3fb,  0xb3da,  0xc33d,  0xd31c,  0xe37f,  0xf35e,
		0x02b1,  0x1290,  0x22f3,  0x32d2,  0x4235,  0x5214,  0x6277,  0x7256,
		0xb5ea,  0xa5cb,  0x95a8,  0x8589,  0xf56e,  0xe54f,  0xd52c,  0xc50d,
		0x34e2,  0x24c3,  0x14a0,  0x0481,  0x7466,  0x6447,  0x5424,  0x4405,
		0xa7db,  0xb7fa,  0x8799,  0x97b8,  0xe75f,  0xf77e,  0xc71d,  0xd73c,
		0x26d3,  0x36f2,  0x0691,  0x16b0,  0x6657,  0x7676,  0x4615,  0x5634,
		0xd94c,  0xc96d,  0xf90e,  0xe92f,  0x99c8,  0x89e9,  0xb98a,  0xa9ab,
		0x5844,  0x4865,  0x7806,  0x6827,  0x18c0,  0x08e1,  0x3882,  0x28a3,
		0xcb7d,  0xdb5c,  0xeb3f,  0xfb1e,  0x8bf9,  0x9bd8,  0xabbb,  0xbb9a,
		0x4a75,  0x5a54,  0x6a37,  0x7a16,  0x0af1,  0x1ad0,  0x2ab3,  0x3a92,
		0xfd2e,  0xed0f,  0xdd6c,  0xcd4d,  0xbdaa,  0xad8b,  0x9de8,  0x8dc9,
		0x7c26,  0x6c07,  0x5c64,  0x4c45,  0x3ca2,  0x2c83,  0x1ce0,  0x0cc1,
		0xef1f,  0xff3e,  0xcf5d,  0xdf7c,  0xaf9b,  0xbfba,  0x8fd9,  0x9ff8,
		0x6e17,  0x7e36,  0x4e55,  0x5e74,  0x2e93,  0x3eb2,  0x0ed1,  0x1ef0,
};

static unsigned char BitTable[] =	/*	???????????????	*/
{
		0x00 , 0x80 , 0x40 , 0xC0 , 0x20 , 0xA0 , 0x60 , 0xE0 ,
		0x10 , 0x90 , 0x50 , 0xD0 , 0x30 , 0xB0 , 0x70 , 0xF0 ,
		0x08 , 0x88 , 0x48 , 0xC8 , 0x28 , 0xA8 , 0x68 , 0xE8 ,
		0x18 , 0x98 , 0x58 , 0xD8 , 0x38 , 0xB8 , 0x78 , 0xF8 ,
		0x04 , 0x84 , 0x44 , 0xC4 , 0x24 , 0xA4 , 0x64 , 0xE4 ,
		0x14 , 0x94 , 0x54 , 0xD4 , 0x34 , 0xB4 , 0x74 , 0xF4 ,
		0x0C , 0x8C , 0x4C , 0xCC , 0x2C , 0xAC , 0x6C , 0xEC ,
		0x1C , 0x9C , 0x5C , 0xDC , 0x3C , 0xBC , 0x7C , 0xFC ,
		0x02 , 0x82 , 0x42 , 0xC2 , 0x22 , 0xA2 , 0x62 , 0xE2 ,
		0x12 , 0x92 , 0x52 , 0xD2 , 0x32 , 0xB2 , 0x72 , 0xF2 ,
		0x0A , 0x8A , 0x4A , 0xCA , 0x2A , 0xAA , 0x6A , 0xEA ,
		0x1A , 0x9A , 0x5A , 0xDA , 0x3A , 0xBA , 0x7A , 0xFA ,
		0x06 , 0x86 , 0x46 , 0xC6 , 0x26 , 0xA6 , 0x66 , 0xE6 ,
		0x16 , 0x96 , 0x56 , 0xD6 , 0x36 , 0xB6 , 0x76 , 0xF6 ,
		0x0E , 0x8E , 0x4E , 0xCE , 0x2E , 0xAE , 0x6E , 0xEE ,
		0x1E , 0x9E , 0x5E , 0xDE , 0x3E , 0xBE , 0x7E , 0xFE ,
		0x01 , 0x81 , 0x41 , 0xC1 , 0x21 , 0xA1 , 0x61 , 0xE1 ,
		0x11 , 0x91 , 0x51 , 0xD1 , 0x31 , 0xB1 , 0x71 , 0xF1 ,
		0x09 , 0x89 , 0x49 , 0xC9 , 0x29 , 0xA9 , 0x69 , 0xE9 ,
		0x19 , 0x99 , 0x59 , 0xD9 , 0x39 , 0xB9 , 0x79 , 0xF9 ,
		0x05 , 0x85 , 0x45 , 0xC5 , 0x25 , 0xA5 , 0x65 , 0xE5 ,
		0x15 , 0x95 , 0x55 , 0xD5 , 0x35 , 0xB5 , 0x75 , 0xF5 ,
		0x0D , 0x8D , 0x4D , 0xCD , 0x2D , 0xAD , 0x6D , 0xED ,
		0x1D , 0x9D , 0x5D , 0xDD , 0x3D , 0xBD , 0x7D , 0xFD ,
		0x03 , 0x83 , 0x43 , 0xC3 , 0x23 , 0xA3 , 0x63 , 0xE3 ,
		0x13 , 0x93 , 0x53 , 0xD3 , 0x33 , 0xB3 , 0x73 , 0xF3 ,
		0x0B , 0x8B , 0x4B , 0xCB , 0x2B , 0xAB , 0x6B , 0xEB ,
		0x1B , 0x9B , 0x5B , 0xDB , 0x3B , 0xBB , 0x7B , 0xFB ,
		0x07 , 0x87 , 0x47 , 0xC7 , 0x27 , 0xA7 , 0x67 , 0xE7 ,
		0x17 , 0x97 , 0x57 , 0xD7 , 0x37 , 0xB7 , 0x77 , 0xF7 ,
		0x0F , 0x8F , 0x4F , 0xCF , 0x2F , 0xAF , 0x6F , 0xEF ,
		0x1F , 0x9F , 0x5F , 0xDF , 0x3F , 0xBF , 0x7F , 0xFF
};

void getRouteMap(void)
{

	//nowGx = 12;
	//nowGy = 16;

	int mx = moveStackGx, my = moveStackGy, nowx = nowGx, nowy = nowGy, dir, dx, dy, targetDir, nowDir,i;
	//int  checkDir1, checkDir2, checkDir3, checkDir4;
	int dirTbl[] = { 0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7 ,-7 };
	float tmpDir;
	float tmpX, tmpY;
	bool flag;
	int predir = -9999;

	moveLastDir = -1;
	if (nowx == mx && nowy == my)
		return;
	tmpX = (float)(mx - nowx);
	tmpY = (float)(my - nowy);
	tmpDir = Atan(tmpX, tmpY) + 22.5F;
	AdjustDir(&tmpDir);
	targetDir = (int)(tmpDir / 45);

	moveRouteCnt = 0;

	while (nowx != mx || nowy != my)
	{
		if (moveRouteCnt >= MOVE_MAX)
		{
			moveRouteCnt = 0;
			return;
		}

		tmpX = (float)(mx - nowx);
		tmpY = (float)(my - nowy);
		tmpDir = Atan(tmpX, tmpY) + 22.5F;
		AdjustDir(&tmpDir);
		nowDir = (int)(tmpDir / 45);
		/*
		checkDir1 = targetDir + 1;
		checkDir1 &= 7;
		checkDir2 = targetDir - 1;
		checkDir2 &= 7;
		checkDir3 = targetDir - 2;
		checkDir3 &= 7;
		checkDir4 = targetDir + 2;
		checkDir4 &= 7;
		
		if (nowDir != targetDir && nowDir != checkDir1 && nowDir != checkDir2 && nowDir != checkDir3 && nowDir != checkDir4)
			break;
		*/
		flag = true;
		for (i = 0; i < sizeof(dirTbl) / sizeof(int); i++)
		{
			dir = nowDir + dirTbl[i];
			dir &= 7;
			/*
			checkDir1 = targetDir + 1;
			checkDir1 &= 7;
			checkDir2 = targetDir - 1;
			checkDir2 &= 7;
			checkDir3 = targetDir - 2;
			checkDir3 &= 7;
			checkDir4 = targetDir + 2;
			checkDir4 &= 7;
			
			if (dir != targetDir && dir != checkDir1 && dir != checkDir2 && nowDir != checkDir3 && nowDir != checkDir4)
				continue;
			*/
			if (CompareDir(predir, dir)) continue;
		
			getRouteData(dir, &dx, &dy);
			int tempx = nowx + dx;
			int tempy = nowy + dy;
			if (checkHitMap(tempx, tempy))
			{
				if ((nowx + dx) == mx && (nowy + dy) == my)
				{
					if ((dir % 2) == 0)
						continue;
					flag = true;
					break;
				}
				else
					continue;
			}
			if ((dir % 2) == 0)
			{
				int dir2, dx2, dy2, dir3, dx3, dy3;
				bool flag2, flag3;

				dir2 = dir + 1;
				dir2 &= 7;
				getRouteData(dir2, &dx2, &dy2);
				dir3 = dir - 1;
				dir3 &= 7;
				getRouteData(dir3, &dx3, &dy3);
				flag2 = checkHitMap(nowx + dx2, nowy + dy2);
				flag3 = checkHitMap(nowx + dx3, nowy + dy3);
				if (flag2 && flag3)
					break;
				if (flag2)
				{
					moveRoute[moveRouteCnt] = dir3;
					moveRouteGx[moveRouteCnt] = nowx + dx3;
					moveRouteGy[moveRouteCnt] = nowy + dy3;
					predir = dir3;
					printf("dir3 %d\n", dir3);
					printf("walkpos %d,%d\n", moveRouteGx[moveRouteCnt], moveRouteGy[moveRouteCnt]);
					moveRouteCnt++;
					dx = (nowx + dx) - (nowx + dx3);
					dy = (nowy + dy) - (nowy + dy3);
					dir = getDirData(0, 0, dx, dy);
					nowx += dx3;
					nowy += dy3;
					flag = false;
					break;
				}
				if (flag3)
				{
					moveRoute[moveRouteCnt] = dir2;
					moveRouteGx[moveRouteCnt] = nowx + dx2;
					moveRouteGy[moveRouteCnt] = nowy + dy2;
					predir = dir2;
					printf("dir3 %d\n", dir2);
					printf("walkpos %d,%d\n", moveRouteGx[moveRouteCnt], moveRouteGy[moveRouteCnt]);
					moveRouteCnt++;
					dx = (nowx + dx) - (nowx + dx2);
					dy = (nowy + dy) - (nowy + dy2);
					dir = getDirData(0, 0, dx, dy);
					nowx += dx2;
					nowy += dy2;
					flag = false;
					break;
				}
			}
			flag = false;
			break;
		}
		if (flag)
			break;
		nowx += dx;
		nowy += dy;
		moveRoute[moveRouteCnt] = dir;
		moveRouteGx[moveRouteCnt] = nowx;
		moveRouteGy[moveRouteCnt] = nowy;
		predir = dir;
		printf("dir %d\n", dir);
		printf("walkpos %d,%d\n", nowx, nowy);
		moveRouteCnt++;
	}
	dx = 0;
	if (mx - nowx > 0)
		dx = 1;
	else if (mx - nowx < 0)
		dx = -1;
	if (dx != 0)
	{
		while (!checkHitMap(nowx + dx, nowy) && mx != nowx)
		{
			nowx += dx;
			moveRoute[moveRouteCnt] = getDirData(0, 0, dx, 0);
			moveRouteGx[moveRouteCnt] = nowx;
			moveRouteGy[moveRouteCnt] = nowy;
			printf("getDirData dx %d\n", moveRoute[moveRouteCnt]);
			printf("walkpos %d,%d\n", nowx, nowy);
			moveRouteCnt++;
		}
	}
	dy = 0;
	if (my - nowy > 0)
		dy = 1;
	else if (my - nowy < 0)
		dy = -1;
	if (dy != 0)
	{
		while (!checkHitMap(nowx, nowy + dy) && my != nowy)
		{
			nowy += dy;
			moveRoute[moveRouteCnt] = getDirData(0, 0, 0, dy);
			moveRouteGx[moveRouteCnt] = nowx;
			moveRouteGy[moveRouteCnt] = nowy;
			printf("getDirData dy %d\n", moveRoute[moveRouteCnt]);
			printf("walkpos %d,%d\n", nowx, nowy);
			moveRouteCnt++;
		}
	}
	if (moveRouteCnt > 0 && (nowx != mx || nowy != my))
	{
		tmpX = (float)(mx - nowx);
		tmpY = (float)(my - nowy);
		tmpDir = Atan(tmpX, tmpY) + 22.5F;
		AdjustDir(&tmpDir);
		moveLastDir = (int)(tmpDir / 45);
	}

	printf("moveRouteCnt %d, moveRouteCnt2 %d\n", moveRouteCnt, moveRouteCnt2);
	return;
}

void _getMoveRoute2(void)
{
	int i;

	for (i = 0; i < MOVE_MAX2 && moveRouteCnt > 0; i++)
	{
		moveRoute2[moveRouteCnt2] = moveRoute[0];
		moveRouteCnt2++;
		shiftRouteMap();
	}
}

void shiftRouteMap(void)
{
	int i;

	if (moveRouteCnt <= 0)
		return;

	moveRouteCnt--;
	for (i = 0; i < moveRouteCnt; i++)
	{
		moveRoute[i] = moveRoute[i + 1];
		moveRouteGx[i] = moveRouteGx[i + 1];
		moveRouteGy[i] = moveRouteGy[i + 1];

		printf("walkpos %d,%d\n", moveRouteGx[i], moveRouteGy[i]);
	}
}

void getRouteData(int dir, int* x, int* y)
{
	switch (dir)
	{
	case 0:
		*x = -1;
		*y = 1;
		break;

	case 1:
		*x = -1;
		*y = 0;
		break;

	case 2:
		*x = -1;
		*y = -1;
		break;

	case 3:
		*x = 0;
		*y = -1;
		break;

	case 4:
		*x = 1;
		*y = -1;
		break;

	case 5:
		*x = 1;
		*y = 0;
		break;

	case 6:
		*x = 1;
		*y = 1;
		break;

	case 7:
		*x = 0;
		*y = 1;
		break;

	default:
		*x = 0;
		*y = 0;
		break;
	}
}

bool checkHitMap(int gx, int gy)
{
	int x, y;
	printf("checkHitMap:X-%d,Y-%d\n", gx, gy);
	x = gx - mapAreaX1;
	y = gy - mapAreaY1;

	if (pc.skywalker)
		return false;

	// ????????
	if (x < 0 || mapAreaWidth <= x || y < 0 || mapAreaHeight <= y) {
		setWarpMap(gx, gy);
		resetMap();

		x = gx - mapAreaX1;
		y = gy - mapAreaY1;
	}
		
#ifdef _ITEM_PATH
	if (ITEMPATHFLAG)
	{
		ITEMPATHFLAG = FALSE;
		return FALSE;
	}
#endif
	// ????????
	if (hitMap[y * mapAreaWidth + x] == 1)
		return true;

	return false;
}

int getDirData(int gx1, int gy1, int gx2, int gy2)
{
	float tmpDir, tmpX, tmpY;

	// ?佋?????
	tmpX = (float)(gx2 - gx1);
	tmpY = (float)(gy2 - gy1);
	tmpDir = Atan(tmpX, tmpY) + 22.5F;
	AdjustDir(&tmpDir);

	return (int)(tmpDir / 45);
}


void onceMoveProc(void)
{
	int dir;
	// ??????????????䥺?
	nowSpdRate = 1.0F;
	// ??????????????

	if ((float)nextGx * GRID_SIZE == nowX && (float)nextGy * GRID_SIZE == nowY)
	{
		if (moveStackFlag && moveRouteCnt2 == 0)
		{
			moveStackFlag = FALSE;
			getRouteMap();
		}
	}
}

BOOL readMap(int floor, int x1, int y1, int x2, int y2, unsigned short* tile, unsigned short* parts, unsigned short* event)
{
	FILE* fp;
	char filename[255];
#ifdef _FIX_DEL_MAP           // WON 修正玩家抽地图
	char list[10];
#endif
	int fWidth, fHeight, fOffset, mWidth, width, height, fx, fy, mx, my, len, len2, i;
	printf("floor=%d x1=%d y1=%d x2=%d y2=%d\n",floor,x1,y1,x2,y2);
	// ???????䦶?
	//sprintf_s(filename, "map\\%d.dat", floor);
	sprintf_s(filename, "E:\\Game\\shiqiso107\\shiqiso\\map\\%d.dat", floor);

	// ????????
	if ((fp = fopen(filename, "rb")) == NULL)
	{
#ifdef _FIX_DEL_MAP	//andy_add
		memset(tile, 193, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
		//memset(parts, 193, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
#else
		_mkdir("map");
		// ?????????
		fp = fopen(filename, "wb");
		fclose(fp);
#endif
		// ??????????????
		if ((fp = fopen(filename, "rb")) == NULL)
			return FALSE;
	}

#ifdef _FIX_DEL_MAP           // WON 修正玩家抽地图    
	fseek(fp, 0, SEEK_SET);
	if (!fread(list, sizeof(char), 1, fp)) {   // 玩家抽掉地图送监狱
		//andy_add
		memset(tile, 193, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
		//memset(parts, 193, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
		fclose(fp);
		//lssproto_DM_send(sockfd);
		return TRUE;
	}
#endif
	printf("MAP_X_SIZE=%d MAP_Y_SIZE=%d\n",MAP_X_SIZE,MAP_Y_SIZE);
	memset(tile, 0, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
	memset(parts, 0, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
	memset(event, 0, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));
	fseek(fp, 0, SEEK_SET);
	fread(&fWidth, sizeof(int), 1, fp); //1-宽
	fread(&fHeight, sizeof(int), 1, fp);//2-高
	printf("fWidth=%d fHeight=%d\n",fWidth,fHeight);
	mWidth = x2 - x1;
	width = mWidth;
	height = y2 - y1;
	mx = 0;
	fx = x1;

	
	while (1)
	{
		int c = fgetc(fp);
		if (feof(fp))
		{
			printf("\nBBBBB");
			break;
		}
		printf("%d", c);
	}
	

	printf("mWidth=%d width=%d  height=%d  fx=%d\n",mWidth,width,height,fx);
	if (x1 < 0)
	{
		width += x1;
		fx = 0;
		mx -= x1;
	}
	if (x2 > fWidth)
		width -= (x2 - fWidth);
	my = 0;
	fy = y1;
	if (y1 < 0)
	{
		height += y1;
		fy = 0;
		my -= y1;
	}
	if (y2 > fHeight)
		height -= (y2 - fHeight);

	fOffset = sizeof(int) * 2;
	len = fy * fWidth + fx;
	len2 = my * mWidth + mx;
	for (i = 0; i < height; i++)
	{
		fseek(fp, sizeof(short) * len + fOffset, SEEK_SET);
		fread(&tile[len2], sizeof(short) * width, 1, fp);
		printf("%d\n", tile[len2]);
		len += fWidth;
		len2 += mWidth;
	}
	fOffset += sizeof(short) * (fWidth * fHeight);
	len = fy * fWidth + fx;
	len2 = my * mWidth + mx;
	for (i = 0; i < height; i++)
	{
		fseek(fp, sizeof(short) * len + fOffset, SEEK_SET);
		fread(&parts[len2], sizeof(short) * width, 1, fp);//aaaaaaaaaaaaa
		printf("%d\n", parts[len2]);
		len += fWidth;
		len2 += mWidth;
	}
	fOffset += sizeof(short) * (fWidth * fHeight);
	len = fy * fWidth + fx;
	len2 = my * mWidth + mx;
	for (i = 0; i < height; i++)
	{
		fseek(fp, sizeof(short) * len + fOffset, SEEK_SET);
		fread(&event[len2], sizeof(short) * width, 1, fp);
		printf("%d\n", event[len2]);
		len += fWidth;
		len2 += mWidth;
	}
	fclose(fp);

	return TRUE;
}

void readHitMap(int x1, int y1, int x2, int y2, unsigned short* tile, unsigned short* parts, unsigned short* event, unsigned short* hitMap)
{
	int width, height, i, j, k, l;
	S2 hit, hitX, hitY;
	U4 bmpNo;

	memset(hitMap, 0, MAP_X_SIZE * MAP_Y_SIZE * sizeof(short));

	width = x2 - x1;
	height = y2 - y1;
	if (width < 1 || height < 1)
		return;

	// ???
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			// ???????
			if (tile[i * width + j] > CG_INVISIBLE || (60 <= tile[i * width + j] && tile[i * width + j] <= 79))
			{
				realGetNo(tile[i * width + j], &bmpNo);
				// ?????䥺
				realGetHitFlag(bmpNo, &hit);
				// ????????????
				if (hit == 0 && hitMap[i * width + j] != 2)
					hitMap[i * width + j] = 1;
				else if (hit == 2) // hit?2?????????
					hitMap[i * width + j] = 2;
			}
			else
			{
				// 0??11??????????????
				switch (tile[i * width + j])
				{
				case 0:	// 0.bmp(䥺???)????????????
					// ????????????????????
					if ((event[i * width + j] & MAP_SEE_FLAG) == 0)
						break;
				case 1:
				case 2:
				case 5:
				case 6:
				case 9:
				case 10:
					// ?????????????
					if (hitMap[i * width + j] != 2)
						hitMap[i * width + j] = 1;
					break;

				case 4:
					hitMap[i * width + j] = 2;
					break;
				}
			}
		}
	}

	// ???
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			// ???????
			if (parts[i * width + j] > CG_INVISIBLE)
			{
				realGetNo(parts[i * width + j], &bmpNo);
				// ?????䥺
				realGetHitFlag(bmpNo, &hit);
				// ????????????
				if (hit == 0)
				{
					realGetHitPoints(bmpNo, &hitX, &hitY);
					for (k = 0; k < hitY; k++)
					{
						for (l = 0; l < hitX; l++)
						{
							if ((i - k) >= 0 && (j + l) < width && hitMap[(i - k) * width + j + l] != 2)
								hitMap[(i - k) * width + j + l] = 1;
						}
					}
				}
				// ?????????????????
				// ?????????
				else if (hit == 2)
				{
					realGetHitPoints(bmpNo, &hitX, &hitY);
					for (k = 0; k < hitY; k++)
					{
						for (l = 0; l < hitX; l++)
						{
							if ((i - k) >= 0 && (j + l) < width)
								hitMap[(i - k) * width + j + l] = 2;
						}
					}
				}
				else if (hit == 1 && parts[i * width + j] >= 15680 && parts[i * width + j] <= 15732)
				{
					realGetHitPoints(bmpNo, &hitX, &hitY);
					for (k = 0; k < hitY; k++)
					{
						for (l = 0; l < hitX; l++)
						{
							//if ((i - k) >= 0 && (j + l) < width)
								//hitMap[(i-k)*width+j+l] = 0;
							if (k == 0 && l == 0)
								hitMap[(i - k) * width + j + l] = 1;
						}
					}
				}
			}
			else if (60 <= parts[i * width + j] && parts[i * width + j] <= 79)
			{
				realGetNo(parts[i * width + j], &bmpNo);
				// ?????䥺
				realGetHitFlag(bmpNo, &hit);
				// ????????????
				if (hit == 0 && hitMap[i * width + j] != 2)
					hitMap[i * width + j] = 1;
				// hit?2?????????
				else if (hit == 2)
					hitMap[i * width + j] = 2;
			}
			else
			{
				// 0??11??????????????
				switch (parts[i * width + j])
				{
				case 1:
				case 2:
				case 5:
				case 6:
				case 9:
				case 10:
					// ?????????????
					if (hitMap[i * width + j] != 2)
						hitMap[i * width + j] = 1;
					break;

				case 4:
					hitMap[i * width + j] = 2;
					break;
				}
			}

			// ???????????????
			if ((event[i * width + j] & 0x0fff) == EVENT_NPC)
				hitMap[i * width + j] = 1;
		}
	}

	
}

void setMap(int floor, int gx, int gy)
{
	nowFloor = floor;
	setWarpMap(gx, gy);
}

void setWarpMap(int gx, int gy)
{
	nowGx = gx;
	nowGy = gy;
	nowX = (float)nowGx * GRID_SIZE;
	nowY = (float)nowGy * GRID_SIZE;
	nextGx = nowGx;
	nextGy = nowGy;
	nowVx = 0;
	nowVy = 0;
	nowSpdRate = 1;
	oldGx = -1;
	oldGy = -1;
	oldNextGx = -1;
	oldNextGy = -1;
	viewPointX = nowX;
	viewPointY = nowY;
	wnCloseFlag = 1;
#ifdef _AniCrossFrame	   // Syu ADD 动画层游过画面生物
	extern void crossAniRelease();
	crossAniRelease();
#endif
#ifdef _SURFACE_ANIM       //ROG ADD 动态场景
	extern void ReleaseSpecAnim();
	ReleaseSpecAnim();
#endif
}

void initMap(void)
{
	offlineFlag = TRUE;
	if (offlineFlag)
	{
		setMap(2001, 16, 19);
		nowFloorGxSize = 30;
		nowFloorGySize = 30;
	}
	else
	{
		nowFloor = 0;
		nowFloorGxSize = 0;
		nowFloorGySize = 0;
		nowGx = 0;
		nowGy = 0;
		nowX = 0;
		nowY = 0;
		nextGx = 0;
		nextGy = 0;
		oldGx = 0, oldGy = 0;
		oldNextGx = 0, oldNextGy = 0;

		loginFlag = TRUE;
	}

	mapAreaX1 = nowGx + MAP_TILE_GRID_X1;
	mapAreaY1 = nowGy + MAP_TILE_GRID_Y1;
	mapAreaX2 = nowGx + MAP_TILE_GRID_X2;
	mapAreaY2 = nowGy + MAP_TILE_GRID_Y2;

	if (mapAreaX1 < 0)
		mapAreaX1 = 0;
	if (mapAreaY1 < 0)
		mapAreaY1 = 0;
	if (mapAreaX2 > nowFloorGxSize)
		mapAreaX2 = nowFloorGxSize;
	if (mapAreaY2 > nowFloorGySize)
		mapAreaY2 = nowFloorGySize;

	mapAreaWidth = mapAreaX2 - mapAreaX1;
	mapAreaHeight = mapAreaY2 - mapAreaY1;
	nowVx = 0;
	nowVy = 0;
	nowSpdRate = 1;
	moveRouteCnt = 0;
	moveRouteCnt2 = 0;
	moveStackFlag = FALSE;
	mapEmptyFlag = FALSE;
	mouseCursorMode = MOUSE_CURSOR_MODE_NORMAL;
	nowEncountPercentage = 0;
	nowEncountExtra = 0;
	sendEnFlag = 0;
	encountNowFlag = 0;
	eventWarpSendFlag = 0;
	eventEnemySendFlag = 0;
	eventEnemyFlag = 0;
	etcEventFlag = 0;
	mouseLeftPushTime = 0;
	beforeMouseLeftPushTime = 0;
	warpEffectFlag = FALSE;
	warpEffectStart = FALSE;
	warpEffectOk = FALSE;
	//	autoMapSeeFlag = FALSE;
	eventWarpSendId = -1;
	eventEnemySendId = -1;
	moveLastDir = -1;
	amountXFastDraw = 0;
	amountYFastDraw = 0;
	nowXFastDraw = 0;
	nowYFastDraw = 0;
	baseXFastDraw = 0;
	baseYFastDraw = 0;
	amountXFastDraw2 = 0;
	amountYFastDraw2 = 0;
	nowXFastDraw2 = 0;
	nowYFastDraw2 = 0;
	baseXFastDraw2 = 0;
	baseYFastDraw2 = 0;
	vsLookFlag = 0;
	fastDrawTileFlag = 1;
	transmigrationEffectFlag = 0;
	transEffectPaletteStatus = 0;
	transEffectPaletteAfterWaitTime = 0;
#ifdef MAP_CACHE_PROC
	initMapCache();
#endif
}

//
void camGamenToMap(float sx, float sy, float* ex, float* ey)
{
	float x0, y0, x, y;

	// ?䴘?
	x0 = sx - viewOffsetX;
	y0 = sy - viewOffsetY;
	x = x0 - (float)SURFACE_WIDTH / (float)SURFACE_HEIGHT * y0;
	y = x0 + (float)SURFACE_WIDTH / (float)SURFACE_HEIGHT * y0;
	*ex = x + viewPointX;
	*ey = y + viewPointY;
}

void camMapToGamen(float sx, float sy, float* ex, float* ey)
{
	float x0, y0, x, y, tx = (float)(SURFACE_WIDTH >> 1), ty = (float)(SURFACE_HEIGHT >> 1);

	x0 = (sx - viewPointX) / GRID_SIZE;
	y0 = (sy - viewPointY) / GRID_SIZE;
	x = +x0 * tx + y0 * tx;
	y = -x0 * ty + y0 * ty;
	//?䴘?
	*ex = x + viewOffsetX;
	*ey = y + viewOffsetY;
}

void drawGrid(void)
{
	int xx, yy;
	float x, y;

	//camGamenToMap((float)mouse.nowPoint.x, (float)mouse.nowPoint.y, &x, &y);
	camGamenToMap((float)314, (float)263, &x, &y);
	mouseMapX = (int)(x + .5);
	mouseMapY = (int)(y + .5);
	mouseMapGx = (mouseMapX + (GRID_SIZE >> 1)) / GRID_SIZE;
	mouseMapGy = (mouseMapY + (GRID_SIZE >> 1)) / GRID_SIZE;
	xx = mouseMapGx * GRID_SIZE;
	yy = mouseMapGy * GRID_SIZE;
	camMapToGamen((float)xx, (float)yy, &x, &y);
}

unsigned short CheckCRC(unsigned char* p, int size)
{
	unsigned short	crc = 0;
	int		i;

	for (i = 0; i < size; i++)
	{
		crc = (crctab16[(crc >> 8) & 0xFF] ^ (crc << 8) ^ BitTable[p[i]]);
	}
	return crc;
}

void createMap(int fl, int maxx, int maxy)
{
	FILE* fp;
	char floorname[255];
	int i = 0, j, k, ox, oy;
	short l = 0;

	if (fl == 0)
		return;

	sprintf(floorname, "map\\%d.dat", fl);
	if ((fp = fopen(floorname, "rb")) == NULL)
	{
		// ?????䥺??????
		_mkdir("map");
		if ((fp = fopen(floorname, "wb")) == NULL)
			return;
		fseek(fp, 0, SEEK_SET);
		fwrite(&maxx, sizeof(int), 1, fp);
		fwrite(&maxy, sizeof(int), 1, fp);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < maxx; j++)
			{
				for (k = 0; k < maxy; k++)
				{
					fwrite(&l, sizeof(short), 1, fp);
				}
			}
		}
		fclose(fp);
	}
	else
	{
		fread(&ox, sizeof(int), 1, fp);
		fread(&oy, sizeof(int), 1, fp);
		if (maxx != ox || maxy != oy)
		{
			fclose(fp);
			// ????????????????????
			if ((fp = fopen(floorname, "wb")) == NULL)
				return;
			fwrite(&maxx, sizeof(int), 1, fp);
			fwrite(&maxy, sizeof(int), 1, fp);
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < maxx; j++)
				{
					for (k = 0; k < maxy; k++)
					{
						fwrite(&l, sizeof(short), 1, fp);
					}
				}
			}
		}
		fclose(fp);
	}
}




char cnvServDir(int dir, int mode)
{
	char ret = 'f';

	if (0 <= dir && dir <= 2)
	{
		if (mode == 0)
			ret = 'f' + dir;
		else
			ret = 'F' + dir;
	}
	else if (dir < 8)
	{
		if (mode == 0)
			ret = 'a' + dir - 3;
		else
			ret = 'A' + dir - 3;
	}

	return ret;
}

BOOL CompareDir(int predir, int dir) {
	BOOL isOpposite = FALSE;
	switch (predir)
	{
	case 0:
		if (dir == 4) isOpposite = TRUE;
		break;
	case 1:
		if (dir == 5) isOpposite = TRUE;
		break;
	case 2:
		if (dir == 6) isOpposite = TRUE;
		break;
	case 3:
		if (dir == 7) isOpposite = TRUE;
		break;
	case 4:
		if (dir == 0) isOpposite = TRUE;
		break;
	case 5:
		if (dir == 1) isOpposite = TRUE;
		break;
	case 6:
		if (dir == 2) isOpposite = TRUE;
		break;
	case 7:
		if (dir == 3) isOpposite = TRUE;
		break;
	default:
		isOpposite = FALSE;
		break;
	}

	return isOpposite;
}

void resetMap(void)
{
	// ?????????????
	nowGx = (int)(nowX / GRID_SIZE);
	nowGy = (int)(nowY / GRID_SIZE);
	nextGx = nowGx;
	nextGy = nowGy;
	nowX = (float)nowGx * GRID_SIZE;
	nowY = (float)nowGy * GRID_SIZE;
	oldGx = -1;
	oldGy = -1;
	oldNextGx = -1;
	oldNextGy = -1;
	
	mapAreaX1 = nowGx + MAP_TILE_GRID_X1;
	mapAreaY1 = nowGy + MAP_TILE_GRID_Y1;
	mapAreaX2 = nowGx + MAP_TILE_GRID_X2;
	mapAreaY2 = nowGy + MAP_TILE_GRID_Y2;

	
	if (mapAreaX1 < 0)
		mapAreaX1 = 0;
	if (mapAreaY1 < 0)
		mapAreaY1 = 0;
	if (mapAreaX2 > nowFloorGxSize)
		mapAreaX2 = nowFloorGxSize;
	if (mapAreaY2 > nowFloorGySize)
		mapAreaY2 = nowFloorGySize;
	
	mapAreaWidth = mapAreaX2 - mapAreaX1;
	mapAreaHeight = mapAreaY2 - mapAreaY1;
	nowVx = 0;
	nowVy = 0;
	nowSpdRate = 1;
	viewPointX = nowX;
	viewPointY = nowY;
	moveRouteCnt = 0;
	moveRouteCnt2 = 0;
	moveStackFlag = FALSE;
	mouseCursorMode = MOUSE_CURSOR_MODE_NORMAL;
	mouseLeftPushTime = 0;
	beforeMouseLeftPushTime = 0;
	//	autoMapSeeFlag = FALSE;
}

/* 判斷是否為石器的地圖並讀取其檔頭 parameter: filename: 地圖的檔名 mapheader:
存放地圖的檔頭 return: 是否成功 */
BOOL ReadMapHeader(LPCTSTR filename, LPMAPHEADER mapheader)
{
	HANDLE	hfile;
	DWORD	readbyte;
	BOOL	ret = FALSE;
	int		len;
	LPSTR	str;
	if (INVALID_HANDLE_VALUE != (hfile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL))) {
		if (ReadFile(hfile, mapheader, sizeof(MAPHEADER), &readbyte, NULL)) {
			str = mapheader->szMagic;
			if (*str == 'L' && str[1] == 'S' && str[2] == '2' && str[3] == 'M' && str[4] == 'A' && str[5] == 'P') {
				str = mapheader->szMapName;
				len = lstrlen(str);
				//				if( len>2 && str[len-2]=='|' && str[len-1]=='0'){
				//					mapheader->szMapName[len-2] = '\0';
				//				}
				mapheader->wID = ntohs(mapheader->wID);
				mapheader->wHeight = ntohs(mapheader->wHeight);
				mapheader->wWidth = ntohs(mapheader->wWidth);
				ret = TRUE;
			}
		}
		CloseHandle(hfile);
	}
	return ret;
}

/* 讀取石器地圖的資料 parameter: origin: 要讀入的地圖資料 filename:
地圖的檔名 width, height: 地圖的寬高 unitwideth, unitheight: 地圖的格子大小 return: 是否成功 */
BOOL ReadMapData(LPMAPORIGIN origin, LPCTSTR filename, int width, int height, int unitwidth, int unitheight)
{
	HANDLE	hfile;
	DWORD	readbyte;
	LPWORD	tiles, parts, tmp, tmp1;
	BOOL	ret = FALSE;
	int		i, j, size = width * height * 2;
	//ReleaseSaMap(origin);
	if (tiles = origin->lpwTileData = (LPWORD)VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE)) {
		if (parts = origin->lpwPartData = (LPWORD)VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE)) {
			if (origin->lpdwNpc = (LPDWORD)VirtualAlloc(NULL, size << 1, MEM_COMMIT, PAGE_READWRITE)) {
#ifdef _ANITILE         //ROG ADD 動態地表 //新地圖Ani記憶體配置
				if (origin->lpwAniTileData = (LPWORD)VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE)) {
#endif
					if (tmp1 = tmp = (LPWORD)VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE)) {
						
					
							if (INVALID_HANDLE_VALUE != (hfile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL))) {
								SetFilePointer(hfile, sizeof(MAPHEADER), NULL, FILE_BEGIN);
								if (ReadFile(hfile, tmp1, size, &readbyte, NULL)) {
									tiles += (width - 1);
									for (i = 0; i < height; i++) {
										for (j = 0; j < width; j++, tiles--, tmp1++)
											*tiles = ntohs(*tmp1);
										tiles += (width << 1);
									}
									tmp1 = tmp;
									if (ReadFile(hfile, tmp1, size, &readbyte, NULL)) {
										parts += (width - 1);
										for (i = 0; i < height; i++) {
											for (j = 0; j < width; j++, parts--, tmp1++)
												*parts = ntohs(*tmp1);
											parts += ((width << 1));
										}
										ret = TRUE;
									}
									//SetOrigin(origin, 0, 0, width, height, unitwidth, unitheight);
								}
								CloseHandle(hfile);
							}
						
						
						VirtualFree(tmp, NULL, MEM_RELEASE);
					}
#ifdef _ANITILE         //ROG ADD 笆篈
				}
#endif
			}
		}
	}
	/*
	if (!ret) {
		FreeAllUndo();
		ReleaseSaMap(origin);
	}
	*/
	return ret;
}

/* 從一個(x,y)的viewport點轉換成菱形格(tile)的座標 parameter: origin:
傳入viewport相對於tile座標的資料 x, y:
查詢viewport上某一點的座標 rx, ry: 傳回tile的座標 */
void View2Tile(LPMAPORIGIN origin, int x, int y, int* rx, int* ry)
{
	int		mx, my, h, w, h_2, w_2;
	h = origin->wUnitHeight;
	w = origin->wUnitWidth;
	h_2 = h >> 1;
	w_2 = w >> 1;
	x = x + origin->iViewStartX + w_2;
	y = y + origin->iViewStartY + h_2;
	__asm {
		mov		eax, x
		cdq
		mov		ebx, w
		idiv	ebx
		cmp		edx, 0
		jge		_GOTO
		dec		eax
		_GOTO : mov		mx, eax; 
		mov		x, edx; `
		mov		eax, y
		cdq
		mov		ebx, h
		idiv	ebx
		mov		my, eax
		mov		y, edx
	}
	*rx = my - mx;
	*ry = my + mx;
	if (x < 0)
		x = w + x;
	if (x > w_2) {
		x -= w_2;
		if (y > h_2) {
			y -= h_2;
			if ((x * h_2 / w_2) > (h_2 - y))
				*ry += 1;
		}
		else {
			if ((x * h_2 / w_2) > y)
				*rx -= 1;
		}
	}
	else {
		if (y > h_2) {
			y -= h_2;
			if ((x * h_2 / w_2) < y)
				*rx += 1;
		}
		else {
			if ((x * h_2 / w_2) < (h_2 - y))
				*ry -= 1;
		}
	}
}

void drawMap(void) {
	/*
	nowFloor = 2000;
	mapAreaX1 = 22;
	mapAreaY1 = 4;
	mapAreaX2 = 23;
	mapAreaY2 = 28;
	int tilesum = 28264;
	int objsum = 55321;
	int eventsum = 0;
	
	nowFloor = 2001;
	mapAreaX1 = 1;
	mapAreaY1 = 3;
	mapAreaX2 = 25;
	mapAreaY2 = 4;
	*/
	oldGx = -1, oldGy = -1;

	unsigned short tile[MAP_X_SIZE * MAP_Y_SIZE];
	unsigned short parts[MAP_X_SIZE * MAP_Y_SIZE];
	unsigned short event[MAP_X_SIZE * MAP_Y_SIZE];


	if (nowGx != oldGx || nowGy != oldGy)
	{
		if (readMap(nowFloor, mapAreaX1, mapAreaY1, mapAreaX2, mapAreaY2, tile, parts, event))
		{
			// hitMap[]????????
			readHitMap(mapAreaX1, mapAreaY1, mapAreaX2, mapAreaY2, tile, parts, event, &hitMap[0]);
		}
		else
			return;
	}
}


void mapCheckSum()
{
	int floor = 2001;
	int x1 = 1;
	int y1 = 3;
	int x2 = 25;
	int y2 = 4;
	int tileSum = 0;
	int partsSum = 14916;
	int eventSum = 0;


	int tilesum = 0, objsum = 0, eventsum = 0, databufferindex = 0, width = x2 - x1, height = y2 - y1, i, j;
	unsigned short tile[MAP_X_SIZE * MAP_Y_SIZE];
	unsigned short parts[MAP_X_SIZE * MAP_Y_SIZE];
	unsigned short event[MAP_X_SIZE * MAP_Y_SIZE];

	readMap(floor, x1, y1, x2, y2, tile, parts, event);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			event[i * width + j] &= 0x0fff;
	}
	tilesum = CheckCRC((unsigned char*)tile, 27 * 27 * sizeof(short));
	objsum = CheckCRC((unsigned char*)parts, 27 * 27 * sizeof(short));
	eventsum = CheckCRC((unsigned char*)event, 27 * 27 * sizeof(short));

	if (tileSum == tilesum && partsSum == objsum && eventSum == eventsum)
	{
		printf("AAA");
	}
}

void SetOrigin(LPMAPORIGIN origin, int tx, int ty, int tw, int th, int w, int h)
{
	origin->iOriginTileX = (tw + 1) * (w >> 1);
	origin->iOriginTileY = 6 * (h >> 1);
	origin->wUnitWidth = w;
	origin->wUnitHeight = h;
	origin->wTileW = tw;
	origin->wTileH = th;
	origin->iScrollX = 0;
	origin->iScrollY = 0;
	origin->iZoom = 0;
	SetTileOrigin(origin, tx, ty);
}

void SetTileOrigin(LPMAPORIGIN origin, int x, int y)
{
	int		mx, my;
	int		h, w;
	x -= origin->iOriginTileX;
	y -= origin->iOriginTileY;
	h = origin->wUnitHeight;
	w = origin->wUnitWidth;
	origin->iViewStartX = x;
	origin->iViewStartY = y;
	x += (w >> 1);
	y += (h >> 1);
	__asm {
		mov		eax, x
		cdq
		mov		ebx, w
		idiv	ebx
		cmp		edx, 0
		jge		_GOTO
		dec		eax
		_GOTO : mov		mx, eax; 坝计
		mov		x, edx; 緇计
		mov		eax, y
		cdq
		mov		ebx, h
		idiv	ebx
		mov		my, eax
		mov		y, edx
	}
	origin->iTileX = my - mx;
	origin->iTileY = my + mx;
	//	origin->iTileDx = x;
	//	origin->iTileDy = y;
}

void test() {
	//C2001|30|30|14|15
	//2009|40|60|12|36
	//int fl = 154;
	int fl = 154;
	int maxx = 85;
	int maxy = 35;
	/*
	int gx = 12;
	int gy = 30;
	moveStackGx = 16;
	moveStackGy = 30;
	///Case 1
	int gx = 17;
	int gy = 18;
	moveStackGx = 21;
	moveStackGy = 21;
	///Case 2
	int gx = 12;
	int gy = 30;
	moveStackGx = 16;
	moveStackGy = 30;
	
	int gx = 17;
	int gy = 21;
	moveStackGx = 18;
	moveStackGy = 24;

	int gx = 11;
	int gy = 50;
	moveStackGx = 11;
	moveStackGy = 12;
	*/
	//39 -  154; 1; 15; 2; 35;魔王竞技砨Z頦閃9礬靝m-?騋?燶畀UL?!H,�飷隮$C?(h'%z@縇J5硾専}丕9咫K)bo?亲?筙p盇腎定氉?宆,2,,,,,,,,,,,|,,,,,,,,,,鞤?汼榀P;
	// 38 - 154; 0; 15; 1; 35;
	//XZ 30,30 SIZE = 30*30 = 900， 0可行， 3NPC
	//255不可行 254黑色，
	FILE* fp;
	int fWidth = -1;
	int fHeight = -1;
	int parts = -1;
	if ((fp = fopen("E:\\Game\\NW\\map\\2001.dat", "rb")) != NULL) {
		fseek(fp, 0, SEEK_SET);
		fread(&fWidth, sizeof(int), 1, fp); //1-宽
		fread(&fHeight, sizeof(int), 1, fp);//2-高
		int i = 1;
		while (1){
		
			/*
			fread(&parts, sizeof(short) * 2, 1, fp);
			if (feof(fp))
			{
				printf("\nBBBBB");
				break;
			}
			printf("%d\n", parts);
			*/
		
			
			int c = fgetc(fp);
			if (feof(fp))
			{
				printf("\nBBBBB");
				break;
			}
			if (c == 254) {
				printf("h");
			}
			else if (c == 255) {
				printf("x");
			}
			else
			{
				printf("%d", c);
			}
			if (i == fWidth) {
				i = 1;
				printf("\n");
			}
			else
			{
			i++;
			}
			
		}
	}
	/*
	//-1.-1
	MAPHEADER	mapheader;
	MAPORIGIN m_MapOrigin;
	CString		str = "E:\\Game\\shiqiso107\\shiqiso\\map\\2001.dat";
	ReadMapHeader(str, &mapheader);
	ReadMapData(&m_MapOrigin, str, 64, 47, SURFACE_WIDTH, SURFACE_HEIGHT);
	int x = 11;
	int y = 12;
	int xx = -1;
	int yy = -1;
	SetOrigin(&m_MapOrigin, 0, 0, 20, 20, 30, 30);
	View2Tile(&m_MapOrigin, x, y, (int*)&xx, (int*)&yy);
	int gx = 13;
	int gy = 28;
	moveStackGx = 19;
	moveStackGy = 32;

	nowFloorGxSize = maxx;
	nowFloorGySize = maxy;

	char realBinName[256];
	char adrnBinName[256];
	strcpy(realBinName, REALBIN_DIR);
	strcpy(adrnBinName, ADRNBIN_DIR);

	initRealbinFileOpen(realBinName, adrnBinName);
	setMap(fl, gx, gy);
	createMap(fl, maxx, maxy);
	resetMap();
	drawMap();
	getRouteMap();

	
	if (moveRouteCnt > 0 && moveRouteCnt2 == 0)
	{
		_getMoveRoute2();
	}
	*/
	
	
}