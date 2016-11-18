#ifndef __TANK_H__
#define __TANK_H__

#include "Player.h"


class Tank : public Player
{
public:

	//Constructors
	Tank();//Default
	Tank(float xPos, float yPos, float width, float height);
	Tank(float xPos, float yPos, float width, float height, float movementSpeed);
	Tank(float xPos, float yPos, float width, float height, float movementSpeed, int health);
	Tank(float width, float height, float movementSpeed, int health);

	//Destructor
	~Tank();

	//ID
	unsigned int  m_spriteID;


	//Functions

	//Update function
	void	Update(float deltaTime);

	//Key setting function is in Player

	//	get functions
	//
	//	Used for getting the current value of 'foo' variable specified in function. Can't change the value here, used set or Addto.
	//
	int		getHealth();
	float	getMoveSpeed();
	float*	getSize();
	float*	getPosition();
	void	getPosition(float& a_xPos, float& a_yPos);
	float	getDirection();
	virtual int getSpriteID();

	//	set functions
	//
	//	Used to set 'foo' variable specified in function. Useful if you know exactly what you want and where.
	//
	int		setSprite(char* a_fileName);
	void	setHealth(int a_health);
	void	setMoveSpeed(float a_moveSpeed);
	void	setSize(float a_width, float a_height);
	void	setSize(float* a_size);
	void	setPosition(float a_xPos, float a_yPos);
	void	setPosition(float* a_position);
	void	setDirection(float a_directionAngle);

	//	addTo functions
	//
	//	Used for adding to current 'foo' variable specified per function. Instead of having to retrieve through get then add in set.
	//

	void	addPositionX(float a_x);
	void	addPositionY(float a_y);
	void	addPositionXY(float a_x, float a_y);
	void	addDirection(float a_angle);

protected:


private:

	float m_height;
	float m_width;
	float m_size[2];//Will always be in order of width then height.

	float m_xPos;
	float m_yPos;
	float m_position[2];//Always in order of Xpos then Ypos
	float m_origin[2];

	float m_movementSpeed;
	float m_directionAngle;//Make this a vector2 when implementing Maths lib. Needs to be normalised too.

	int	  m_health;
	
	unsigned int upKey;
	unsigned int downKey; 
	unsigned int leftKey; 
	unsigned int rightKey;
};

#endif //__TANK_H__
