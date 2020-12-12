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
    //����״̬
    virtual bool onEnter();
    //��ȡ����
    virtual void inputHandle();
    //����״̬
    virtual void update();
    //״̬��Ⱦ
    virtual void render();
    //�˳�״̬
    virtual bool onExit();
    //����״̬id
    virtual string getStateID();
    //���Ӿ���
    void addSprite(CObject* sprite);
    //ɾ������
    void deleteSprite(CObject* sprite);
private:
    static const string s_StateID;
    vector<CObject*> m_CSpriteList;
    vector<CButton*> m_CButtonList;
};