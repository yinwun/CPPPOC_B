#include "loadrealbin.h"



unsigned long bitmapnumbertable[MAX_GRAPHICS];
ADRNBIN adrnbuff[MAX_GRAPHICS];
#ifdef _PTTERN_SEPARATION_BIN
extern int MaxAdrnID;
FILE* Realbinfp[MAX_GRAPHICS] = { NULL };
#else
FILE* Realbinfp;
#endif
FILE* Addrbinfp;

BOOL realGetNo(U4 CharAction, U4* GraphicNo)
{
#ifndef _READ16BITBMP
	if (CharAction < 0 || CharAction >= MAX_GRAPHICS) { *GraphicNo = 0; return FALSE; }
	*GraphicNo = bitmapnumbertable[CharAction];
	return TRUE;
#else
	if (CharAction < 0) {
		*GraphicNo = 0;
		return FALSE;
	}
	if (CharAction >= OLD_GRAPHICS_START) {
		if (CharAction >= MAX_GRAPHICS) {
			*GraphicNo = 0;
			return FALSE;
		}
		*GraphicNo = CharAction;
		return TRUE;
	}
	else *GraphicNo = bitmapnumbertable[CharAction];
	return TRUE;
#endif
}

BOOL realGetHitFlag(U4 GraphicNo, S2* Hit)
{
	if (GraphicNo < 0 || GraphicNo >= MAX_GRAPHICS) {
		*Hit = 0;
		return FALSE;
	}

	if ((GraphicNo >= 369715 && GraphicNo <= 369847) || GraphicNo == 369941)//强制地表可走
		*Hit = 1;
	else if (GraphicNo >= 369641 && GraphicNo <= 369654)
		*Hit = 1;
	else
		*Hit = (adrnbuff[GraphicNo].attr.hit % 100);

	return TRUE;
}

BOOL realGetHitPoints(U4 GraphicNo, S2* HitX, S2* HitY)
{
	if (GraphicNo < 0 || GraphicNo >= MAX_GRAPHICS) { *HitX = 0; *HitY = 0; return FALSE; }

	*HitX = adrnbuff[GraphicNo].attr.atari_x;
	*HitY = adrnbuff[GraphicNo].attr.atari_y;

	return TRUE;
}


BOOL initRealbinFileOpen(char* realbinfilename, char* addrbinfilename)
{
	ADRNBIN tmpadrnbuff;
	if ((Addrbinfp = fopen(addrbinfilename, "rb")) == NULL)
		return FALSE;
#ifdef _PTTERN_SEPARATION_BIN
	FILE* Realfp;
	if ((Realfp = fopen(realbinfilename, "rb")) == NULL)
		return FALSE;
#else
	if ((fopen_s(&Realbinfp, realbinfilename, "rb")) != NULL)
		return FALSE;
#endif
	//adrn.bin
	while (!feof(Addrbinfp)) {
		fread(&tmpadrnbuff, sizeof(tmpadrnbuff), 1, Addrbinfp);
		adrnbuff[tmpadrnbuff.bitmapno] = tmpadrnbuff;

#ifdef _PTTERN_SEPARATION_BIN
		Realbinfp[tmpadrnbuff.bitmapno] = Realfp;
		if ((ULONG)MaxAdrnID < tmpadrnbuff.bitmapno) {
			MaxAdrnID = tmpadrnbuff.bitmapno;
		}
#endif
		if (tmpadrnbuff.attr.bmpnumber != 0) {
			if ((12802 <= tmpadrnbuff.attr.bmpnumber && tmpadrnbuff.attr.bmpnumber <= 12811)
				|| (10132 <= tmpadrnbuff.attr.bmpnumber && tmpadrnbuff.attr.bmpnumber <= 10136)) {
				adrnbuff[tmpadrnbuff.bitmapno].attr.hit =
					300 + (adrnbuff[tmpadrnbuff.bitmapno].attr.hit % 100);
			}
			if (tmpadrnbuff.attr.bmpnumber <= 33 && tmpadrnbuff.bitmapno > 230000) {//防堵魔法图号覆盖声音的bug
				continue;
			}
			if (tmpadrnbuff.bitmapno == 2001) {
				printf("A");
			}
			bitmapnumbertable[tmpadrnbuff.attr.bmpnumber] = tmpadrnbuff.bitmapno;
		}
		else
			bitmapnumbertable[tmpadrnbuff.attr.bmpnumber] = 0;
	}
	fclose(Addrbinfp);
	return TRUE;
}