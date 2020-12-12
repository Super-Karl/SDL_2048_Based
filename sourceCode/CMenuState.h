#pragma once

#include "CState.h"
#include "CObject.h"
#include "CButton.h"
#include "CGame.h"
#include <string>
#include <iostream>
using namespace std;

class CMenuState :public CState
{
public:
    virtual ~CMenuState() {}
    //进入状态
    virtual bool onEnter();
    //获取操作
    virtual void inputHandle();
    //更新状态
    virtual void update();
    //状态渲染
    virtual void render();
    //退出状态
    virtual bool onExit();
    //返回状态id
    virtual string getStateID();
    //增加精灵
    void addSprite(CObject* sprite);
    //删除精灵
    void deleteSprite(CObject* sprite);
private:
    static const string s_StateID;
    vector<CObject*> m_CSpriteList;
    vector<CButton*> m_CButtonList;
};