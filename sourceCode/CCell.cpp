#include "CCell.h"

CCell::CCell()
{
    m_textureID = "";
    m_fWidth = 0;
    m_fHeight = 0;
    m_Position.setX(0);
    m_Position.setY(0);
}

CCell::CCell(string fileName, string id, int x, int y, int width, int height)
{
    m_textureID = id;
    m_Position.setX(x);
    m_Position.setY(y);
    m_fWidth = width;
    m_fHeight = height;
    CTextureManager::Instance()->load(fileName.c_str(), m_textureID.c_str());
}

void CCell::load(string fileName, string id, int x, int y, int width, int height)
{
    m_textureID = id;
    m_Position.setX(x);
    m_Position.setY(y);
    m_fWidth = width;
    m_fHeight = height;
    CTextureManager::Instance()->load(fileName.c_str(), m_textureID.c_str());
}

void CCell::draw()
{
    CTextureManager::Instance()->drawFrame(m_textureID, m_Position.getX(), m_Position.getY(), 400, 100, 0, m_currentFrame, 0.0, 255);
}

void CCell::update()
{
    Vector2D* pMousePos = CInputHandle::Instance()->getMousePosition();

    if (pMousePos->getX() < (m_Position.getX() + m_fWidth) && pMousePos->getX() > m_Position.getX()
        && pMousePos->getY() < (m_Position.getY() + m_fHeight) && pMousePos->getY() > m_Position.getY())
    {

        if (CInputHandle::Instance()->getMouseButtonState(LEFT))
        {
            m_currentFrame = CLICKED;
        }
        else if (!CInputHandle::Instance()->getMouseButtonState(LEFT))
        {
            m_currentFrame = MOUSE_OVER;
        }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}

void CCell::clean()
{
}
