#include "CFileManage.h"
#include "CPlayState.h"
#include "CTextureManager.h"
#include "CAudioManage.h"
#include "CFontManager.h"
#include "CInputHandle.h"
#include <iostream>
#include <time.h>

const string CPlayState::s_StateID = "PLAYSTATE";

bool CPlayState::onEnter()
{
	cout << "enter CPlayState\n";
	m_Nowstate = state_state::ALIVE;
	maxNum = 2;
	score = 0;
	highestScore = atoi((CFileManage::Instance()->readin()).c_str());
	//¼ÓÔØÎÄ×Ö
	SDL_Color black = { 0,0,0 };
	SDL_Color lightred = { 245,100,100 };
	SDL_Color gold = { 255,215,0 };
	CFontManager::Instance()->load("./res/fonts/Dock51.ttf", "2048logo", 100);
	CFontManager::Instance()->textToTexture("2048", "2048logo", "2048logo", lightred);
	CFontManager::Instance()->load("./res/fonts/Consolas.ttf", "number", 30);
	//¼ÓÔØ±³¾°Í¼Æ¬
	CTextureManager::Instance()->load("./res/image/background.png", "playborad");
	CTextureManager::Instance()->load("./res/image/scorebg.png", "scorebg");
	CTextureManager::Instance()->load("./res/image/block_2.png", "block_2");
	CTextureManager::Instance()->load("./res/image/block_4.png", "block_4");
	CTextureManager::Instance()->load("./res/image/block_8.png", "block_8");
	CTextureManager::Instance()->load("./res/image/block_16.png", "block_16");
	CTextureManager::Instance()->load("./res/image/block_32.png", "block_32");
	CTextureManager::Instance()->load("./res/image/block_64.png", "block_64");
	CTextureManager::Instance()->load("./res/image/block_128.png", "block_128");
	CTextureManager::Instance()->load("./res/image/block_256.png", "block_256");
	CTextureManager::Instance()->load("./res/image/block_512.png", "block_512");
	CTextureManager::Instance()->load("./res/image/block_1024.png", "block_1024");
	CTextureManager::Instance()->load("./res/image/block_2048.png", "block_2048");

	//¼ÓÔØÒôÀÖ
	CAudioManage::Instance()->load("./res/audio/background.wav", "background", SOUND_MUSIC);

	//²¥·Å±³¾°ÒôÀÖ
	CAudioManage::Instance()->playMusic("background", 1);

	//³õÊ¼»¯×ø±êÎ»ÖÃ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			block[i][j].setX(15 + 15 * (j + 1) + 106 * j);
			block[i][j].setY(178 + 15 * (i + 1) + 106 * i);
			cout << block[i][j].getX() << " " << block[i][j].getY() << ", ";
		}
		cout << endl;
	}
	board = newBoard();
	addRandom();
	addRandom();
	return true;
}

void CPlayState::inputHandle()
{
	CInputHandle::Instance()->update();
	moveSuccess = false;
	if (CInputHandle::Instance()->ifKeyDown(SDL_SCANCODE_LEFT)){
		moveSuccess = moveLeft();
	}
	else if (CInputHandle::Instance()->ifKeyDown(SDL_SCANCODE_RIGHT)) {
		moveSuccess = moveRight();
	}
	else if (CInputHandle::Instance()->ifKeyDown(SDL_SCANCODE_UP)) {
		moveSuccess = moveUp();
	}
	else if (CInputHandle::Instance()->ifKeyDown(SDL_SCANCODE_DOWN)) {
		moveSuccess = moveDown();
	}

	if (moveSuccess) 
	{
		addRandom();
		if(cantmove()) 
		{
			finishedGame = true;
			m_Nowstate = state_state::DYING;
		}
	}
}

void CPlayState::update()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != NULL)
			{
				board[i][j]->SetSpritePosition_X(block[i][j].getX());
				board[i][j]->SetSpritePosition_Y(block[i][j].getY());
			}
		}
	}
}

