#pragma once

#include <iostream>
#include <string>
#include <map>
#include "CGame.h"
using namespace std;

#include<SDL.h>
#include<SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class CFontManager 
{
public:
	static CFontManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new CFontManager();
		}
		return s_pInstance;
	}
	/*
	* ���ܣ���������
	*/
	bool load(const std::string& file_name/*�����ļ��ĵ�ַ*/, const std::string& id/*�Լ������id*/, int size/*���ص������С*/, int style = TTF_STYLE_NORMAL/*�����Ч������Ӵ֣�б��*/);
	/*
	* ���ܣ�������ͨ�����ص���������Ļ����ʾ����
	*/
	bool textToTexture(const std::string& text/*Ҫ��ʾ���ַ���*/, const std::string& font_id/*ʹ�õ�����id*/, const std::string& texture_id/*����Ψһ����id*/, SDL_Color colour = { 0, 0, 0, 255 }/*��ɫ*/);
	/*
	* ���ܣ�ͨ��id��������ָ��
	*/
	TTF_Font* getFont(const std::string& id);
	/*
	* ���ܣ�����һ���ص�����
	*/
	void clean();
	/*
	* ��ʾ�����Ѽ��ص�����id
	*/
	void displayFontMap();

private:
	CFontManager();
	~CFontManager();

	map<string, TTF_Font*> m_fontMap;

	static CFontManager* s_pInstance;
};


