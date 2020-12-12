#pragma once
#include <SDL.h>
#include "CTimer.h"
#include "CStateManage.h"
#include <vector>

using namespace std;

class CGame
{
private:
	//单例
	static CGame* s_pInstance;
	//游戏进行中
	bool m_bRunning = true;
	//窗口指针
	SDL_Window* m_pWindow;
	//渲染器指针
	SDL_Renderer* m_pRenderer;
	//游戏状态管理指针
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

	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); //初始化
	void HandleEvents(); //输入事件处理，包括鼠标、键盘、手柄等
	void Update();  //根据不同的事件对游戏状态或内容进行更新
	void Render();  //渲染，完成图像的绘制
	void Close();  //释放内存，结束

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	SDL_Window* getWindow() const { return m_pWindow; }
	CStateManage* getStateManage() const { return m_pGameStateManage; }

	bool Running() { return m_bRunning; }
	void Quit() { m_bRunning = false; }

	int getGameWidth() const { return m_gameWidth; }
	int getGameHeight() const { return m_gameHeight; }

};
