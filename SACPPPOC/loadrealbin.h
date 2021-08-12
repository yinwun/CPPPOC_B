#pragma once

#include <Windows.h>
#include"sprmgr.h"
#include <iostream>

typedef          short S2;
typedef unsigned long U4;

typedef struct {
	unsigned char atari_x, atari_y;	//¢†??
	unsigned short hit;				// ¿É·ñÐÐ×ß //¨÷???
	short height;				//?????
	short broken;				//????
	short indamage;				//¦VHP????
	short outdamage;			//üÒ????
	short inpoison;				//¦V¥€
	short innumb;				//¦V???
	short inquiet;				//¦V£œ?
	short instone;				//¦Vþð?
	short indark;				//¦V??
	short inconfuse;			//¦V??
	short outpoison;			//üÒ¥€
	short outnumb;				//üÒ??
	short outquiet;				//üÒ£œ?
	short outstone;				//üÒþð?
	short outdark;				//üÒ??
	short outconfuse;			//üÒ??
	short effect1;				//?????1??þ????????þ?????
	short effect2;				//?????2?¦V???????þ?????
	unsigned short damy_a;
	unsigned short damy_b;
	unsigned short damy_c;
	unsigned int bmpnumber;		//??§k?
} MAP_ATTR;

struct ADRNBIN {
	unsigned long	bitmapno;
	unsigned long	adder;
	unsigned long	size;
	int	xoffset;
	int	yoffset;
	unsigned int width;
	unsigned int height;
	MAP_ATTR attr;
};

BOOL realGetNo(U4 CharAction, U4* GraphicNo);
BOOL realGetHitFlag(U4 GraphicNo, S2* Hit);
BOOL realGetHitPoints(U4 GraphicNo, S2* HitX, S2* HitY);
BOOL initRealbinFileOpen(char* realbinfilename, char* addrbinfilename);