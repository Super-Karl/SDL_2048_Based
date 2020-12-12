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
    //随机添加一个cell
    void addRandom();
    //新建board
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