void CPlayState::render()
{
	SDL_RenderClear(CGame::Instance()->getRenderer());
	
	SDL_Color ro = { 240,230,213 };
	CTextureManager::Instance()->clearFromTextureMap("maxNum");
	CTextureManager::Instance()->clearFromTextureMap("score");
	CTextureManager::Instance()->clearFromTextureMap("highestscore");

	CFontManager::Instance()->textToTexture(to_string(maxNum), "number", "maxNum", ro);
	CFontManager::Instance()->textToTexture(to_string(score), "number", "score", ro);
	CFontManager::Instance()->textToTexture(to_string(highestScore), "number", "highestscore", ro);

	CTextureManager::Instance()->draw("playborad", 15, 178);
	CTextureManager::Instance()->draw("2048logo", 10, 10, 0);
	CTextureManager::Instance()->draw("scorebg", 254, 10, 0);
	CTextureManager::Instance()->draw("highestscore", 400, 25, 0);
	CTextureManager::Instance()->draw("maxNum", 400, 120, 0);
	CTextureManager::Instance()->draw("score", 400, 75, 0);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != NULL)
			{
				CTextureManager::Instance()->draw("block_" + board[i][j]->GetID(), board[i][j]->GetSpritePosition_X(), board[i][j]->GetSpritePosition_Y());
			}
		}
	}
	SDL_RenderPresent(CGame::Instance()->getRenderer());
}

bool CPlayState::onExit()
{
	cout << "exit CPlayState\n";
	int row, col;
	for (row = 0; row < 4; row++) 
	{
		for (col = 0; col < 4; col++) 
		{
			if (board[row] != NULL && board[row][col] != NULL) 
			{
				free(board[row][col]);
				board[row][col] = NULL;
			}
		}
	}
	for (row = 0; row < 4; row++) {
		free(board[row]);
		board[row] = NULL;
	}
	free(board);
	board = NULL;
	CTextureManager::Instance()->clearTextureMap();
	CFontManager::Instance()->clean();
	CAudioManage::Instance()->stopMusic(1000);
	if (highestScore < score)
	{
		highestScore = score;
	}
	CFileManage::Instance()->write(to_string(highestScore));
	return true;
}

string CPlayState::getStateID()
{
	return s_StateID;
}

void CPlayState::addSprite(CObject* sprite)
{
	m_CSpriteList.push_back(sprite);
}

void CPlayState::deleteSprite(CObject* sprite)
{
	m_CSpriteList.erase(std::remove(m_CSpriteList.begin(), m_CSpriteList.end(), sprite), m_CSpriteList.end());
}

void CPlayState::addRandom()
{
	srand((unsigned int)time(0));
	int i = rand() % 4;
	int j = rand() % 4;
	while (board[i][j] != NULL)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	board[i][j] = new CCell();
	board[i][j]->SetID("2");
	board[i][j]->SetSpritePosition_X(block[i][j].getX());
	board[i][j]->SetSpritePosition_Y(block[i][j].getY());
}

Board CPlayState::newBoard()
{
	Board board;
	board = (Board)malloc(sizeof(cell*) * 4);
	int row, col;
	for (row = 0; row < 4; row++) 
	{
		board[row] = (cell*)malloc(sizeof(cell) * 4);
	}
	for (row = 0; row < 4; row++) 
	{
		for (col = 0; col < 4; col++) 
		{
			board[row][col] = NULL;
		}
	}
	return board;
}

int CPlayState::moveUp() {
	int row, col, flag;
	int i;
	flag = 0;
	for (col = 0; col < 4; col++) 
	{
		for (row = 1; row < 4; row++) 
		{
			while (row > 0 && board[row][col] != NULL && board[row - 1][col] == NULL) {
				flag++;
				board[row - 1][col] = board[row][col];
				board[row][col] = NULL;
				row--;
			}
		}
	}
	for (col = 0; col < 4; col++) {
		for (row = 0; row < 3; row++) {
			if (board[row][col] != NULL && board[row + 1][col] != NULL
				&& board[row][col]->GetID()== board[row + 1][col]->GetID()) {
				flag++;
				free(board[row + 1][col]);
				board[row + 1][col] = NULL;
				board[row][col]->SetID(to_string(2 * atoi(board[row][col]->GetID().c_str())));
				if (atoi(board[row][col]->GetID().c_str()) > maxNum)
				{
					maxNum = atoi(board[row][col]->GetID().c_str());
				}
				score += atoi(board[row][col]->GetID().c_str());
			}
		}
	}
	for (col = 0; col < 4; col++) 
	{
		for (row = 1; row < 4; row++) 
		{
			while (row > 0 && board[row][col] != NULL && board[row - 1][col] == NULL) 
			{
				flag++;
				board[row - 1][col] = board[row][col];
				board[row][col] = NULL;
				row--;
			}
		}
	}

	if (flag > 0) {
		return true;
	}
	else {
		return false;
	}
}

