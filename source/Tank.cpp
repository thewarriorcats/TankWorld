#include "Tank.h"

#include "UGFW.h"
#include "Enumerations.h"

/*
//	Constructors for Tanks found below.
*/

Tank::Tank() : Player()
/*
//	Does nothing except initalise everything to 0 and creates said object.
*/
{
	//SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D, UG::KEY_SPACE);
	SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D);
	m_xPos = 0; m_yPos = 0;
	m_position[0] = m_xPos;
	m_position[1] = m_yPos;

	m_movementSpeed = 0;
	m_health = 0;
	m_width = 0;
	m_height = 0;
	m_directionAngle = 0;

	m_size[0] = 0;
	m_size[1] = 0;
	m_origin[0] = 0.6f;
	m_origin[1] = 0.5f;

	m_spriteID = UG::CreateSprite(".resources/images/TankTop.png", m_size, m_origin);
}

Tank::Tank(float a_xPos, float a_yPos, float a_width, float a_height)
/*
// Sets position to values given and size, also initialises the rest to 0.
*/
{
	//SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D, UG::KEY_SPACE);
	SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D);

	m_xPos = a_xPos;
	m_yPos = a_yPos;
	m_position[0] = m_xPos;
	m_position[1] = m_yPos;

	m_width = a_width;
	m_height = a_height;
	m_size[0] = m_width;
	m_size[1] = m_height;

	m_origin[0] = 0.6f;
	m_origin[1] = 0.5f;

	m_movementSpeed = 0;
	m_health = 0;
	m_directionAngle = 0;

	m_spriteID = UG::CreateSprite(".resources/images/TankTop.png", m_size, m_origin);
}

Tank::Tank(float a_xPos, float a_yPos, float a_width, float a_height, float a_movementSpeed)
/*
// Sets positions, size, and movement speed to given values, also initialises health to 0.
*/
{
	//SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D, UG::KEY_SPACE);
	SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D);

	m_movementSpeed = a_movementSpeed;

	m_xPos = a_xPos;
	m_yPos = a_yPos;
	m_position[0] = m_xPos;
	m_position[1] = m_yPos;



	m_width = a_width;
	m_height = a_height;
	m_size[0] = m_width;
	m_size[1] = m_height;

	m_origin[0] = 0.6f;
	m_origin[1] = 0.5f;

	m_health = 0;
	m_directionAngle = 0;

	m_spriteID = UG::CreateSprite("./images/TankTop.png", m_size, m_origin);
}

Tank::Tank(float a_xPos, float a_yPos, float a_width, float a_height, float a_movementSpeed, int a_health)
/*
// Sets positions, size, movement speed, and health to values given.
*/
{
	//SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D, UG::KEY_SPACE);
	SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D);

	m_movementSpeed = a_movementSpeed;
	m_health = a_health;

	m_xPos = a_xPos;
	m_yPos = a_yPos;
	m_position[0] = m_xPos;
	m_position[1] = m_yPos;

	m_width = a_width;
	m_height = a_height;
	m_size[0] = m_width;
	m_size[1] = m_height;

	m_origin[0] = 0.8f;
	m_origin[1] = 0.5f;

	m_directionAngle = 0;

	m_spriteID = UG::CreateSprite("./images/TankTop.png", m_size, m_origin);
}

Tank::Tank(float a_width, float a_height, float a_movementSpeed, int a_health)
/*
//	Sets size, movement speed and health to values given, initialises xPos and yPos to 0.
*/
{
	//SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D, UG::KEY_SPACE);
	SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D);

	m_xPos = 0; m_yPos = 0;
	m_position[0] = m_xPos; m_position[1] = m_yPos;

	m_movementSpeed = a_movementSpeed;
	m_health = a_health;

	m_width = a_width;
	m_height = a_height;
	m_size[0] = m_width;
	m_size[1] = m_height;

	m_directionAngle = 0;

	m_origin[0] = 0.6f;
	m_origin[1] = 0.5f;

	m_spriteID = UG::CreateSprite(".resources/images/TankTop.png", m_size, m_origin);
}

