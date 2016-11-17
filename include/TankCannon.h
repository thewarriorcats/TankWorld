#ifndef __TANKCANNON_H__
#define __TANKCANNON_H__

#include "Player.h"

class TankCannon : public Player
{
public:

	TankCannon();
	TankCannon(char* fileName, float width, float height);
	TankCannon(char* fileName, float width, float height, float xPos, float yPos);
	TankCannon(char* fileName, float width, float height, Vector2 a_v2Velocity, float xPos, float yPos);
	TankCannon(char* fileName, float width, float height, Vector2 origin);
	~TankCannon() {};

	void SetKeys(unsigned int a_rotateLeft, unsigned int a_rotateRight, unsigned int a_shootKey);

	void Update(float a_fDeltaTime);

	void Rotate(float a_fAngle);

	bool checkFiring();


	Vector2 getRotateVector();
	Vector2 getRotateVector(Vector2& a_v2);


protected:

private:

	unsigned int rLeftKey;
	unsigned int rRightKey;
	unsigned int shootKey;
	bool		 isFiring;

	float m_height;
	float m_width;
	Vector2 m_v2Size;

	float m_xPos;
	float m_yPos;
	Vector2 m_v2Pos;
	Vector2 m_origin;

	Vector2 m_v2Velocity;

	float m_rotationAngle = 90;
	float deltaRotate = 120.f;

};

#endif