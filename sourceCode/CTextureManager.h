#pragma once

#include <iostream>
#include <string>
#include <map>
#include <SDL.h>
#include "CGame.h"
using namespace std;

class CTextureManager
{
private:

    CTextureManager() {}
    ~CTextureManager() {}

    map<string, SDL_Texture*> m_textureMap;

    static CTextureManager* s_pInstance;

public:

    static CTextureManager* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new CTextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    /*
    * 功能：图片加载
    * 参数：文件地址，用户自定义分配的ID（在后续渲染中作为标识符）
    */
    bool load(string fileName, string id);
    /*
    * 功能：添加纹理到纹理map，由load函数调用，不得直接使用
    */
    bool addTexture(string id, SDL_Texture* pTexture);
    /*
    * 功能：设置纹理名字为id的透明度
    * 参数：纹理的id，透明度值
    */
    void setAlpha(const std::string& id, const Uint8 new_alpha);
    /*
     * 功能：设置纹理名字为id的颜色
     * 参数：纹理的id，颜色的rbg值
    */
    void setColour(const std::string& id, const Uint8 red, const Uint8 green, const Uint8 blue);
    /*
    * 功能：清除纹理map
    */
    void clearTextureMap();
    /*
    * 功能：将名字为id的纹理从map中清除
    * 参数：纹理的id
    */
    void clearFromTextureMap(string id);
    /*
    * 功能：加载纹理到渲染器，用于渲染展示
    */
    void draw(string id/*纹理的id*/, int x/*纹理加载到屏幕上的横坐标*/, int y/*纹理加载到屏幕上的纵坐标*/,
        float angle = 0/*旋转角度*/, int width = -1/*纹理的宽度*/, int height = -1/*纹理的高度*/, 
        float alpha = 255/*透明度*/, SDL_RendererFlip flip = SDL_FLIP_NONE/*图片翻转*/);
    /*
    * 功能：加载纹理到渲染器，可自定义参数更多，在原图上截取一个子图片，以自定义方式展现在屏幕上
    */
    void drawSuper(string id/*纹理的id*/, int cutx/*在原图上开始截取的点的横坐标*/, 
        int cuty/*在原图上开始截取的点的纵坐标*/, int cutwidth/*原图上截取的宽度*/, int cutheight/*原图上截取的高度*/,
        int showx/*在屏幕上显示的横坐标*/, int showy/*在屏幕上显示的纵坐标*/, int showwidth/*在屏幕上显示的宽度*/, 
        int showheight/*在屏幕上显示的高度*/, float angle/*屏幕上显示角度*/, float alpha/*透明度*/, int rotx/*旋转中心的横坐标*/,
        int roty/*旋转中心的纵坐标*/, SDL_RendererFlip flip/*是否翻转*/);
    /*
    * 功能：在一张图片中进行切片，更改切片的位置，可以实现动图的显示效果
    */
    void drawFrame(string id/*纹理的id*/, int x/*显示在屏幕上的横坐标*/, int y/*显示在屏幕上的纵坐标*/,
        int width/*显示的宽度以及原图宽度*/, int height/*显示的高度以及原图高度*/, int currentRow/*所取切片的行*/,
        int currentFrame/*所取切片的列*/, double angle/*显示的角度*/, int alpha/*透明度*/, SDL_RendererFlip flip = SDL_FLIP_NONE/*翻转*/);
    /*
    * 功能：类似于上面一个函数，功能更简单
    */
    void drawTile(string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame);

    map<string, SDL_Texture*> getTextureMap() { return m_textureMap; }
};