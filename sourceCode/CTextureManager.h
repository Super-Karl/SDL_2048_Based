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
    * ���ܣ�ͼƬ����
    * �������ļ���ַ���û��Զ�������ID���ں�����Ⱦ����Ϊ��ʶ����
    */
    bool load(string fileName, string id);
    /*
    * ���ܣ������������map����load�������ã�����ֱ��ʹ��
    */
    bool addTexture(string id, SDL_Texture* pTexture);
    /*
    * ���ܣ�������������Ϊid��͸����
    * �����������id��͸����ֵ
    */
    void setAlpha(const std::string& id, const Uint8 new_alpha);
    /*
     * ���ܣ�������������Ϊid����ɫ
     * �����������id����ɫ��rbgֵ
    */
    void setColour(const std::string& id, const Uint8 red, const Uint8 green, const Uint8 blue);
    /*
    * ���ܣ��������map
    */
    void clearTextureMap();
    /*
    * ���ܣ�������Ϊid�������map�����
    * �����������id
    */
    void clearFromTextureMap(string id);
    /*
    * ���ܣ�����������Ⱦ����������Ⱦչʾ
    */
    void draw(string id/*�����id*/, int x/*������ص���Ļ�ϵĺ�����*/, int y/*������ص���Ļ�ϵ�������*/,
        float angle = 0/*��ת�Ƕ�*/, int width = -1/*����Ŀ��*/, int height = -1/*����ĸ߶�*/, 
        float alpha = 255/*͸����*/, SDL_RendererFlip flip = SDL_FLIP_NONE/*ͼƬ��ת*/);
    /*
    * ���ܣ�����������Ⱦ�������Զ���������࣬��ԭͼ�Ͻ�ȡһ����ͼƬ�����Զ��巽ʽչ������Ļ��
    */
    void drawSuper(string id/*�����id*/, int cutx/*��ԭͼ�Ͽ�ʼ��ȡ�ĵ�ĺ�����*/, 
        int cuty/*��ԭͼ�Ͽ�ʼ��ȡ�ĵ��������*/, int cutwidth/*ԭͼ�Ͻ�ȡ�Ŀ��*/, int cutheight/*ԭͼ�Ͻ�ȡ�ĸ߶�*/,
        int showx/*����Ļ����ʾ�ĺ�����*/, int showy/*����Ļ����ʾ��������*/, int showwidth/*����Ļ����ʾ�Ŀ��*/, 
        int showheight/*����Ļ����ʾ�ĸ߶�*/, float angle/*��Ļ����ʾ�Ƕ�*/, float alpha/*͸����*/, int rotx/*��ת���ĵĺ�����*/,
        int roty/*��ת���ĵ�������*/, SDL_RendererFlip flip/*�Ƿ�ת*/);
    /*
    * ���ܣ���һ��ͼƬ�н�����Ƭ��������Ƭ��λ�ã�����ʵ�ֶ�ͼ����ʾЧ��
    */
    void drawFrame(string id/*�����id*/, int x/*��ʾ����Ļ�ϵĺ�����*/, int y/*��ʾ����Ļ�ϵ�������*/,
        int width/*��ʾ�Ŀ���Լ�ԭͼ���*/, int height/*��ʾ�ĸ߶��Լ�ԭͼ�߶�*/, int currentRow/*��ȡ��Ƭ����*/,
        int currentFrame/*��ȡ��Ƭ����*/, double angle/*��ʾ�ĽǶ�*/, int alpha/*͸����*/, SDL_RendererFlip flip = SDL_FLIP_NONE/*��ת*/);
    /*
    * ���ܣ�����������һ�����������ܸ���
    */
    void drawTile(string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame);

    map<string, SDL_Texture*> getTextureMap() { return m_textureMap; }
};