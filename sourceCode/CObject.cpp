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
* ���þ�����
* ������fWidth Ҫ���õĿ��ֵ
* @ľ��
*/
void CObject::SetSpriteWidth(float fWidth)
{
	m_fWidth = fWidth;
}

/*
*���þ���߶�
* ������fHeight Ҫ���õĸ߶�ֵ
* @ľ��
*/
void CObject::SetSpriteHeight(float fHeight)
{
	m_fHeight = fHeight;
}

/*
*��ȡ������
* ����ֵ��float�͵ľ���Ŀ��
* @ľ��
*/
float CObject::GetSpriteWidth()
{
	return m_fWidth;
}

/*
*��ȡ����߶�
* ����ֵ��float�͵ľ���ĸ߶�
* @ľ��
*/
float CObject::GetSpriteHeight()
{
	return m_fHeight;
}

/*
*���þ�����X�������Ƿ�ת
* ������bFlipX �Ƿ�ת
* @ľ��
*/
void CObject::SetSpriteFlipX(bool bFlipX)
{
	m_bFlip_X = bFlipX;
}

/*
*���þ�����Y�������Ƿ�ת
* ������bFlipY �Ƿ�ת
* @ľ��
*/
void CObject::SetSpriteFlipY(bool bFlipY)
{
	m_bFlip_Y = bFlipY;
}

/*
*��ȡ������X�������Ƿ�ת
* ����ֵ���Ƿ�ת
* @ľ��
*/
bool CObject::GetSpriteFlipX()
{
	return m_bFlip_X;
}

/*
*��ȡ������Y�������Ƿ�ת
* ����ֵ���Ƿ�ת
* @ľ��
*/
bool CObject::GetSpriteFlipY()
{
	return m_bFlip_Y;
}

/*
* ���þ����λ��
* ������fPos_x: xλ��
* ������fPos_y: yλ��
* @ľ��
*/
void CObject::SetSpritePosition(float fPos_x, float fPos_y)
{
	m_Position.setX(fPos_x);
	m_Position.setY(fPos_y);
}

/*
*���þ����Xλ��
* ������fPos_x Ҫ���õ�xλ��
* @ľ��
*/
void CObject::SetSpritePosition_X(float fPos_x)
{
	m_Position.setX(fPos_x);
}

/*
*���þ����Yλ��
* ������fPos_y Ҫ���õ�yλ��
* @ľ��
*/
void CObject::SetSpritePosition_Y(float fPos_y)
{
	m_Position.setY(fPos_y);
}

/*
*��ȡ�����Xλ��
* ����ֵ��float�͵ľ���λ��X
* @ľ��
*/
float CObject::GetSpritePosition_X()
{
	float pos_x = m_Position.getX();
	return pos_x;
}

/*
*��ȡ�����Yλ��
* ����ֵ��float�͵ľ���λ��Y
* @ľ��
*/
float CObject::GetSpritePosition_Y()
{
	float pos_y = m_Position.getY();
	return pos_y;
}
/*
* ���þ����ٶ�
* ������fVelocity_x X������ٶ�
* ������fVelocity_y Y������ٶ�
* @ľ��
*/
void CObject::SetSpriteVelocity(float fVelocity_x, float fVelocity_y)
{
	m_Velocity.setX(fVelocity_x);
	m_Velocity.setY(fVelocity_y);
}
/*
* ��ȡ����X������ٶ�
* ����ֵ��float�͵ľ����ٶ�X
* @ľ��
*/
float CObject::GetSpriteVelocity_X()
{
	float f_velocity_X = m_Velocity.getX();
	return f_velocity_X;
}
/*
* ��ȡ����Y������ٶ�
* ����ֵ��float�͵ľ����ٶ�Y
* @ľ��
*/
float CObject::GetSpriteVelocity_Y()
{
	float f_velocity_Y = m_Velocity.getY();
	return f_velocity_Y;
}
/*
* ɾ������
* @ľ��
*/
void CObject::DeleteSprite()
{
	m_bDead = true;
}
/*
* ���þ���������
* @ľ��
*/
void CObject::SetSpriteVisible(const bool bVisible)
{
	m_bDisplay = bVisible;
}
/*
* �ж�ĳ�����Ƿ��ھ����ڲ�
* ������fPos_x �õ��X����
* ������fPos_y �õ��Y����
* @ľ��
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
* ���þ�����ת�Ƕ�
* ������fRot Ҫ��ת�ĽǶ�
* @ľ��
*/
void CObject::SetSpriteRotation(float fRot)
{
	m_fAngle = fRot;
}
/*
* ��ȡ����Ƕ�
* ����ֵ��float�͵ĽǶ�ֵ
* @ľ��
*/
float CObject::GetSpriteRotation()
{
	return m_fAngle;
}
/*
* ���þ����Զ���ת
* ������fRotSpeed �Զ���ת���ٶ�
* ������bStra ��ת�ķ���0Ϊ��ʱ�룬1Ϊ˳ʱ��
* @ľ��
*/
void CObject::SetSpriteAutoRot(float fRotSpeed, bool bStra)
{
	m_fRotSpeed = fRotSpeed;
	m_bRoting = true;
}
/*
* ���þ����ƶ���ĳ��λ��
* ������fPosX Ŀ�ĵ�����X
* ������fPosY Ŀ�ĵ�����Y
* ������fSpeed �ƶ��ٶ�
* ������bAutoStop �Ƿ��Զ�ֹͣ��Ĭ��Ϊ�Զ�ֹͣ
* @ľ��
*/
void CObject::SetSpriteMoveTo(float fPosX, float fPosY, float fSpeed, bool bAutoStop)
{
	//�˴�Ӧ����һ�������������ǰ������ٶ�ת��Ϊxy�����ϵ��ٶ�
}
/*
* ���þ����Զ���ת��ĳ���Ƕ�
* ������fRot ��ת�ĽǶ�
* ������fRotSpeed ��ת���ٶ�
* ������bAutoStop �Ƿ��Զ�ֹͣ��Ĭ��Ϊ�Զ�ֹͣ
*/
void CObject::SetSpriteRotateTo(float fRot, float fRotSpeed, bool bAutoStop)
{
	m_fRotSpeed = fRotSpeed;
	m_fAimRot = fRot;
	m_bRoting = true;
}