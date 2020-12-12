#pragma once

#include "CState.h"
#include "CObject.h"
#include "CButton.h"
#include "CCell.h"
#include "enums.h"
#include <string>
#include <iostream>
using namespace std;

typedef CCell* cell;
typedef cell** Board;

class CPlayState:public CState
{
public:
    virtual ~CPlayState() {}
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
    //������һ��cell
    void addRandom();
    //�½�board
    Board newBoard();
    int moveUp();
    int moveDown();
    int moveLeft();
    int moveRight();
    bool cantmove();
private:
    Vector2D block[4][4];
    Board board;
    vector<CObject*> m_CSpriteList;
    static const string s_StateID;
    CButton* button;
    bool moveSuccess;
    bool finishedGame;
    int maxNum;
    int score;
    int highestScore;
};

