#include "PC.h"

PC pc;

void setPcDir(int dir)
{
	pc.dir = dir;

	if (pc.ptAct == NULL)
		return;

	pc.ptAct->anim_ang = dir;
}