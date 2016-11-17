#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Sprite.h"
#include "Bullet.h"

class Player : public Sprite
{
public:

	Player();
	Player(char* fileName, float width, float height);
	Player(char* fileName, float width, float height, Vector2 origin);
	Player(char* fileName, float width, float height, int health);
	virtual ~Player();

	void	 SetControlKeys(unsigned int a_up, unsigned int a_down, unsigned int a_left, unsigned int a_right);
	void	 SetHealth(int health);
	void	 SetMovementSpeed(Vector2 velocity);
	void	 SetDirection(Vector2 direction);

	int			getHealth();
	Vector2		getVelocity();
	void		getVelocity(Vector2& velocity);
	Vector2		getDirection();
	void		getDirection(Vector2& direction);
	virtual int getSpriteID();

	virtual void Update(float deltaTime);
	void Rotate(float rotateAngle);

	bool TestCollision(Player& playerTwo);
	bool TestCollision(Sprite& a_wall);
	bool TestIfHit(Bullet& bullet);



protected:

private:

	Vector2		 m_velocityV2;


	Vector2		 m_directionV2;///////////////////////
							   //0,0			1,0 //
	int			 m_health;	   //					//
							   //					//
							   //		 0,5		//
							   //					//
	unsigned int upKey;		   // 1,0			1,1 //
	unsigned int downKey;	   ///////////////////////
	unsigned int leftKey;
	unsigned int rightKey;

	unsigned int m_iSpriteID;

};

//             [~]
//             |=|
//           .-' '-.
//           |-----|
//           | ~~~ |
//           | ~~~ |
//           | XXX |
//           |-----|
//           '-----'
//
//		 Well deserved, Pig.

#endif