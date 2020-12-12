#pragma once
#include "CObject.h"
#include "CTextureManager.h"
#include "Vector2D.h"
#include "CInputHandle.h"
#include "CState.h"


class CCell :public CObject
{
public:
    CCell();
    CCell(string fileName, string id, int x, int y, int width = -1, int height = -1);
    void load(string fileName, string id, int x, int y, int width = -1, int height = -1);
    //绘制
    void draw();
    //更新
    void update();
    //清理
    void clean();
};