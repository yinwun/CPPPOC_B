#include "AStar.h"
#include<stdio.h>

AStar::AStar() {
	m_pAPointArr = NULL;
	m_nAPointArrWidth = 0;
	m_nAPointArrHeight = 0;

	m_pStartPoint = NULL;
	m_pEndPoint = NULL;
	m_pCurPoint = NULL;
}

AStar::~AStar() {

}

BOOL AStar::LoadMap() {
	FILE* fp;
	int fWidth = -1;
	int fHeight = -1;
	char path[1024] = { 0 };
	memset(path, 0, sizeof(path));
	strcpy(path, "E:\\Game\\NW\\map\\2001.dat");
	if ((fp = fopen(path, "rb")) == NULL) {
		return FALSE;
	}

	//Get Width, Height
	fseek(fp, 0, SEEK_SET);
	fread(&fWidth, sizeof(int), 1, fp); //1-宽
	fread(&fHeight, sizeof(int), 1, fp);//2-高

	if (fWidth < 1 || fHeight < 1) {
		return FALSE;
	}

	m_pAPointArr = new APoint[fWidth * fHeight];
	if (!m_pAPointArr) return FALSE;

	m_nAPointArrWidth = fWidth;
	m_nAPointArrHeight = fHeight;

	int x = 0;
	int y = 0;
	while (1) {
		int c = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		if (c == 254) {
			m_pAPointArr[y * m_nAPointArrWidth + x].type = APT_BLOCKER;
		}
		else if (c == 255) {
			m_pAPointArr[y * m_nAPointArrWidth + x].type = APT_WALL;
		}
		else
		{
			m_pAPointArr[y * m_nAPointArrWidth + x].type = APT_OPENED;;
		}
		m_pAPointArr[y * m_nAPointArrWidth + x].x = x;
		m_pAPointArr[y * m_nAPointArrWidth + x].y = y;
		m_pAPointArr[y * m_nAPointArrWidth + x].g = 0;
		m_pAPointArr[y * m_nAPointArrWidth + x].f = 0;
		m_pAPointArr[y * m_nAPointArrWidth + x].h = 0;
		if (x == fWidth - 1) {
			x = 0;
			y++;
		}
		else {
			x++;
		}
		
		
	}
	fclose(fp);
	return TRUE;
}

void AStar::SetStartPoint(int x, int y) {
	if (m_pStartPoint && m_pAPointArr[y * m_nAPointArrWidth + x].type != APT_CLOSED)
	{
		m_pStartPoint->type = APT_OPENED;
		// 设置新的值
		m_pStartPoint = m_pAPointArr + y * m_nAPointArrWidth + x;
		m_pStartPoint->type = APT_STARTPOINT;
		m_pCurPoint = m_pStartPoint;
	}

}

void AStar::SetEndPoint(int x, int y)
{
	if (m_pStartPoint && m_pAPointArr[y * m_nAPointArrWidth + x].type != APT_CLOSED)
	{
		m_pStartPoint->type = APT_OPENED;
		// 设置新的值
		m_pStartPoint = m_pAPointArr + y * m_nAPointArrWidth + x;
		m_pStartPoint->type = APT_ENDPOINT;
	}
}


void AStar::SetCurrent(int x, int y)
{
	m_pCurPoint = m_pAPointArr + y * m_nAPointArrWidth + x;
}

void AStar::SetOpened(int x, int y)
{
	if (m_pAPointArr[y * m_nAPointArrWidth + x].type != APT_OPENED)
	{
		m_pAPointArr[y * m_nAPointArrWidth + x].type = APT_OPENED;
	}
}

void AStar::SetClosed(int x, int y)
{
	if (m_pAPointArr[y * m_nAPointArrWidth + x].type != APT_CLOSED)
	{
		m_pAPointArr[y * m_nAPointArrWidth + x].type = APT_CLOSED;
	}
}


PAPoint AStar::CalcNextPoint(PAPoint ptCalc)
{
	if (ptCalc == NULL)
	{
		ptCalc = m_pStartPoint;
	}

	int x = ptCalc->x;
	int y = ptCalc->y;
	int dx = m_pEndPoint->x;
	int dy = m_pEndPoint->y;
	int xmin = x, ymin = y, vmin = 0; // 最优步骤的坐标和

	// 判断是否已经到了最终的位置
	if ((x == dx && abs(y - dy) == 1) || (y == dy && abs(x - dx) == 1))
	{
		return m_pEndPoint;
	}

	//Up, 1
	if (m_pAPointArr[(x + 0) + m_nAPointArrWidth * (y - 1)].type == APT_OPENED && y > 0)
	{

	}
}


void AStar::TestMap() {
	FILE* fp;
	int fWidth = -1;
	int fHeight = -1;
	char path[1024] = { 0 };
	memset(path, 0, sizeof(path));
	strcpy(path, "E:\\Game\\NW\\map\\2001.dat");
	if ((fp = fopen(path, "rb")) == NULL) {
		return;
	}

	//Get Width, Height
	fseek(fp, 0, SEEK_SET);
	fread(&fWidth, sizeof(int), 1, fp); //1-宽
	fread(&fHeight, sizeof(int), 1, fp);//2-高

	if (fWidth < 1 || fHeight < 1) {
		return ;
	}

	m_nAPointArrWidth = fWidth;
	m_nAPointArrHeight = fHeight;

	int x = 0;
	int y = 0;
	int i = 0;
	while (1) {
		int c = fgetc(fp);
		if (feof(fp))
		{
			break;
		}

		if (m_pAPointArr[y * m_nAPointArrWidth + x].type == APT_BLOCKER) {
			printf("h");
		}
		else if (m_pAPointArr[y * m_nAPointArrWidth + x].type == APT_WALL) {
			printf("x");
		}
		else {
			printf("%d", c);
		}

		if (x == fWidth - 1) {
			x = 0;
			y++;
			printf("\n");
		}
		else {
			x++;
		}

		
	}
	fclose(fp);
}