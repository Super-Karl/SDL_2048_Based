#include "CTimer.h"
#include "CGame.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) 
{
    cout << "game init attempt...\n";
    if (CGame::Instance()->Init("2048", 100, 200, 540, 698, false))
    {
        cout << "game init success!\n";

		CTimer::Instance()->setFPS();
		CTimer::Instance()->StartTime();

        while (CGame::Instance()->Running())
        {
            //时间控制
            CTimer::Instance()->TimeContrler();
            //输入事件相应、更新、渲染
            CGame::Instance()->HandleEvents();
            CGame::Instance()->Update();
            CGame::Instance()->Render();
        }
    }
    else
    {
        cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }
    cout << "game closing...\n";
	CGame::Instance()->Close();

    return 0;
}