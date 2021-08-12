#include "tool.h"

unsigned int TimeGetTime(void)
{
#ifdef _TIME_GET_TIME
	static __int64 time;
	QueryPerformanceCounter(&CurrentTick);
	return (unsigned int)(time = CurrentTick.QuadPart / tickCount.QuadPart);
	//return GetTickCount();
#else
	return 0;
	//return GetTickCount();
	//return timeGetTime();
#endif
}