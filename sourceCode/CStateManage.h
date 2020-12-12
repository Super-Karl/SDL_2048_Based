#pragma once

#include <vector>
#include "CState.h"
using namespace std;

class CStateManage
{
public:

    CStateManage() {}
    ~CStateManage() {}
    //�¼�����
    void inputHandle();
    //����
    void update();
    //��Ⱦ
    void render();
    //����״̬
    void pushState(CState* pState);
    //�ı�״̬
    void changeState(CState* pState);
    //����״̬
    void popState();
    //���
    void clean();

    vector<CState*>& getGameStates() { return m_gameStates; }

private:
    vector<CState*>m_gameStates;
};
