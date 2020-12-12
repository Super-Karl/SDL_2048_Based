#include "CGame.h"
#include "CFontManager.h"
#include "CAudioManage.h"
#include "CTextureManager.h"
#include "CInputHandle.h"
#include "CState.h"
#include "CMenuState.h"
#include "CPlayState.h"
#include "CEndState.h"
CGame* CGame::s_pInstance = 0;

CGame::CGame():
	m_pWindow(0),
	m_pRenderer(0),
	m_bRunning(false)
{}

CGame::~CGame()
{
	m_pRenderer = 0;
	m_pWindow = 0;
}


bool CGame::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    //游戏界面的窗口大小
    m_gameWidth = width;
    m_gameHeight = height;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    //初始化SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL init success\n";
        // 初始化窗口
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (m_pWindow != 0) // 窗口初始化成功
        {
            cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

            if (m_pRenderer != 0) // 渲染器初始化成功
            {
                cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 240, 230, 213, 255);
            }
            else
            {
                cout << "renderer init fail\n";
                return false; // 渲染器初始化失败
            }
            // 初始化字体处理器
            if (TTF_Init() == -1)
            {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                return false;
            }
        }
        else
        {
            cout << "window init fail\n";
            return false; // 窗口创建失败
        }
    }
    else
    {
        cout << "SDL init fail\n";
        return false; // SDL 初始化失败
    }
    //所有组件初始化完成

    // 开始主菜单
    m_pGameStateManage = new CStateManage();
    m_pGameStateManage->pushState(new CMenuState());

    m_bRunning = true; // 所有初始化完成，跳转到主循环
    return true;
}

void CGame::HandleEvents()
{
    CInputHandle::Instance()->update();
    if (CInputHandle::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Quit();
    }
    m_pGameStateManage->inputHandle();
    
}

void CGame::Update()
{
    m_pGameStateManage->update();
}

void CGame::Render()
{
    m_pGameStateManage->render();
}

void CGame::Close()
{
    std::cout << "cleaning game" << std::endl;
    m_pGameStateManage->clean();
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}
