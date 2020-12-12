#pragma once
#include <iostream>
#include <SDL.h>
using namespace std;

class CTimer
{
private:
	//������Ϸ֡�ʣ�FPS��
	double FPS;
	int DELAY_TIME;
	double realFPS;
	//����ȫ�ֶ���
	static CTimer* s_pInstance;
	//��ʼʱ�䣬�����������¼���Ĺ���ʱ��
	Uint32 start;
	Uint32 toEnd;
	//���ع��캯������������
	CTimer();
	~CTimer();
public:

	static CTimer* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new CTimer();
		return s_pInstance;
	}
	
	void TimeContrler();	//����֡��
	double GetRealFPS();	//����ʵ��֡��
	void setFPS();			//������Ϸ֡��
	void StartTime();       //��ʼ��Ϸ���ó�ʼʱ��
	Uint32 GetNowTime();	//���شӿ�ʼ��Ϸ�����ڵĺ�����
	int Timer(int Time,int Times); //��ʱ��
};