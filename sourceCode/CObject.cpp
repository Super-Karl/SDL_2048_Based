#include "CObject.h"
void CObject::SetID(std::string id)
{
	m_textureID = id;
}
std::string CObject::GetID()
{
	return m_textureID;
}
/*
* 设置精灵宽度
* 参数：fWidth 要设置的宽度值
* @木笔
*/
void CObject::SetSpriteWidth(float fWidth)
{
	m_fWidth = fWidth;
}

/*
*设置精灵高度
* 参数：fHeight 要设置的高度值
* @木笔
*/
void CObject::SetSpriteHeight(float fHeight)
{
	m_fHeight = fHeight;
}

/*
*获取精灵宽度
* 返回值：float型的精灵的宽度
* @木笔
*/
float CObject::GetSpriteWidth()
{
	return m_fWidth;
}

/*
*获取精灵高度
* 返回值：float型的精灵的高度
* @木笔
*/
float CObject::GetSpriteHeight()
{
	return m_fHeight;
}

/*
*设置精灵在X方向上是否翻转
* 参数：bFlipX 是否翻转
* @木笔
*/
void CObject::SetSpriteFlipX(bool bFlipX)
{
	m_bFlip_X = bFlipX;
}

/*
*设置精灵在Y方向上是否翻转
* 参数：bFlipY 是否翻转
* @木笔
*/
void CObject::SetSpriteFlipY(bool bFlipY)
{
	m_bFlip_Y = bFlipY;
}

/*
*获取精灵在X方向上是否翻转
* 返回值：是否翻转
* @木笔
*/
bool CObject::GetSpriteFlipX()
{
	return m_bFlip_X;
}

/*
*获取精灵在Y方向上是否翻转
* 返回值：是否翻转
* @木笔
*/
bool CObject::GetSpriteFlipY()
{
	return m_bFlip_Y;
}

/*
* 设置精灵的位置
* 参数：fPos_x: x位置
* 参数：fPos_y: y位置
* @木笔
*/
void CObject::SetSpritePosition(float fPos_x, float fPos_y)
{
	m_Position.setX(fPos_x);
	m_Position.setY(fPos_y);
}

/*
*设置精灵的X位置
* 参数：fPos_x 要设置的x位置
* @木笔
*/
void CObject::SetSpritePosition_X(float fPos_x)
{
	m_Position.setX(fPos_x);
}

/*
*设置精灵的Y位置
* 参数：fPos_y 要设置的y位置
* @木笔
*/
void CObject::SetSpritePosition_Y(float fPos_y)
{
	m_Position.setY(fPos_y);
}

/*
*获取精灵的X位置
* 返回值：float型的精灵位置X
* @木笔
*/
float CObject::GetSpritePosition_X()
{
	float pos_x = m_Position.getX();
	return pos_x;
}

/*
*获取精灵的Y位置
* 返回值：float型的精灵位置Y
* @木笔
*/
float CObject::GetSpritePosition_Y()
{
	float pos_y = m_Position.getY();
	return pos_y;
}
/*
* 设置精灵速度
* 参数：fVelocity_x X方向的速度
* 参数：fVelocity_y Y方向的速度
* @木笔
*/
void CObject::SetSpriteVelocity(float fVelocity_x, float fVelocity_y)
{
	m_Velocity.setX(fVelocity_x);
	m_Velocity.setY(fVelocity_y);
}
/*
* 获取精灵X方向的速度
* 返回值：float型的精灵速度X
* @木笔
*/
float CObject::GetSpriteVelocity_X()
{
	float f_velocity_X = m_Velocity.getX();
	return f_velocity_X;
}
/*
* 获取精灵Y方向的速度
* 返回值：float型的精灵速度Y
* @木笔
*/
float CObject::GetSpriteVelocity_Y()
{
	float f_velocity_Y = m_Velocity.getY();
	return f_velocity_Y;
}
/*
* 删除精灵
* @木笔
*/
void CObject::DeleteSprite()
{
	m_bDead = true;
}
/*
* 设置精灵显隐性
* @木笔
*/
void CObject::SetSpriteVisible(const bool bVisible)
{
	m_bDisplay = bVisible;
}
/*
* 判断某个点是否在精灵内部
* 参数：fPos_x 该点的X坐标
* 参数：fPos_y 该点的Y坐标
* @木笔
*/
bool CObject::IsPointInSprite(float fPOs_x, float fPos_y)
{
	float my_pos_x = GetSpritePosition_X();
	float my_pos_y = GetSpritePosition_Y();
	float my_width = GetSpriteWidth();
	float my_height = GetSpriteHeight();
	if (fPOs_x >= my_pos_x - (my_width / 2) && fPOs_x <= my_pos_x + (my_height / 2) &&
		fPos_y >= my_pos_y - (my_height / 2) && fPos_y <= my_pos_y + (my_height / 2))
		return true;
	else
		return false;
}
/*
* 设置精灵旋转角度
* 参数：fRot 要旋转的角度
* @木笔
*/
void CObject::SetSpriteRotation(float fRot)
{
	m_fAngle = fRot;
}
/*
* 获取精灵角度
* 返回值：float型的角度值
* @木笔
*/
float CObject::GetSpriteRotation()
{
	return m_fAngle;
}
/*
* 设置精灵自动旋转
* 参数：fRotSpeed 自动旋转的速度
* 参数：bStra 旋转的方向，0为逆时针，1为顺时针
* @木笔
*/
void CObject::SetSpriteAutoRot(float fRotSpeed, bool bStra)
{
	m_fRotSpeed = fRotSpeed;
	m_bRoting = true;
}
/*
* 设置精灵移动到某个位置
* 参数：fPosX 目的地坐标X
* 参数：fPosY 目的地坐标Y
* 参数：fSpeed 移动速度
* 参数：bAutoStop 是否自动停止，默认为自动停止
* @木笔
*/
void CObject::SetSpriteMoveTo(float fPosX, float fPosY, float fSpeed, bool bAutoStop)
{
	//此处应调用一个函数，功能是把向量速度转化为xy方向上的速度
}
/*
* 设置精灵自动旋转到某个角度
* 参数：fRot 旋转的角度
* 参数：fRotSpeed 旋转的速度
* 参数：bAutoStop 是否自动停止，默认为自动停止
*/
void CObject::SetSpriteRotateTo(float fRot, float fRotSpeed, bool bAutoStop)
{
	m_fRotSpeed = fRotSpeed;
	m_fAimRot = fRot;
	m_bRoting = true;
}