#include "Pickups.h"

Pickups::Pickups() : Sprite()
{
	setBigBullets(false);
	setShrinkPlayer(false);
	setSpeedBoost(false);
}

Pickups::Pickups(char* fileName, float a_width, float a_height) : Sprite(fileName, a_width, a_height)
{
	m_width = a_width;
	m_height = a_height;
	m_sizev2.Set(m_width, m_height);

	setBigBullets(false);
	setShrinkPlayer(false);
	setSpeedBoost(false);
}

Pickups::Pickups(char* fileName, float a_width, float a_height, float xPos, float yPos) : Sprite(fileName, a_width, a_height, xPos, yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_Posv2.Set(m_xPos, m_yPos);

	m_width = a_width;
	m_height = a_height;
	m_sizev2.Set(m_width, m_height);

	setBigBullets(false);
	setShrinkPlayer(false);
	setSpeedBoost(false);
}

void Pickups::Update(float a_fDeltaTime)
{

}

void Pickups::getSize(float& a_x, float& a_y)
{
	a_x = m_xPos;
	a_y = m_yPos;
}

void Pickups::getSize(Vector2& a_v2)
{
	a_v2 = m_sizev2;
}

void Pickups::getPosition(Vector2& a_v2)
{
	a_v2 = m_Posv2;
}

void Pickups::getPosition(float& a_x, float& a_y)
{
	a_x = m_xPos;
	a_y = m_yPos;
}

bool Pickups::TestCollision(Player& a_player)
{
	//Get the dimensions and size of the ball
	float collectableX = 0.f, collectableY = 0.f;
	float collectableWidth = 0.f, collectableHeight = 0.f;

	getPosition(collectableX, collectableY);
	getSize(collectableWidth, collectableHeight);
	//Draws from centres, get half size
	collectableWidth *= 0.5f;
	collectableHeight *= 0.5f;//Gives it a square hitbox but oh well.

	//Get the dimensions and position of the paddle
	float playerX = 0.f, playerY = 0.f;
	float playerWidth = 0.f, playerHeight = 0.f;

	a_player.getPosition(playerX, playerY);
	a_player.getSize(playerWidth, playerHeight);

	//drawn from center so get half the sizes
	playerWidth *= 0.5f;
	playerHeight *= 0.5f;


	//Remember that the sprite draws from the center.

	if (collectableX + collectableWidth > playerX - playerWidth && collectableX - collectableWidth < playerX + playerWidth)
		//If within x dimensions of each other, test Y
	{
		if (collectableY + collectableHeight > playerY - playerHeight && collectableY - collectableHeight < playerY + playerHeight)
			//Also within Y dimensions, must be colliding!
		{
			return true;
		}
	}
	return false;
}

void Pickups::setSpeedBoost(bool set)
{
	speedBoost = set;
}

void Pickups::setBigBullets(bool set)
{
	biggerBullet = set;
}

void Pickups::setShrinkPlayer(bool set)
{
	shrinkPlayer = set;
}

bool Pickups::isSpeedBoost()
{
	return speedBoost;
}

bool Pickups::isBigBullets()
{
	return biggerBullet;
}

bool Pickups::isShrinkPlayer()
{
	return shrinkPlayer;
}
