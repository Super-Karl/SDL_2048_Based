#include "CEndState.h"
#include "CTextureManager.h"
#include "CAudioManage.h"
#include "CFontManager.h"
#include "CInputHandle.h"
#include <iostream>

const string CEndState::s_StateID = "ENDSTATE";

bool CEndState::onEnter()
{
	cout << "enter EndState\n";
	SDL_Color gold = { 255,215,0 };
	CFontManager::Instance()->load("./res/fonts/Dock51.ttf", "gameover", 80);
	CFontManager::Instance()->textToTexture("Game Over!", "gameover", "gameover", gold);
	return true;
}

void CEndState::inputHandle()
{
	CInputHandle::Instance()->update();
	//用户自定义
	if (CInputHandle::Instance()->getMousePos_X() == 0.0f)
	{
		//相关操作
	}
}

void CEndState::update()
{
	for (int i = 0; i < m_CSpriteList.size(); i++)
	{
		//m_CSpriteList[i]->update;
	}
}

void CEndState::render()
{
	for (int i = 0; i < m_CSpriteList.size(); i++)
	{
		//m_CSpriteList[i]->render;
	}
	SDL_RenderClear(CGame::Instance()->getRenderer());
	CTextureManager::Instance()->draw("gameover", 30, 300, 0);
	SDL_RenderPresent(CGame::Instance()->getRenderer());
}

bool CEndState::onExit()
{
	cout << "exit EndState\n";
	return true;
}

string CEndState::getStateID()
{
	return s_StateID;
}

void CEndState::addSprite(CObject* sprite)
{
	m_CSpriteList.push_back(sprite);
}

void CEndState::deleteSprite(CObject* sprite)
{
	m_CSpriteList.erase(std::remove(m_CSpriteList.begin(), m_CSpriteList.end(), sprite), m_CSpriteList.end());
}
