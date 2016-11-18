#ifndef __BULLET_H__
#define __BULLET_H__

#include "mathLib.h"
#include "Projectile.h"
#include "Sprite.h"

class Bullet : public Projectile
{
public:

	Bullet();
	Bullet(char* fileName, float width, float height, float xPos, float yPos);
	~Bullet();

	void Update(float deltaTime);

	bool TestCollision(Sprite a_wall);
protected:

private:

};

#endif //__BULLET_H__