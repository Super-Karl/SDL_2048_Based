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
    * 此函数用于进入该游戏状态时，对场景的布置，背景图的加载，精灵的创建。
    */
    virtual bool onEnter() = 0;

    /*
    * 此函数用于每次刷新时对输入事件的获取，根据输入写状态中对应的精灵的。
    * 属性改变，例如移动，旋转等等。
    */
    virtual void inputHandle() = 0;

    /*
    * 此函数用于每次刷新时，在输入事件处理完成后，对其他属性的固定刷新，
    * 例如：已经有速度的精灵在没有按键输入的情况下，每一帧也会有移动，需
    * 更新位置坐标等其他参数。
    */
    virtual void update() = 0;
    
    /*
    * 此函数用于在update()处理完后调用，对更新后的场景中的精灵等其他组件
    * 进行渲染。
    */
    virtual void render() = 0;
    
    /*
    * 此函数在退出该游戏状态时调用，对该游戏状态中的所有生成的组件，精灵
    * 进行销毁，释放内存。
    */
    virtual bool onExit() = 0;
    
    /*
    * 获取当前状态的标签
    */
    virtual string getStateID() = 0;
    
    /*
    * 获取当前状态的状态，是否需要结束
    */
    state_state getNowState()
    {
        return m_Nowstate;
    }
protected:
    state_state m_Nowstate;
};

