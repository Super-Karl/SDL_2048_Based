#pragma once
#include<string>
#include"Vector2D.h"
class CObject
{
public:
	//以下4个函数为接口
	virtual void load(std::string fileName, std::string id, int x, int y, int width = -1, int height = -1) = 0;
	//更新
	virtual void update() = 0;
	//绘制
	virtual void draw() = 0;
	//清理
	virtual void clean() = 0;

    Vector2D& getPosition() { return m_Position; }
    Vector2D& getVelocity() { return m_Velocity; }


    
    int getWidth() { return m_fWidth; }
    int getHeight() { return m_fHeight; }
    bool updating() { return m_bUpdating; }
    bool dead() { return m_bDead; }
    bool dying() { return m_bDying; }
    void setUpdating(bool updating) { m_bUpdating = updating; }
	void SetID(std::string id);
	std::string GetID();

	void SetSpriteWidth(float fWidth);
	float GetSpriteWidth();
	void SetSpriteHeight(float fHeight);
	float GetSpriteHeight();
	void SetSpriteFlipX(bool bFlipX);
	bool GetSpriteFlipX();
	void SetSpriteFlipY(bool bFlipY);
	bool GetSpriteFlipY();

	void SetSpritePosition(float fPos_x, float fPos_y);
	void SetSpritePosition_X(float fPos_x);
	void SetSpritePosition_Y(float fPos_y);
	float GetSpritePosition_X();
	float GetSpritePosition_Y();

	void SetSpriteVelocity(float fVelocity_x, float fVelocity_y);
	float GetSpriteVelocity_X();
	float GetSpriteVelocity_Y();

	void DeleteSprite();
	void SetSpriteVisible(const bool bVisible);
	bool IsPointInSprite(float fPos_x, float fPos_y);
	void SetSpriteRotation(float fRot);
	float GetSpriteRotation();
	void SetSpriteAutoRot(float fRotSpeed, bool bStra);
	void SetSpriteMoveTo(float fPosX, float fPosY, float fSpeed, bool bAutoStop = true);
	void SetSpriteRotateTo(float fRot, float fRotSpeed, bool bAutoStop = true);

protected:

	CObject() :m_Position(0, 0),
		m_Velocity(0, 0),
		m_fWidth(0),
		m_fHeight(0),
		m_currentRow(0),
		m_currentFrame(0),
		m_bUpdating(false),
		m_bDead(false),
		m_bDying(false),
		m_angle(0),
		m_alpha(255)
	{
	}

	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;
	std::string m_textureID;

	bool m_bUpdating;
	bool m_bDying;

	double m_angle;

	int m_alpha;


	//精灵的宽高
	float m_fWidth;
	float m_fHeight;

	//精灵的运动变量
	Vector2D m_Velocity;
	Vector2D m_Position;
	float m_fAngle;
	float m_fAimRot;
	float m_fRotSpeed;

	//状态值
	bool m_bDisplay;
	bool m_bDead;
	bool m_bFlip_X;
	bool m_bFlip_Y;
	bool m_bRoting;
	bool m_bAnimation;
};