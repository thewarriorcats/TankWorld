#include "Bullet.h"

#include "UGFW.h"
#include "Enumerations.h"

Bullet::Bullet()
{

}

Bullet::Bullet(char* fileName, float a_width, float a_height, float a_xPos, float a_yPos) : Projectile(fileName, a_width, a_height, a_xPos, a_yPos)
{

}

Bullet::~Bullet()
{

}

void Bullet::Update(float a_fDeltatime)
{
	float xPos; float yPos;
	
	getPosition(xPos, yPos);

	Vector2 direction = getDirection();

	xPos += direction.x * getSpeed() * a_fDeltatime;
	yPos += direction.y * getSpeed() * a_fDeltatime;

	setPosition(xPos, yPos);

	UG::MoveSprite(getSpriteID(), xPos, yPos);
}

bool Bullet::TestCollision(Sprite a_wall)
{
	//Get the dimensions and size of the wall

	float wallX = 0; float wallY = 0;
	float wallWidth; float wallHeight;

	a_wall.getPosition(wallX, wallY);
	a_wall.getSize(wallWidth, wallHeight);

	wallWidth *= 0.5f; //Need half the size as origin is center.
	wallHeight *= 0.5f; //Need half of height because ^

	//Get dimensions now for the bullet.

	float myX = 0; float myY = 0;
	float myWidth = 0; float myHeight = 0;

	getPosition(myX, myY);
	getSize(myWidth, myHeight);
	
	myWidth *= 0.5f;
	myHeight *= 0.5f;//Same as above.




	if (wallX + wallWidth > myX - myWidth && wallX - wallWidth < myX + myWidth)
		//If within x dimensions of each other, test Y
	{
		if (wallY + wallHeight > myY - myHeight && wallY - wallHeight < myY + myHeight)
			//Also within Y dimensions, must be colliding!
		{
			return true;
		}
	}
	return false;
}