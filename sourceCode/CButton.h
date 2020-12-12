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
    //���캯��
    CButton(string fileName, string id, int x, int y, int width, int height);
    //����
    void load(string fileName, string id, int x, int y, int width, int height);
    //����
    void draw();
    //����
    void update();
    //����
    void clean();
    //��ǰ��ť״̬
    button_state getCurrentFrame();

private:

    button_state m_currentFrame;
};
