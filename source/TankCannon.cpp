#include "TankCannon.h"

#include "UGFW.h"
#include "Enumerations.h"

#include <iostream>

TankCannon::TankCannon()
{

}

TankCannon::TankCannon(char* fileName, float width, float height) : Player( fileName,  width,  height)
{
	m_width = width;
	m_height = height;
	m_v2Size.x = m_width;
	m_v2Size.y = m_height;
	m_origin.x = 0.6f;
	m_origin.y = 0.5f;
	//UG::SetSpriteUVCoordinates(getSpriteID(), m_origin);
}

TankCannon::TankCannon(char* fileName, float width, float height, float xPos, float yPos) : Player(fileName, width, height)
{
	m_width = width;
	m_height = height;
	m_v2Size.x = m_width;
	m_v2Size.y = m_height;

	m_xPos = xPos;
	m_yPos = yPos;
	m_v2Pos.x = xPos;
	m_v2Pos.y = yPos;
	m_origin.x = 0.6f;
	m_origin.y = 0.5f;
	//UG::SetSpriteUVCoordinates(getSpriteID(), m_origin);
}

TankCannon::TankCannon(char* fileName, float width, float height, Vector2 a_v2Velocity, float xPos, float yPos) : Player(fileName, width, height)
{
	m_width = width;
	m_height = height;
	m_v2Size.x = m_width;
	m_v2Size.y = m_height;

	m_xPos = xPos;
	m_yPos = yPos;
	m_v2Pos.x = xPos;
	m_v2Pos.y = yPos;

	m_v2Velocity = a_v2Velocity;
	m_origin.x = 0.6f;
	m_origin.y = 0.5f;
	//UG::SetSpriteUVCoordinates(getSpriteID(), m_origin);
}

TankCannon::TankCannon(char* fileName, float width, float height, Vector2 origin) : Player(fileName, width, height, origin)
{
	m_width = width;
	m_height = height;
	m_v2Size.x = m_width;
	m_v2Size.y = m_height;
	m_origin.x = origin.x;
	m_origin.y = origin.y;
	//UG::SetSpriteUVCoordinates(getSpriteID(), m_origin);
}

void TankCannon::SetKeys(unsigned int a_rotateLeft, unsigned int a_rotateRight, unsigned int a_shootKey)
{
	rLeftKey = a_rotateLeft;
	rRightKey = a_rotateRight;
	shootKey = a_shootKey;
}



Vector2 TankCannon::getRotateVector()
{

	Vector2 pos;
	getPosition(pos);
	radAngle = radAngle * PI / 180;
	pos.Rotate(radAngle);
	return pos;
}

Vector2 TankCannon::getRotateVector(Vector2& a_v2)
{
	radAngle = radAngle * PI / 180;

	Vector2 pos = a_v2;

	pos.Rotate(radAngle);
	return pos;
}

void TankCannon::Update(float a_fDeltaTime)
{
	//SetRotation(m_rotationAngle);

	//std::cout << m_rotationAngle << "ra" << std::endl;
	//std::cout << radAngle << "radangle" << std::endl;
	if (UG::IsKeyDown(rLeftKey))
		//SetPosition(getRotateVector());

	{

		Rotate(deltaRotate*a_fDeltaTime);
		m_rotationAngle -= (deltaRotate*a_fDeltaTime);
		radAngle = m_rotationAngle;
		//SetRotation(radAngle);
	}
	if (UG::IsKeyDown(rRightKey))
	{

		Rotate(-deltaRotate*a_fDeltaTime);
		m_rotationAngle += (deltaRotate*a_fDeltaTime);
		radAngle = m_rotationAngle;
		//SetRotation(radAngle);
	}
	radAngle = m_rotationAngle;
	SetRotation(radAngle);
	if (UG::IsKeyDown(shootKey))
	{
		isFiring = true;
	}
	else
	{
		isFiring = false;
	}
}


void TankCannon::Rotate(float a_fAngle)
{
	UG::RotateSprite(Sprite::getSpriteID(), a_fAngle);
}

bool TankCannon::checkFiring()
{
	return isFiring;
}