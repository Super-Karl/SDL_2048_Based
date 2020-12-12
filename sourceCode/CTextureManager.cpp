#include "CTextureManager.h"
#include "SDL_image.h"
#include "SDL.h"

CTextureManager* CTextureManager::s_pInstance = NULL;

bool CTextureManager::load(string fileName, string id)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (pTempSurface == 0)
    {
        cout << IMG_GetError();
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(CGame::Instance()->getRenderer(), pTempSurface);

    SDL_FreeSurface(pTempSurface);

    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }

    return false;
}

bool CTextureManager::addTexture(string id, SDL_Texture* pTexture)
{
    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    return false;
}

void CTextureManager::setAlpha(const string& id, const Uint8 new_alpha)
{
    auto pTexture = m_textureMap[id];
    SDL_SetTextureAlphaMod(pTexture, new_alpha);
    pTexture = nullptr;
}

void CTextureManager::setColour(const string& id, const Uint8 red, const Uint8 green, const Uint8 blue)
{
    auto pTexture = m_textureMap[id];
    SDL_SetTextureColorMod(pTexture, red, green, blue);
    pTexture = nullptr;
}

void CTextureManager::draw(string id, int x, int y, float angle, int width, int height, float alpha, SDL_RendererFlip flip)
{
    if (width <= 0 || height < 0)
    {
        SDL_QueryTexture(m_textureMap[id], nullptr, nullptr, &width, &height);
    }
    
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(CGame::Instance()->getRenderer(), m_textureMap[id], &srcRect, &destRect, angle, NULL, flip);
}

void CTextureManager::drawSuper(string id, int cutx, int cuty, int cutwidth, int cutheight,
    int showx, int showy, int showwidth,int showheight, float angle, float alpha,
    int rotx,int roty, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Point rotatedCenter;

    srcRect.x = cutx;
    srcRect.y = cuty;
    srcRect.w = cutwidth;
    srcRect.h = cutheight;

    destRect.x = showx;
    destRect.y = showy;
    destRect.w = showwidth;
    destRect.h = showheight;

    rotatedCenter.x= rotx;
    rotatedCenter.y = roty;

    SDL_SetTextureAlphaMod(m_textureMap[id], alpha);
    SDL_RenderCopyEx(CGame::Instance()->getRenderer(), m_textureMap[id], &srcRect, &destRect, angle, &rotatedCenter, flip);
}

void CTextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, double angle, int alpha, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_SetTextureAlphaMod(m_textureMap[id], alpha);
    SDL_RenderCopyEx(CGame::Instance()->getRenderer(), m_textureMap[id], &srcRect, &destRect, angle, 0, flip);
}
//margin空白边距，spacing间隔，currentFrame当前框架，currentRow列，currentFrame行
void CTextureManager::drawTile(string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(CGame::Instance()->getRenderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}

void CTextureManager::clearTextureMap()
{
    m_textureMap.clear();
}

void CTextureManager::clearFromTextureMap(string id)
{
    SDL_DestroyTexture(m_textureMap[id]);
    m_textureMap.erase(id);
}

