#pragma once

#include "CState.h"
#include "CObject.h"
#include "CButton.h"
#include <string>
#include <iostream>
using namespace std;

class CObject;

class CEndState :public CState
{
public:
    virtual ~CEndState() {}
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
    vector<CObject*> m_CSpriteList;
    static const string s_StateID;
};