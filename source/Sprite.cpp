#include "Sprite.h"

#include "UGFW.h"
#include "Enumerations.h"

Sprite::Sprite()
{

}

Sprite::Sprite(char* fileName)
{
	m_iSpriteID = UG::CreateSprite(fileName, 0.f, 0.f);

	m_xPos = 0;
	m_yPos = 0;
	m_posV2.Set(0, 0);

	m_width = 0;
	m_height = 0;
	m_sizeV2.Set(0, 0);
}

Sprite::Sprite(char* fileName, float width, float height)
{
	m_iSpriteID = UG::CreateSprite(fileName, width, height);

	m_width = width;
	m_height = height;
	m_sizeV2.Set(m_width, m_height);

	m_xPos = 0;
	m_yPos = 0;
	m_posV2.Set(0, 0);
}

Sprite::Sprite(char* fileName, float width, float height, float xPos, float yPos)
{
	m_iSpriteID = UG::CreateSprite(fileName, width, height);

	m_width = width;
	m_height = height;
	m_sizeV2.Set(m_width, m_height);

	m_xPos = xPos;
	m_yPos = yPos;
	m_posV2.Set(m_xPos, m_yPos);
}

Sprite::Sprite(char* fileName, float width, float height, Vector2 origin)
{
	m_iSpriteID = UG::CreateSprite(fileName, width, height, origin);

	m_width = width;
	m_height = height;
	m_sizeV2.Set(m_width, m_height);

}

Sprite::~Sprite()
{
}

////////////////////////////////////////////////////////////////////////////////////////
//
//							SET FUNCTIONS
//
////////////////////////////////////////////////////////////////////////////////////////


void Sprite::SetSprite(char* fileName)
/*
//	Allows you to reuse the sprite instead of creating another, or changing its texture. Will give it a new sprite ID but keep its width and height.
*/
{
	m_iSpriteID = UG::CreateSprite(fileName, m_width, m_height);
}
////////////
//////Set Size functions
///////////
void Sprite::SetSize(float a_width, float a_height)
/*
// Allows you to set the size of the Sprite with floats.
*/
{
	m_width = a_width;
	m_height = a_height;

	m_sizeV2.Set(m_width, m_height);
}

void Sprite::SetSize(Vector2 a_v2)
/*
//	Sets the size of the Sprite to the size Vector passed in. X = width, Y = height.
*/
{
	m_sizeV2 = a_v2;

	m_width = m_sizeV2.x;
	m_height = m_sizeV2.y;
}

////////////
//////Set Position functions
///////////

void Sprite::SetPosition(float a_xPos, float a_yPos)
/*
//	Sets the sprite position to floats passed in. Will also utilise UG::MoveSprite for you.
*/
{
	m_xPos = a_xPos;
	m_yPos = a_yPos;

	m_posV2.Set(m_xPos, m_yPos);

	UG::MoveSprite(m_iSpriteID, m_xPos, m_yPos);
}

void Sprite::SetPosition(Vector2 a_v2)
/*
//	Sets the sprite position to the Vector passed in. Will also ultilise UG::MoveSprite for you.
*/
{
	m_posV2 = a_v2;

	m_xPos = m_posV2.x;
	m_yPos = m_posV2.y;

	UG::MoveSprite(m_iSpriteID, m_xPos, m_yPos);
}

void Sprite::SetRotation(float a_fAngle)
{
	m_fAngle = a_fAngle;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//							GET FUNCTIONS
//
////////////////////////////////////////////////////////////////////////////////////////


int Sprite::getSpriteID()
/*
//	Returns the current Sprite ID as an integer.
*/
{
	return m_iSpriteID;
}


////////////
//////Get Size functions
///////////
void Sprite::getSize(float& a_width, float& a_height)
/*
//	Returns the size of the Sprite in the Variables passed through.
*/
{
	a_width = m_width;
	a_height = m_height;
}

void Sprite::getSize(Vector2& a_v2)
/*
//	Returns the size of the Sprite in the Vector2 passed through. x = width, y = height.
*/
{
	a_v2 = m_sizeV2;
}

Vector2 Sprite::getSize()
/*
//	Returns the size of the Sprite as a Vector2. X = width, Y = height.
*/
{
	return m_sizeV2;
}


////////////
//////Get Position functions
///////////
void Sprite::getPosition(float& a_xPos, float& a_yPos)
/*
//	Returns the position of the Sprite in the variables passed through.
*/
{
	a_xPos = m_xPos;
	a_yPos = m_yPos;
}

void Sprite::getPosition(Vector2& a_v2)
/*
//	Returns the position of the Sprite in the Vector2 passed through.
*/
{
	a_v2 = m_posV2;
}

Vector2 Sprite::getPosition()
/*
//	Returns the position of the sprite in the Vector2 returned.
*/
{
	return m_posV2;
}

void Sprite::getRotation(float& a_fAngle)
{
	a_fAngle = m_fAngle;
}

Vector2 Sprite::getRotateVector()
{

	Vector2 pos;
	getPosition(pos);
	radAngle = radAngle * PI / 180;
	pos.Rotate(radAngle);
	return pos;
}

Vector2 Sprite::getRotateVector(Vector2& a_v2)
{
	radAngle = radAngle * PI / 180;

	Vector2 pos = a_v2;

	pos.Rotate(radAngle);
	return pos;
}

void Sprite::getDeltaRotate(float& a_fDelt)
{
	a_fDelt = deltaRotate;
}

void Sprite::setDeltaRotate(float a_fDelta)
{
	deltaRotate = a_fDelta;
}

/////////////////////////////////////////
/////////////////////////////////////////

void Sprite::Update(float a_deltaTime)
{

}