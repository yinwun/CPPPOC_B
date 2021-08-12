#pragma once
#include <Windows.h>

typedef struct _APoint {
	int x; // x 坐标
	int y; // y 坐标
	int type; // 类型
	int f; // f = g + h
	int g;
	int h;
} APoint, * PAPoint;

enum APointType {
	APT_UNKNOWN, // 未知状态
	APT_BLOCKER, // 阻碍物
	APT_WALL, //墙
	APT_OPENED, // 开放列表中
	APT_CLOSED, // 关闭列表中
	APT_STARTPOINT, // 起始点
	APT_ENDPOINT // 结束点
};

class AStar {
public:
	AStar();
	~AStar();
private:
	PAPoint m_pAPointArr;
	int m_nAPointArrWidth;
	int m_nAPointArrHeight;
	PAPoint m_pStartPoint, m_pEndPoint, m_pCurPoint;
	char* m_pOldArr;
public:
	BOOL LoadMap();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	void SetCurrent(int x, int y);
	void SetOpened(int x, int y);
	void SetClosed(int x, int y);
	PAPoint CalcNextPoint(PAPoint ptCalc);
	void TestMap();
};