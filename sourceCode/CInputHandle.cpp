#include "CInputHandle.h"
#include "CGame.h"
#include <iostream>

CInputHandle* CInputHandle::s_pInstance = 0;

/*
* 构造函数，设置键盘和鼠标的初始信息
* @木笔
*/
CInputHandle::CInputHandle() : m_keystates(0),
m_mousePosition(new Vector2D(0, 0))
{
    for (int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}

/*
* 析构函数
* @木笔
*/
CInputHandle::~CInputHandle()
{
    // 删除创建的所有动态对象
    delete m_keystates;
    delete m_mousePosition;
    m_mouseWheelState_Down = false;
    m_mouseWheelState_Up = false;
    m_mouseWheelState_Left = false;
    m_mouseWheelState_Right = false;
    // 清除数组
    m_mouseButtonStates.clear();
}

/*
* 复位鼠标的按键状态为未按下
* @木笔
*/
void CInputHandle::reset()
{
    m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}

/*
* 判断键盘某个按键是否按下
* 参数 SDL_Scancode key：要判断的键值
* 返回值：true--按下，false--未按下
* @木笔
*/
bool CInputHandle::isKeyDown(SDL_Scancode key) const
{
    if (m_keystates != 0)
    {
        if (m_keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

/*
* 获取鼠标按键状态
* 参数 buttonNumber：要获取的鼠标按键的键值
* @木笔
*/
bool CInputHandle::getMouseButtonState(int buttonNumber) const
{
    return m_mouseButtonStates[buttonNumber];
}

/*
* 获取鼠标位置
* 返回值：鼠标当前位置
* @木笔
*/
Vector2D* CInputHandle::getMousePosition() const
{
    return m_mousePosition;
}

/*
* 更新SDL事件，实时获取键盘、鼠标的信息
* @木笔
*/
void CInputHandle::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            CGame::Instance()->Quit();
            break;

        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;

        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;

        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
            break;

        case SDL_MOUSEWHEEL:
            onMouseWheelAct(event);
            break;

        case SDL_KEYDOWN:
            onKeyDown();
            break;

        case SDL_KEYUP:
            onKeyUp();
            break;

        default:
            break;
        }
    }
}

/*
* 键盘按下
* @木笔
*/
void CInputHandle::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
* 键盘弹起
* @木笔
*/
void CInputHandle::onKeyUp()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
* 鼠标移动
* 参数 SDL_Event& event：SDL事件
* @木笔
*/
void CInputHandle::onMouseMove(SDL_Event& event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

/*
* 鼠标键按下
* 参数 SDL_Event& event：SDL事件
* @木笔
*/
void CInputHandle::onMouseButtonDown(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }

    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }

    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}

/*
* 鼠标键弹起
* 参数 SDL_Event& event：SDL事件
* @木笔
*/
void CInputHandle::onMouseButtonUp(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }

    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }

    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

/*
* 鼠标滚轮滚动
* 参数 SDL_Event& event：SDL事件
* @木笔
*/
void CInputHandle::onMouseWheelAct(SDL_Event& event)
{
    if (event.wheel.x > 0)
    {
        m_mouseWheelState_Left = true;
    }
    else if (event.wheel.x < 0)
    {
        m_mouseWheelState_Right = true;
    }
    else
    {
        m_mouseWheelState_Left = false;
        m_mouseWheelState_Right = false;
    }
    if (event.wheel.y > 0)
    {
        m_mouseWheelState_Up = true;
    }
    else if (event.wheel.y < 0)
    {
        m_mouseWheelState_Down = true;
    }
    else
    {
        m_mouseWheelState_Up = false;
        m_mouseWheelState_Down = false;
    }

}