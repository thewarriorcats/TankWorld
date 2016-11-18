#include "Player.h"

#include "UGFW.h"
#include <iostream>

Player::Player()
{

}

Player::Player(char* fileName, float a_width, float a_height) : Sprite(fileName, a_width, a_height, 0, 0)
{
	m_health = 0;
	m_directionV2.x = 0;
	m_directionV2.y = 0;
}

Player::Player(char* fileName, float width, float height, Vector2 origin) : Sprite(fileName, width, height, origin)
{
	m_health = 0;
	m_directionV2.x = 0;
	m_directionV2.y = 0;
}

Player::Player(char* fileName, float a_width, float a_height, int a_health) :Sprite(fileName, a_width, a_height, 0, 0)
{
	m_health = a_health;
	m_directionV2.x = 0;
	m_directionV2.y = 0;
}

Player::~Player()
{
}

void Player::SetControlKeys(unsigned int a_up, unsigned int a_down, unsigned int a_left, unsigned int a_right)
{
	upKey = a_up;
	downKey = a_down;
	leftKey = a_left;
	rightKey = a_right;
}

void Player::SetHealth(int a_health)
{
	m_health = a_health;
}

void Player::SetMovementSpeed(Vector2 a_v2)
{
	m_velocityV2 = a_v2;
}

void Player::SetDirection(Vector2 a_v2)
{
	m_directionV2 = a_v2;
}

int Player::getHealth()
{
	return m_health;
}

Vector2 Player::getVelocity()
{
	return m_velocityV2;
}

void Player::getVelocity(Vector2& a_vel)
{
	a_vel = m_velocityV2;
}

Vector2 Player::getDirection()
{
	return m_directionV2;
}

void Player::getDirection(Vector2& a_v2)
{
	a_v2 = m_directionV2;
}

int Player::getSpriteID()
{
	return Sprite::getSpriteID();
}

void Player::Update(float a_fDeltaTime)
{
	float xPos; float yPos;

	
	//Movement control
	if (UG::IsKeyDown(upKey))
	{
		getPosition(xPos, yPos);
		radAngle = rotationAngle - 180;

		SetRotation(rotationAngle);


		SetPosition(getRotateVector());
	}
	if (UG::IsKeyDown(downKey))
	{
		getPosition(xPos, yPos);

		radAngle = rotationAngle;
		SetPosition(getRotateVector());

	}
	if (UG::IsKeyDown(leftKey))
	{

		Rotate(deltaRotate*a_fDeltaTime);
		rotationAngle -= (deltaRotate*a_fDeltaTime);
		//getPosition(xPos, yPos);
		//SetPosition(xPos - ((m_velocityV2.x*a_fDeltaTime)*20), yPos);
	}
	if (UG::IsKeyDown(rightKey))
	{

		Rotate(-deltaRotate*a_fDeltaTime);
		rotationAngle += (deltaRotate*a_fDeltaTime);

		//Rotate(-2.f);
		//rotationAngle += 2.f;
		//getPosition(xPos, yPos);
		//SetPosition(xPos + ((m_velocityV2.x*a_fDeltaTime)*20), yPos);
	}
}

void Player::Rotate(float a_fAngle)
{
	UG::RotateSprite(Sprite::getSpriteID(), a_fAngle);
	m_directionV2.operator+(a_fAngle);
}

bool Player::TestCollision(Player& a_player2)
{
	//Get the dimensions and size of the ball
	float playerOneX = 0.f, playerOneY = 0.f;
	float playerOneWidth = 0.f, playerOneHeight = 0.f;

	this->getPosition(playerOneX, playerOneY);
	this->getSize(playerOneWidth, playerOneHeight);
	//Draws from centres, get half size
	playerOneWidth *= 0.5f;
	playerOneHeight *= 0.5f;

	//Get the dimensions and position of the paddle
	float playerTwoX = 0.f, playerTwoY = 0.f;
	float playerTwoWidth = 0.f, playerTwoHeight = 0.f;

	a_player2.getPosition(playerTwoX, playerTwoY);
	a_player2.getSize(playerTwoWidth, playerTwoHeight);

	//drawn from center so get half the sizes
	playerTwoWidth *= 0.5f;
	playerTwoHeight *= 0.5f;


	//Remember that the sprite draws from the center.

	if (playerOneX + playerOneWidth > playerTwoX - playerTwoWidth && playerOneX - playerOneWidth < playerTwoX + playerTwoWidth)
		//If within x dimensions of each other, test Y
	{
		if (playerOneY + playerOneHeight > playerTwoY - playerTwoHeight && playerOneY - playerOneHeight < playerTwoY + playerTwoHeight)
			//Also within Y dimensions, must be colliding!
		{
			return true;
		}
	}
	return false;

}

bool Player::TestCollision(Sprite& a_wall)
{
	//Get the dimensions and size of the ball
	float playerOneX = 0.f, playerOneY = 0.f;
	float playerOneWidth = 0.f, playerOneHeight = 0.f;

	getPosition(playerOneX, playerOneY);
	getSize(playerOneWidth, playerOneHeight);
	//Draws from centres, get half size
	playerOneWidth *= 0.5f;
	playerOneHeight *= 0.5f;

	//Get the dimensions and position of the paddle
	float wallX = 0.f, wallY = 0.f;
	float wallWidth = 0.f, wallHeight = 0.f;

	a_wall.getPosition(wallX, wallY);
	a_wall.getSize(wallWidth, wallHeight);

	//drawn from center so get half the sizes
	wallWidth *= 0.5f;
	wallHeight *= 0.5f;


	//Remember that the sprite draws from the center.

	if (playerOneX + playerOneWidth > wallX - wallWidth && playerOneX - playerOneWidth < wallX + wallWidth)
		//If within x dimensions of each other, test Y
	{
		if (playerOneY + playerOneHeight > wallY - wallHeight && playerOneY - playerOneHeight < wallY + wallHeight)
			//Also within Y dimensions, must be colliding!
		{
			return true;
		}
	}
	return false;

}

bool Player::TestIfHit(Bullet& a_bullet)//For testing if hit with a bullet.. Might make this use a Template object type.
{
	//Get the dimensions and size of the ball
	float playerOneX = 0.f, playerOneY = 0.f;
	float playerOneWidth = 0.f, playerOneHeight = 0.f;

	this->getPosition(playerOneX, playerOneY);
	this->getSize(playerOneWidth, playerOneHeight);
	//Draws from centres, get half size
	playerOneWidth *= 0.5f;
	playerOneHeight *= 0.5f;

	//Get the dimensions and position of the paddle
	float playerTwoX = 0.f, playerTwoY = 0.f;
	float playerTwoWidth = 0.f, playerTwoHeight = 0.f;

	a_bullet.getPosition(playerTwoX, playerTwoY);
	a_bullet.getSize(playerTwoWidth, playerTwoHeight);

	//drawn from center so get half the sizes
	playerTwoWidth *= 0.5f;
	playerTwoHeight *= 0.5f;


	//Remember that the sprite draws from the center.

	if (playerOneX + playerOneWidth > playerTwoX - playerTwoWidth && playerOneX - playerOneWidth < playerTwoX + playerTwoWidth)
		//If within x dimensions of each other, test Y
	{
		if (playerOneY + playerOneHeight > playerTwoY - playerTwoHeight && playerOneY - playerOneHeight < playerTwoY + playerTwoHeight)
			//Also within Y dimensions, must be colliding!
		{
			return true;
		}
	}
	return false;

}