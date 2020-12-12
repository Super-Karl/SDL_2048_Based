#pragma once

#include "Vector2D.h"
#include "CObject.h"

/*
* ���ܣ��жϾ����Ƿ���ײ������ֵΪboolֵ
* ������AΪ����A�ľ���ָ�룬Bͬ��s_bufferΪ����ϵ������ǰ��߳���s_bufferΪ�������Ŀ��
*/
static bool IsCollision(CObject* A, CObject* B, int s_buffer = 4)
{
    int aHBuf = A->GetSpriteHeight() / s_buffer;
    int aWBuf = A->GetSpriteWidth() / s_buffer;

    int bHBuf = B->GetSpriteHeight() / s_buffer;
    int bWBuf = B->GetSpriteWidth() / s_buffer;

    if ((A->GetSpritePosition_Y() + A->GetSpriteHeight() - aHBuf <= B->GetSpritePosition_Y() + bHBuf)) { return false; }

    if (A->GetSpritePosition_Y() + aHBuf >= (B->GetSpritePosition_Y() + B->GetSpriteHeight() - bHBuf)) { return false; }

    if ((A->GetSpritePosition_X() + A->GetSpriteWidth()) - aWBuf <= B->GetSpritePosition_X() + bWBuf) { return false; }

    if (A->GetSpritePosition_X() + aWBuf >= (B->GetSpritePosition_X() + B->GetSpriteWidth()) - bWBuf) { return false; }

    return true;
}