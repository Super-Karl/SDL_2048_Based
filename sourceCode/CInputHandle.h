/*
* 本文件为输入处理类，实现的主要功能为判断某个键是否按下、
* 获取当前鼠标位置、获取手柄状态
* @木笔
*/

#pragma once

#include <iostream>
#include <vector>

#include "SDL.h"
#include "Vector2D.h"
using namespace std;

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class CInputHandle
{
public:

    //创建一个对象
    static CInputHandle* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new CInputHandle();
        }

        return s_pInstance;
    }
    /*
    * 复位鼠标的按键状态为未按下
    * @木笔
    */
    void reset();
    /*
    * 更新SDL事件，实时获取键盘、鼠标的信息
    * @木笔
    */
    void update();

    /*
    * 判断键盘某个按键是否按下
    * 参数 SDL_Scancode key：要判断的键值
    * 返回值：true--按下，false--未按下   
    * @木笔
    */
    bool isKeyDown(SDL_Scancode key) const;

    /*
    * 获取鼠标按键状态
    * 参数 buttonNumber：要获取的鼠标按键的键值
    * @木笔
    */
    bool getMouseButtonState(int buttonNumber) const;
    
    /*
    * 获取鼠标位置
    * 返回值：鼠标当前位置
    * @木笔
    */
    Vector2D* getMousePosition() const;
    
    /*
    * 用户使用，判断键盘按键是否按下
    * 参数 keydown：要判断的值
    * 返回值：true--按下 false--未按下
    * @木笔
    */
    static bool ifKeyDown(SDL_Scancode keydown)
    {
        Instance()->update();
        if (Instance()->isKeyDown(keydown))
        {
            return true;
        }
        else
            return false;
    }
    
    /*
    * 用户使用，判断鼠标按键是否按下
    * 参数 buttonNumber：要判断的鼠标键值，左中右分别为 0 1 2
    * 返回值：true--按下 false--未按下
    * @木笔
    */
    static bool ifMouseDown(int buttonNumber)
    {
        if (Instance()->getMouseButtonState(buttonNumber))
            return true;
        else
            return false;
    }
   
    /*
    * 用户使用，获取鼠标位置
    * 返回值：鼠标当前的 X / Y 位置
    * @木笔
    */
    static float getMousePos_X()
    {
        Vector2D* m_pPos = Instance()->getMousePosition();
        return m_pPos->getX();
    }
    
    static float getMousePos_Y()
    {
        Vector2D* m_pPos = Instance()->getMousePosition();
        return m_pPos->getY();
    }
    /*
    * 用户使用，判断滚轮是否滚动
    * 参数 directionNum：滚轮转动方向  左上右下依次为 1 2 3 4
    */
    static bool ifMouseWheelAct(int directionNum)
    {
        bool m_mJudge = false;
        switch (directionNum)
        {
        case 1:
            if (Instance()->m_mouseWheelState_Left)
                m_mJudge = true;
            break;
        case 2:
            if (Instance()->m_mouseWheelState_Up)
                m_mJudge = true;
            break;
        case 3:
            if (Instance()->m_mouseWheelState_Right)
                m_mJudge = true;
            break;
        case 4:
            if (Instance()->m_mouseWheelState_Down)
                m_mJudge = true;
            break;
        default:
            break;
        }
        if (m_mJudge)
            return true;
        else
            return false;
    }

    CInputHandle();
    ~CInputHandle();
    /*
    * 键盘按下
    * @木笔
    */
    void onKeyDown();
    /*
    * 键盘弹起
    * @木笔
    */
    void onKeyUp();
    /*
    * 鼠标移动
    * 参数 SDL_Event& event：SDL事件
    * @木笔
    */
    void onMouseMove(SDL_Event& event);
    /*
    * 鼠标键按下
    * 参数 SDL_Event& event：SDL事件
    * @木笔
    */
    void onMouseButtonDown(SDL_Event& event);
    /*
    * 鼠标键弹起
    * 参数 SDL_Event& event：SDL事件
    * @木笔
    */
    void onMouseButtonUp(SDL_Event& event);
    /*
    * 鼠标滚轮滚动
    * 参数 SDL_Event& event：SDL事件
    * @木笔
    */
    void onMouseWheelAct(SDL_Event& event);
private:
    const Uint8* m_keystates;
    vector<bool> m_mouseButtonStates;
    bool m_mouseWheelState_Left;
    bool m_mouseWheelState_Right;
    bool m_mouseWheelState_Up;
    bool m_mouseWheelState_Down;
    Vector2D* m_mousePosition;
    static CInputHandle* s_pInstance;
};