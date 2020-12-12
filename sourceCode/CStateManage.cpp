#include "CStateManage.h"
#include "CPlayState.h"
#include "CMenuState.h"
#include "CEndState.h"
#include <iostream>
using namespace std;

void CStateManage::inputHandle()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->inputHandle();
    }
}

void CStateManage::update()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->update();
        if (m_gameStates.back()->getNowState() == DYING && m_gameStates.back()->getStateID()=="MENUSTATE")
        {
            changeState(new CPlayState());
        }
        if (m_gameStates.back()->getNowState() == DYING && m_gameStates.back()->getStateID() == "PLAYSTATE")
        {
            changeState(new CEndState());
        }
    }
}

void CStateManage::render()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}

void CStateManage::pushState(CState* pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void CStateManage::popState()
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

void CStateManage::changeState(CState* pState)
{
    if (!m_gameStates.empty())
    {
        if (m_gameStates.back()->getStateID() == pState->getStateID())
        {
            return;
        }

        if (m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

    // 初始化状态
    pState->onEnter();

    // 推入新状态
    m_gameStates.push_back(pState);
}

void CStateManage::clean()
{
    if (!m_gameStates.empty())
    {
        for (vector<CState*>::iterator i = m_gameStates.begin(); i != m_gameStates.end(); i++)
        {
            (*i)->onExit();
            delete* i;
        }
        m_gameStates.clear();
    }
}