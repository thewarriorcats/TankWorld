#ifndef __PICKUPS_H__
#define __PICKUPS_H__

#include "Sprite.h"
#include "Player.h"

class Pickups : public Sprite
{

public:

	Pickups();
	~Pickups() {};
	Pickups(char* fileName, float a_width, float a_height);
	Pickups(char* fileName, float a_width, float a_height, float xPos, float yPos);

	virtual void Update(float a_fDeltaTime);

	void getSize(float& a_x, float& a_y);
	void getSize(Vector2& a_v2);

	void getPosition(Vector2& a_v2);
	void getPosition(float& a_x, float& a_y);

	bool TestCollision(Player& player);

	void setSpeedBoost(bool set);
	void setBigBullets(bool set);
	void setShrinkPlayer(bool set);

	bool isSpeedBoost();
	bool isBigBullets();
	bool isShrinkPlayer();

protected:

private:



	float m_width;
	float m_height;
	Vector2 m_sizev2;

	float m_xPos; 
	float m_yPos;
	Vector2 m_Posv2;

	bool speedBoost;
	bool biggerBullet;
	bool shrinkPlayer;

};

#endif