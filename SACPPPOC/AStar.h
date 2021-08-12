#pragma once
#include <Windows.h>

typedef struct _APoint {
	int x; // x ����
	int y; // y ����
	int type; // ����
	int f; // f = g + h
	int g;
	int h;
} APoint, * PAPoint;

enum APointType {
	APT_UNKNOWN, // δ֪״̬
	APT_BLOCKER, // �谭��
	APT_WALL, //ǽ
	APT_OPENED, // �����б���
	APT_CLOSED, // �ر��б���
	APT_STARTPOINT, // ��ʼ��
	APT_ENDPOINT // ������
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