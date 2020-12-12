#include "CTimer.h"

CTimer* CTimer::s_pInstance = NULL;

CTimer::CTimer()
{
	start = SDL_GetTicks();
}

CTimer::~CTimer()
{

}


//功能:控制游戏帧数，锁帧
void CTimer::TimeContrler()
{
	toEnd = SDL_GetTicks() - start;
	if (toEnd < DELAY_TIME)
	{
		SDL_Delay((int)(DELAY_TIME - toEnd));
	}
	realFPS = 1000.0 / (double(SDL_GetTicks() - start));
	start = SDL_GetTicks();
	//printf("%d\n", int(SDL_GetTicks()) / 100);
}


//功能:获得实时帧数
double CTimer::GetRealFPS()
{
	return realFPS;
}


//功能:设置帧数
void CTimer::setFPS()
{
	FPS = 60.0;
	DELAY_TIME = 1000.0 / FPS;
}


//功能:开始游戏计时
void CTimer::StartTime()
{
	start = SDL_GetTicks();
}
//返回从开始游戏到现在的毫秒时间
Uint32 CTimer::GetNowTime()
{
	return SDL_GetTicks();
}

//Time为一个周期所花的时间单位为豪秒,Times为周期中输出的次数
//功能，在Time时间内按顺序输出0~（Times-1）序列
int CTimer::Timer(int Time, int Times)
{
	return int((SDL_GetTicks() * Times / (Time)) % Times);
}
