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
	* 功能：加载字体
	*/
	bool load(const std::string& file_name/*字体文件的地址*/, const std::string& id/*自己分配的id*/, int size/*加载的字体大小*/, int style = TTF_STYLE_NORMAL/*字体的效果，如加粗，斜体*/);
	/*
	* 功能：将文字通过加载的字体在屏幕上显示出来
	*/
	bool textToTexture(const std::string& text/*要显示的字符串*/, const std::string& font_id/*使用的字体id*/, const std::string& texture_id/*分配唯一纹理id*/, SDL_Color colour = { 0, 0, 0, 255 }/*颜色*/);
	/*
	* 功能：通过id返回字体指针
	*/
	TTF_Font* getFont(const std::string& id);
	/*
	* 功能：清理一加载的字体
	*/
	void clean();
	/*
	* 显示所有已加载的字体id
	*/
	void displayFontMap();

private:
	CFontManager();
	~CFontManager();

	map<string, TTF_Font*> m_fontMap;

	static CFontManager* s_pInstance;
};