/*
//	Tank destructor
*/

Tank::~Tank()
/*
//	Deletes the tank.
*/
{
//	delete this;
}

/*
//	Class functions
*/

void Tank::Update(float a_dt)
{
	if (UG::IsKeyDown(UG::KEY_LEFT))
	{
		UG::RotateSprite(m_spriteID, 5.f);
	}
	if (UG::IsKeyDown(UG::KEY_RIGHT))
	{
		UG::RotateSprite(m_spriteID, -5.f);
	}
}

// Get functions

int Tank::getHealth()
/*
//	Returns this tanks Health as an integer.
*/
{
	return m_health;
}

float Tank::getMoveSpeed()
/*
//	Returns this tanks Movement speed as a float.
*/
{
	return m_movementSpeed;
}

float* Tank::getSize()
/*
//	Returns a pointer to an array with width first then height inside it.
*/
{
	return m_size;
}

float* Tank::getPosition()
/*
//	Returns a pointer to an array with xPos first then yPos inside it.
*/
{
	return m_position;
}

void Tank::getPosition(float& a_xPos, float& a_yPos)
/*
//	Provides you with the xPos and yPos of the tank in the variables you provide (By reference).
*/
{
	a_xPos = m_xPos;
	a_yPos = m_yPos;
}

float Tank::getDirection()
/*
//	Returns the angle (direction) the tank is facing.
*/
{
	return m_directionAngle;
}

int Tank::getSpriteID()
/*
//	Returns the spriteID for the Tank.
*/
{
	return m_spriteID;
}

//	Set functions
int Tank::setSprite(char* a_fileName)
{
	return m_spriteID = UG::CreateSprite(a_fileName, m_size, m_origin);
}

void Tank::setHealth(int a_health)
/*
//	Sets health to value given.
*/
{
	m_health = a_health;
}

void Tank::setMoveSpeed(float a_moveSpeed)
/*
//	Sets movement speed to value given.
*/
{
	m_movementSpeed = a_moveSpeed;
}

void Tank::setSize(float a_width, float a_height)
/*
//	Sets size of Tank, with variables given. Also assigns these variables to the size array.
*/
{
	m_width = a_width;
	m_height = a_height;

	m_size[0] = a_width;
	m_size[1] = a_height;
}

void Tank::setSize(float* a_size)
/*
//	Sets the Size array with the array passed in. Expected to be width then height order.
*/
{
	m_size[0] = a_size[0];
	m_size[1] = a_size[1];
}

void Tank::setPosition(float a_xPos, float a_yPos)
/*
//	Sets position to values given. X Position and Y Position respectively.
*/
{
	m_xPos = a_xPos;
	m_yPos = a_yPos;
}

void Tank::setPosition(float* a_position)
/*
//	Sets the Size array with the array passed in. Expected to be width then height order.
*/
{
		m_position[0] = m_position[0];
		m_position[1] = m_position[1];
}

void Tank::setDirection(float a_directionAngle)
/*
// The angle entered will be made the angle the tank is facing.
*/
{
	m_directionAngle = a_directionAngle;
}

//	addTo Functions

void Tank::addPositionX(float a_x)
/*
//	Adds amount given to current X Pos.
*/
{
	m_xPos = m_xPos + a_x;
}

void Tank::addPositionY(float a_y)
/*
//	Adds amount given to current Y Pos.
*/
{
	m_yPos = m_yPos + a_y;
}

void Tank::addPositionXY(float a_x, float a_y)
/*
//	Adds amount given to current X and Y Pos.
*/
{
	m_xPos = m_xPos + a_x;
	m_yPos = m_yPos + a_y;
}

void Tank::addDirection(float a_angle)
/*
//	Adds angle given ontop of current angle / direction of tank.
*/
{
	m_directionAngle = m_directionAngle + a_angle;
}
