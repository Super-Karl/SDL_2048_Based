#pragma once

#include <vector>
#include "CState.h"
using namespace std;

class CStateManage
{
public:

    CStateManage() {}
    ~CStateManage() {}
    //事件输入
    void inputHandle();
    //加载
    void update();
    //渲染
    void render();
    //推入状态
    void pushState(CState* pState);
    //改变状态
    void changeState(CState* pState);
    //弹出状态
    void popState();
    //清除
    void clean();

    vector<CState*>& getGameStates() { return m_gameStates; }

private:
    vector<CState*>m_gameStates;
};
