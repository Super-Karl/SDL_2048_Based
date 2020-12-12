#include "CTimer.h"

CTimer* CTimer::s_pInstance = NULL;

CTimer::CTimer()
{
	start = SDL_GetTicks();
}

CTimer::~CTimer()
{

}


//����:������Ϸ֡������֡
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


//����:���ʵʱ֡��
double CTimer::GetRealFPS()
{
	return realFPS;
}


//����:����֡��
void CTimer::setFPS()
{
	FPS = 60.0;
	DELAY_TIME = 1000.0 / FPS;
}


//����:��ʼ��Ϸ��ʱ
void CTimer::StartTime()
{
	start = SDL_GetTicks();
}
//���شӿ�ʼ��Ϸ�����ڵĺ���ʱ��
Uint32 CTimer::GetNowTime()
{
	return SDL_GetTicks();
}

//TimeΪһ������������ʱ�䵥λΪ����,TimesΪ����������Ĵ���
//���ܣ���Timeʱ���ڰ�˳�����0~��Times-1������
int CTimer::Timer(int Time, int Times)
{
	return int((SDL_GetTicks() * Times / (Time)) % Times);
}
