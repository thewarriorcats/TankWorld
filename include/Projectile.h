#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "mathLib.h"

class Projectile
{

public:

	Projectile();
	Projectile(char* fileName, float width, float height, float xPos, float yPos);
	Projectile(char* fileName, Vector2 size, Vector2 position);

	virtual ~Projectile();

	virtual void Update(float deltaTime);

	////////////////////////////////////////////////////////////////////////////////////////
	//
	//							GET FUNCTIONS
	//
	////////////////////////////////////////////////////////////////////////////////////////

	int			getSpriteID();

	void		getPosition(float& xPos, float& yPos);
	void		getPosition(Vector2& a_v2);
	Vector2	    getPosition();
	
	Vector2		getPerpendicularAngle();

	void		getSpeed(float& speedX);
	float		getSpeed();

	void		getSize(float& a_width, float& a_height);
	Vector2		getSize();

	void		getDirection(float& directionX, float& directionY);
	void		getDirection(Vector2& a_v2);
	Vector2		getDirection();

	////////////////////////////////////////////////////////////////////////////////////////
	//
	//							SET FUNCTIONS
	//
	////////////////////////////////////////////////////////////////////////////////////////

	void		setPosition(float xPos, float yPos);
	void		setPosition(Vector2 position);

	void		setSpeed(float speedX);

	void		setSize(float width, float height);
	void		setSize(Vector2 size);

	void		setDirection(float directionX, float directionY);
	void		setDirection(Vector2 a_direction);

protected:

private:

	float m_Speed;

	float m_directionX;
	float m_directionY;
	Vector2 m_directionV2;

	float m_xPos;
	float m_yPos;
	Vector2 m_posV2;

	float m_width;
	float m_height;
	Vector2 m_sizeV2;

	unsigned int m_iSpriteID;
};

#endif //__PROJECTILE_H__