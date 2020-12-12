#pragma once

#include <string>
#include <vector>
#include <list>
#include "enums.h"
using namespace std;

class CState
{
public:
    CState() = default;
    virtual ~CState() {}
    /*
    * �˺������ڽ������Ϸ״̬ʱ���Գ����Ĳ��ã�����ͼ�ļ��أ�����Ĵ�����
    */
    virtual bool onEnter() = 0;

    /*
    * �˺�������ÿ��ˢ��ʱ�������¼��Ļ�ȡ����������д״̬�ж�Ӧ�ľ���ġ�
    * ���Ըı䣬�����ƶ�����ת�ȵȡ�
    */
    virtual void inputHandle() = 0;

    /*
    * �˺�������ÿ��ˢ��ʱ���������¼�������ɺ󣬶��������ԵĹ̶�ˢ�£�
    * ���磺�Ѿ����ٶȵľ�����û�а������������£�ÿһ֡Ҳ�����ƶ�����
    * ����λ�����������������
    */
    virtual void update() = 0;
    
    /*
    * �˺���������update()���������ã��Ը��º�ĳ����еľ�����������
    * ������Ⱦ��
    */
    virtual void render() = 0;
    
    /*
    * �˺������˳�����Ϸ״̬ʱ���ã��Ը���Ϸ״̬�е��������ɵ����������
    * �������٣��ͷ��ڴ档
    */
    virtual bool onExit() = 0;
    
    /*
    * ��ȡ��ǰ״̬�ı�ǩ
    */
    virtual string getStateID() = 0;
    
    /*
    * ��ȡ��ǰ״̬��״̬���Ƿ���Ҫ����
    */
    state_state getNowState()
    {
        return m_Nowstate;
    }
protected:
    state_state m_Nowstate;
};

