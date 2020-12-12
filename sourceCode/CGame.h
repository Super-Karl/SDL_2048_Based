#pragma once
#include <SDL.h>
#include "CTimer.h"
#include "CStateManage.h"
#include <vector>

using namespace std;

class CGame
{
private:
	//����
	static CGame* s_pInstance;
	//��Ϸ������
	bool m_bRunning = true;
	//����ָ��
	SDL_Window* m_pWindow;
	//��Ⱦ��ָ��
	SDL_Renderer* m_pRenderer;
	//��Ϸ״̬����ָ��
	CStateManage* m_pGameStateManage;

	int m_gameWidth;
	int m_gameHeight;

	CGame();
	~CGame();

public:
	static CGame* Instance()
	{
		if (s_pInstance == NULL)
		{
			s_pInstance = new CGame();
		}
		return s_pInstance;
	}

	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); //��ʼ��
	void HandleEvents(); //�����¼�����������ꡢ���̡��ֱ���
	void Update();  //���ݲ�ͬ���¼�����Ϸ״̬�����ݽ��и���
	void Render();  //��Ⱦ�����ͼ��Ļ���
	void Close();  //�ͷ��ڴ棬����

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	SDL_Window* getWindow() const { return m_pWindow; }
	CStateManage* getStateManage() const { return m_pGameStateManage; }

	bool Running() { return m_bRunning; }
	void Quit() { m_bRunning = false; }

	int getGameWidth() const { return m_gameWidth; }
	int getGameHeight() const { return m_gameHeight; }

};