int CPlayState::moveDown() 
{
	int row, col, flag;
	int i;
	flag = 0;
	for (col = 0; col < 4; col++) {
		for (row = 2; row >= 0; row--) {
			while (row < 3 && board[row][col] != NULL && board[row + 1][col] == NULL) {
				flag++;
				board[row + 1][col] = board[row][col];
				board[row][col] = NULL;
				row++;
			}
		}
	}
	for (col = 0; col < 4; col++) {
		for (row = 3; row >= 1; row--) {
			if (board[row][col] != NULL && board[row - 1][col] != NULL
				&& board[row][col]->GetID()==board[row - 1][col]->GetID()) {
				flag++;
				free(board[row - 1][col]);
				board[row - 1][col] = NULL;
				board[row][col]->SetID(to_string(2 * atoi(board[row][col]->GetID().c_str())));
				if (atoi(board[row][col]->GetID().c_str()) > maxNum)
				{
					maxNum = atoi(board[row][col]->GetID().c_str());
				}
				score += atoi(board[row][col]->GetID().c_str());
			}
		}
	}
	for (col = 0; col < 4; col++) {
		for (row = 2; row >= 0; row--) {
			while (row < 3 && board[row][col] != NULL && board[row + 1][col] == NULL) {
				flag++;
				board[row + 1][col] = board[row][col];
				board[row][col] = NULL;
				row++;
			}
		}
	}
	if (flag > 0) {
		return true;
	}
	else {
		return false;
	}
}

int CPlayState::moveLeft() 
{
	int row, col, flag;
	int i;
	flag = 0;
	for (row = 0; row < 4; row++) {
		for (col = 1; col < 4; col++) {
			while (col > 0 && board[row][col] != NULL && board[row][col - 1] == NULL) {
				flag++;
				board[row][col - 1] = board[row][col];
				board[row][col] = NULL;
				col--;
			}
		}
	}
	for (row = 0; row < 4; row++) {
		for (col = 0; col < 3; col++) {
			if (board[row][col] != NULL && board[row][col + 1] != NULL
				&& board[row][col]->GetID()==board[row][col + 1]->GetID()) {
				flag++;
				free(board[row][col + 1]);
				board[row][col + 1] = NULL;
				board[row][col]->SetID(to_string(2 * atoi(board[row][col]->GetID().c_str())));
				if (atoi(board[row][col]->GetID().c_str()) > maxNum)
				{
					maxNum = atoi(board[row][col]->GetID().c_str());
				}
				score += atoi(board[row][col]->GetID().c_str());
			}
		}
	}
	for (row = 0; row < 4; row++) {
		for (col = 1; col < 4; col++) {
			while (col > 0 && board[row][col] != NULL && board[row][col - 1] == NULL) {
				flag++;
				board[row][col - 1] = board[row][col];
				board[row][col] = NULL;
				col--;
			}
		}
	}
	if (flag > 0) {
		return true;
	}
	else {
		return false;
	}
}

int CPlayState::moveRight() 
{
	int col, row, flag;
	int i;
	flag = 0;
	for (row = 0; row < 4; row++) {
		for (col = 2; col >= 0; col--) {
			while (col < 3 && board[row][col] != NULL && board[row][col + 1] == NULL) {
				flag++;
				board[row][col + 1] = board[row][col];
				board[row][col] = NULL;
				col++;
			}
		}
	}
	for (row = 0; row < 4; row++) {
		for (col = 3; col >= 1; col--) {
			if (board[row][col] != NULL && board[row][col - 1] != NULL
				&& board[row][col]->GetID() == board[row][col - 1]->GetID()) {
				flag++;
				free(board[row][col - 1]);
				board[row][col - 1] = NULL;
				board[row][col]->SetID(to_string(2 * atoi(board[row][col]->GetID().c_str())));
				if (atoi(board[row][col]->GetID().c_str()) > maxNum)
				{
					maxNum = atoi(board[row][col]->GetID().c_str());
				}
				score += atoi(board[row][col]->GetID().c_str());
			}
		}
	}
	for (row = 0; row < 4; row++) {
		for (col = 2; col >= 0; col--) {
			while (col < 3 && board[row][col] != NULL && board[row][col + 1] == NULL) {
				flag++;
				board[row][col + 1] = board[row][col];
				board[row][col] = NULL;
				col++;
			}
		}
	}
	if (flag > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool CPlayState::cantmove()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == NULL || board[i][j + 1] == NULL)
			{
				return false;
			}
			if (board[j + 1][i] == NULL || board[j][i] == NULL)
			{
				return false;
			}
			if (board[i][j]->GetID() == board[i][j+1]->GetID() || board[j][i]->GetID() == board[j+1][i]->GetID())
			{
				return false;
			}
		}
	}
	return true;
}