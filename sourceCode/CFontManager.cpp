#include "CFontManager.h"
#include "CTextureManager.h"

CFontManager* CFontManager::s_pInstance = NULL;

bool CFontManager::load(const std::string& file_name, const std::string& id, const int size, const int style)
{
	TTF_Font* font=TTF_OpenFont(file_name.c_str(), size);	

	if (font == 0)
	{
		cout << TTF_GetError();
		return false;
	}
	TTF_SetFontStyle(font, style);
	m_fontMap[id] = font;
	return true;
}

bool CFontManager::textToTexture(const std::string& text, const std::string& font_id, const std::string& texture_id, const SDL_Color colour)
{
	SDL_Surface* textSurface = TTF_RenderUTF8_Blended(m_fontMap[font_id], text.c_str(), colour);
	
	if (textSurface == nullptr)
	{
		cout << "Unable to render text surface! SDL_ttf Error: %s\n" << TTF_GetError();
		return false;
	}
	else
	{
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(CGame::Instance()->getRenderer(), textSurface);
		SDL_FreeSurface(textSurface);
		textSurface = NULL;
		if (CTextureManager::Instance()->addTexture(texture_id, pTexture) == 0)
		{
			cout << "Unable to create texture from rendered text! SDL Error: %s\n" << SDL_GetError();
		}
		pTexture = NULL;
	}
	return true;
}

TTF_Font * CFontManager::getFont(const std::string& id)
{
	return m_fontMap[id];
}

void CFontManager::clean()
{
	m_fontMap.clear();
}

void CFontManager::displayFontMap()
{
	std::cout << "------------ Displaying Font Map -----------" << std::endl;

	std::cout << "Font Map size: " << m_fontMap.size() << std::endl;

	auto it = m_fontMap.begin();
	while (it != m_fontMap.end())
	{
		std::cout << " " << it->first << std::endl;
		++it;
	}
}


CFontManager::CFontManager()
= default;

CFontManager::~CFontManager()
= default;
