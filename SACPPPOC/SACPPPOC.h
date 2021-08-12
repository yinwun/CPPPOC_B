 #pragma once
#include "loadrealbin.h"
#include "sprmgr.h"

typedef struct {
	WORD type;
	WORD isencrypted;
	DWORD width;		//ͼƬ���
	DWORD height;		//ͼƬ�߶�
	DWORD datasize;		//ͼ�������ı����ܴ�С
	BYTE buf[3000];		//ָ��λͼ���ݵ�ָ��
	WORD buflen;		//λͼ���ݵĴ�С
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