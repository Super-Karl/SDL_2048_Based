/*
* ���ļ�Ϊ���봦���࣬ʵ�ֵ���Ҫ����Ϊ�ж�ĳ�����Ƿ��¡�
* ��ȡ��ǰ���λ�á���ȡ�ֱ�״̬
* @ľ��
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

    //����һ������
    static CInputHandle* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new CInputHandle();
        }

        return s_pInstance;
    }
    /*
    * ��λ���İ���״̬Ϊδ����
    * @ľ��
    */
    void reset();
    /*
    * ����SDL�¼���ʵʱ��ȡ���̡�������Ϣ
    * @ľ��
    */
    void update();

    /*
    * �жϼ���ĳ�������Ƿ���
    * ���� SDL_Scancode key��Ҫ�жϵļ�ֵ
    * ����ֵ��true--���£�false--δ����   
    * @ľ��
    */
    bool isKeyDown(SDL_Scancode key) const;

    /*
    * ��ȡ��갴��״̬
    * ���� buttonNumber��Ҫ��ȡ����갴���ļ�ֵ
    * @ľ��
    */
    bool getMouseButtonState(int buttonNumber) const;
    
    /*
    * ��ȡ���λ��
    * ����ֵ����굱ǰλ��
    * @ľ��
    */
    Vector2D* getMousePosition() const;
    
    /*
    * �û�ʹ�ã��жϼ��̰����Ƿ���
    * ���� keydown��Ҫ�жϵ�ֵ
    * ����ֵ��true--���� false--δ����
    * @ľ��
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
    * �û�ʹ�ã��ж���갴���Ƿ���
    * ���� buttonNumber��Ҫ�жϵ�����ֵ�������ҷֱ�Ϊ 0 1 2
    * ����ֵ��true--���� false--δ����
    * @ľ��
    */
    static bool ifMouseDown(int buttonNumber)
    {
        if (Instance()->getMouseButtonState(buttonNumber))
            return true;
        else
            return false;
    }
   
    /*
    * �û�ʹ�ã���ȡ���λ��
    * ����ֵ����굱ǰ�� X / Y λ��
    * @ľ��
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
    * �û�ʹ�ã��жϹ����Ƿ����
    * ���� directionNum������ת������  ������������Ϊ 1 2 3 4
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
    * ���̰���
    * @ľ��
    */
    void onKeyDown();
    /*
    * ���̵���
    * @ľ��
    */
    void onKeyUp();
    /*
    * ����ƶ�
    * ���� SDL_Event& event��SDL�¼�
    * @ľ��
    */
    void onMouseMove(SDL_Event& event);
    /*
    * ��������
    * ���� SDL_Event& event��SDL�¼�
    * @ľ��
    */
    void onMouseButtonDown(SDL_Event& event);
    /*
    * ��������
    * ���� SDL_Event& event��SDL�¼�
    * @ľ��
    */
    void onMouseButtonUp(SDL_Event& event);
    /*
    * �����ֹ���
    * ���� SDL_Event& event��SDL�¼�
    * @ľ��
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