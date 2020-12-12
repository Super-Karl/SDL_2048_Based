#pragma once
#include <iostream>
#include <SDL.h>
using namespace std;

class CTimer
{
private:
	//设置游戏帧率（FPS）
	double FPS;
	int DELAY_TIME;
	double realFPS;
	//单例全局对象
	static CTimer* s_pInstance;
	//开始时间，处理完所有事件后的过程时间
	Uint32 start;
	Uint32 toEnd;
	//隐藏构造函数和析构函数
	CTimer();
	~CTimer();
public:

	static CTimer* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new CTimer();
		return s_pInstance;
	}
	
	void TimeContrler();	//控制帧数
	double GetRealFPS();	//返回实际帧数
	void setFPS();			//设置游戏帧数
	void StartTime();       //开始游戏设置初始时间
	Uint32 GetNowTime();	//返回从开始游戏到现在的毫秒数
	int Timer(int Time,int Times); //计时器
};