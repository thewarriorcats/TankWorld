#include "Projectile.h"

#include "UGFW.h"
#include "Enumerations.h"

Projectile::Projectile()
{

}

Projectile::Projectile(char* fileName, float a_width, float a_height, float a_xPos, float a_yPos)
{
	m_iSpriteID = UG::CreateSprite(fileName, a_width, a_height);

	setSize(a_width, a_height);

	//m_width = a_width;
	//m_height = a_height;
	//m_sizeV2.Set(a_width, a_height);

	setPosition(a_xPos, a_yPos);

	//m_xPos = a_xPos;
	//m_yPos = a_yPos;
	//m_posV2.Set(a_xPos, a_yPos);
}

Projectile::Projectile(char* fileName, Vector2 a_sizeV2, Vector2 a_positionV2)
{
	m_iSpriteID = UG::CreateSprite(fileName, a_sizeV2.x, a_sizeV2.y);

	setSize(a_sizeV2);

	setPosition(a_positionV2);
}

Projectile::~Projectile()
{

}

void Projectile::Update(float a_fDelta)
{

}


////////////////////////////////////////////////////////////////////////////////////////
//
//							GET FUNCTIONS
//
////////////////////////////////////////////////////////////////////////////////////////

int Projectile::getSpriteID()
{
	return m_iSpriteID;
}

void Projectile::getPosition(float& a_xPos, float& a_yPos)
{
	a_xPos = m_xPos;
	a_yPos = m_yPos;
}

void Projectile::getPosition(Vector2& a_v2)
{
	a_v2.x = m_xPos;
	a_v2.y = m_yPos;
}

Vector2 Projectile::getPosition()
{
	return Vector2(m_posV2);
}

Vector2 Projectile::getPerpendicularAngle()
{
	return m_directionV2.getPerpendicular();
}

void Projectile::getSpeed(float& a_speed)
{
	a_speed = m_Speed;
}

float Projectile::getSpeed()
{
	return m_Speed;
}

void Projectile::getSize(float& a_width, float& a_height)
{
	a_width = m_width;
	a_height = m_height;
}

Vector2 Projectile::getSize()
{
	return m_sizeV2;
}

void Projectile::getDirection(float& a_direcX, float& a_direcY)
{
	a_direcX = m_directionX;
	a_direcY = m_directionY;
}

void Projectile::getDirection(Vector2& a_direction)
{
	a_direction = m_directionV2;
}

Vector2 Projectile::getDirection()
{
	return m_directionV2;
}
////////////////////////////////////////////////////////////////////////////////////////
//
//							SET FUNCTIONS
//
////////////////////////////////////////////////////////////////////////////////////////
void Projectile::setPosition(float a_xPos, float a_yPos)
{
	m_xPos = a_xPos;
	m_yPos = a_yPos;

	m_posV2.Set(m_xPos, m_yPos);
}

void Projectile::setPosition(Vector2 a_position)
{
	m_posV2 = a_position;

	m_xPos = m_posV2.x;
	m_yPos = m_posV2.y;
}

void Projectile::setSpeed(float a_fSpeed)
{
	m_Speed = a_fSpeed;
}

void Projectile::setSize(float a_width, float a_height)
{
	m_width = a_width;
	m_height = a_height;

	m_sizeV2.Set(m_width, m_height);
}

void Projectile::setSize(Vector2 a_size)
{
	m_sizeV2 = a_size;

	m_width = m_sizeV2.x;
	m_height = m_sizeV2.y;
}

void Projectile::setDirection(float directionX, float directionY)
{
	m_directionX = directionX;
	m_directionY = directionY;

	m_directionV2.x = directionX;
	m_directionV2.y = directionY;
}

void Projectile::setDirection(Vector2 a_direction)
{
	m_directionV2 = a_direction;

	m_directionX = a_direction.x;
	m_directionY = a_direction.y;
}
