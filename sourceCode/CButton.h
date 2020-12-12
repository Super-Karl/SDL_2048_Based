#pragma once
#include "CObject.h"
#include "Vector2D.h"
#include "enums.h"
#include "string.h"
using namespace std;

//class CObject;
class CButton: public CObject
{
public:

    CButton();
    //构造函数
    CButton(string fileName, string id, int x, int y, int width, int height);
    //加载
    void load(string fileName, string id, int x, int y, int width, int height);
    //绘制
    void draw();
    //更新
    void update();
    //清理
    void clean();
    //当前按钮状态
    button_state getCurrentFrame();

private:

    button_state m_currentFrame;
};
