#include "CInputHandle.h"
#include "CGame.h"
#include <iostream>

CInputHandle* CInputHandle::s_pInstance = 0;

/*
* ���캯�������ü��̺����ĳ�ʼ��Ϣ
* @ľ��
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
* ��������
* @ľ��
*/
CInputHandle::~CInputHandle()
{
    // ɾ�����������ж�̬����
    delete m_keystates;
    delete m_mousePosition;
    m_mouseWheelState_Down = false;
    m_mouseWheelState_Up = false;
    m_mouseWheelState_Left = false;
    m_mouseWheelState_Right = false;
    // �������
    m_mouseButtonStates.clear();
}

/*
* ��λ���İ���״̬Ϊδ����
* @ľ��
*/
void CInputHandle::reset()
{
    m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}

/*
* �жϼ���ĳ�������Ƿ���
* ���� SDL_Scancode key��Ҫ�жϵļ�ֵ
* ����ֵ��true--���£�false--δ����
* @ľ��
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
* ��ȡ��갴��״̬
* ���� buttonNumber��Ҫ��ȡ����갴���ļ�ֵ
* @ľ��
*/
bool CInputHandle::getMouseButtonState(int buttonNumber) const
{
    return m_mouseButtonStates[buttonNumber];
}

/*
* ��ȡ���λ��
* ����ֵ����굱ǰλ��
* @ľ��
*/
Vector2D* CInputHandle::getMousePosition() const
{
    return m_mousePosition;
}

/*
* ����SDL�¼���ʵʱ��ȡ���̡�������Ϣ
* @ľ��
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
* ���̰���
* @ľ��
*/
void CInputHandle::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
* ���̵���
* @ľ��
*/
void CInputHandle::onKeyUp()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
* ����ƶ�
* ���� SDL_Event& event��SDL�¼�
* @ľ��
*/
void CInputHandle::onMouseMove(SDL_Event& event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

/*
* ��������
* ���� SDL_Event& event��SDL�¼�
* @ľ��
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
* ��������
* ���� SDL_Event& event��SDL�¼�
* @ľ��
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
* �����ֹ���
* ���� SDL_Event& event��SDL�¼�
* @ľ��
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