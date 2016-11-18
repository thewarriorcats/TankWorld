#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "mathLib.h"

class Sprite
{
public:

	Sprite();
	Sprite(char* fileName);
	Sprite(char* fileName, float width, float height);
	Sprite(char* fileName, float width, float height, float xPos, float yPos);
	Sprite(char* fileName, float width, float height, Vector2 origin);
	virtual ~Sprite();


	////////////////////////////////////////////////////////////////////////////////////////
	//
	//							SET FUNCTIONS
	//
	////////////////////////////////////////////////////////////////////////////////////////
	void SetSprite(char* fileName);

	void SetSize(float width, float height);
	void SetSize(Vector2 size);

	void SetPosition(float xPos, float yPos);
	void SetPosition(Vector2 position);

	void SetRotation(float a_fAngle);

	////////////////////////////////////////////////////////////////////////////////////////
	//
	//							GET FUNCTIONS
	//
	////////////////////////////////////////////////////////////////////////////////////////
	virtual int  getSpriteID();

	void getSize(float& width, float& height);
	void getSize(Vector2& size);
	Vector2 getSize();

	void getPosition(float& xPos, float& yPos);
	void getPosition(Vector2& position);
	Vector2 getPosition();

	void getRotation(float& a_fAngle);
	Vector2 getRotateVector();
	Vector2 getRotateVector(Vector2& a_v2);

	void getDeltaRotate(float& a_fDelt);
	void setDeltaRotate(float a_fDelt);

	//////////////////////////////////////
	//////////////////////////////////////


	virtual  void Update(float deltaTime);


protected:
	double PI = 3.14159265359f;
	float  rotationAngle = 270;
	float  radAngle = 90;
	float deltaRotate = 60.f;

private:

	unsigned int m_iSpriteID;
	
	float m_width;
	float m_height;
	Vector2 m_sizeV2;
		 
	float m_fAngle;

	float m_xPos;
	float m_yPos;
	Vector2 m_posV2;


};

#endif //__SPRITE_H__
