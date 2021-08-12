 #pragma once
#include "loadrealbin.h"
#include "sprmgr.h"

typedef struct {
	WORD type;
	WORD isencrypted;
	DWORD width;		//图片宽度
	DWORD height;		//图片高度
	DWORD datasize;		//图形数据文本的总大小
	BYTE buf[3000];		//指向位图数据的指针
	WORD buflen;		//位图数据的大小
}SS_IMAGECODE;

void RouteRoad(void);
void SS_DecryptImageCode(char* data, SS_IMAGECODE* imagecode);
unsigned int HexToDec(char* hex);
int RealToBmp(BYTE* Target, BYTE* Source, int RDDataLen);
static BOOL WriteBitmap565ToFile(const char* filename, int width, int height, unsigned char* bitmapData, int dateSize);
static BOOL WriteBitmap888ToFile(const char* filename, int width, int height, unsigned char* bitmapData, int dateSize);
bool simple_4ByteAlignment(int width, int height, unsigned char* bitmapData);
static BOOL WriteBitmap888ToFile(const char* filename, int width, int height, unsigned char* bitmapData, int dateSize);
static BOOL WriteBitmap565ToFile(const char* filename, int width, int height, unsigned char* bitmapData, int dateSize);
BOOL LoadMatixMap();
BOOL PrintMatrixMap();