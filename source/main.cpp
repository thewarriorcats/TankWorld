/*
//////////////////////////////////////////////////////////////////////////////////////
//
//							Author: Kieran Bond
//
//							Game: Tiny Tanks / LeTank
//
//							Alpha r/d: 18/05/2016
//
//	PLANS TO INCLUDE
//
//	Mouse tracking aim.
//	More pickups - Shields, lives, super bouncy ammo.
//  Health system / lives system
//	Online Multiplayer?
//	Submit work
//
//	random levels
//
//////////////////////////////////////////////////////////////////////////////////////
*/
#include "UGFW.h"
#include "Enumerations.h"
#include <iostream>
#include <sstream>
#include <iomanip>

#include "Sprite.h"
#include "Projectile.h"
#include "Player.h"
#include "TankCannon.h"
#include "Bullet.h"
#include "Pickups.h"
#include "mathLib.h"


int main(int argv, char* argc[])
{
	//Use wherever variables
	float xPos = 0; float yPos = 0;

	float bulletSpeed = 800;
	float pickupTimer = 0;





	//Create the framework, singleton approach.
	if (UG::Create(1080, 720, false, "LeTank", 100, 100))//width, height, fullscreen, window name, xPos, yPos
	{
		////////////////////////////////////////////////
		//
		//		Do any creating/setup stuff here.
		//
		////////////////////////////////////////////////

		//Set background colour - In RGBA channels (Red, Green, Blue, Alpha)
		UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0xFF));
		
		//Variables used for when in need of Screen height and width. Useful af.
		int m_screenHeight = 0; int m_screenWidth = 0;
		UG::GetScreenSize(m_screenWidth, m_screenHeight);//Sets said variables for now.

		//Creation of all objects.

		//Players
		Player playerOne("./images/TankBottomGreen.png", 128.f, 96.f);//PlayerOne constructor
		Player playerTwo("./images/TankBottomRed.png", 128.f, 96.f);//PlayerTwo constructor

		//Players guns
		TankCannon playerOneGun("./images/TankGunGreen.png", 128.f, 96.f, Vector2(1, 1));//Cannon for playerOne constructor.
		TankCannon playerTwoGun("./images/TankGunRed.png", 128.f, 96.f, Vector2(1, 1));//Cannon for playerTwo constructor.

		//Extras
		//Walls

		Sprite wallBot("./images/Wall.png", 0, 0, 0, 0);//Filename, width, height, xPos, yPos
		wallBot.SetSize(m_screenWidth * 2.f, 10.f);//width, height
		wallBot.SetPosition(m_screenWidth/2, 10.f);//xPos, yPos

		Sprite wallLeft("./images/Wall.png", 0, 0, 0, 0);//Filename, width, height, xPos, yPos
		wallLeft.SetSize(10, m_screenHeight*2);//Width, height
		wallLeft.SetPosition(0, m_screenHeight/2);//xPos, yPos

		Sprite wallRight("./images/Wall.png", 0, 0, 0, 0);//Filename, width, height, xPos, yPos
		wallRight.SetSize(10, m_screenHeight * 2);//width height
		wallRight.SetPosition(m_screenWidth, m_screenHeight/2);//xpos, ypos

		Sprite wallTop("./images/Wall.png", 0, 0, 0, 0);//filename, width, height, xpos, ypos
		wallTop.SetSize(m_screenWidth*2, 10);//width height
		wallTop.SetPosition(m_screenWidth/2, m_screenHeight);//xpos, ypos


		//Bullets

		Bullet bl2("./images/bullet.png", 16, 24, 10, 10);
		Bullet bl1("./images/bullet.png", 16
			 , 24, 10, 10);

		//Pickups

		Pickups pick1("./images/DiamondPickup.png", 32, 32);
		pick1.SetPosition(200, 500);


		//Sorting shit
		
		bl1.setDirection(0, 0);
		bl2.setDirection(0, 0);
		bl1.setSpeed(0);
		bl2.setSpeed(0);
		
		playerOne.SetPosition(m_screenWidth*0.2f, m_screenHeight*0.2f);
		playerOne.SetControlKeys(UG::KEY_W, UG::KEY_S, UG::KEY_A, UG::KEY_D);
		
		playerOne.SetMovementSpeed(Vector2(10,10));
		playerOneGun.SetKeys(UG::KEY_Q, UG::KEY_E, UG::KEY_SPACE);
			  			  

		playerTwo.SetPosition(m_screenWidth*0.8f, m_screenHeight*0.8f);
		playerTwo.SetControlKeys(UG::KEY_UP, UG::KEY_DOWN, UG::KEY_LEFT, UG::KEY_RIGHT);
		playerTwo.SetMovementSpeed(Vector2(10, 10));
		playerTwoGun.SetKeys(UG::KEY_KP_1, UG::KEY_KP_2, UG::KEY_KP_ENTER);
			  




		//Move Sprites
		//Players
		playerOne.getPosition(xPos, yPos);

		UG::MoveSprite(playerOne.getSpriteID(), xPos, yPos);
		UG::MoveSprite(playerOneGun.getSpriteID(), xPos, yPos);

		playerTwo.getPosition(xPos, yPos);

		UG::MoveSprite(playerTwo.getSpriteID(), xPos, yPos);
		UG::MoveSprite(playerTwoGun.getSpriteID(), xPos, yPos);
		//Extras
		wallBot.getPosition(xPos, yPos);
		UG::MoveSprite(wallBot.getSpriteID(), xPos, yPos);

		wallLeft.getPosition(xPos, yPos);
		UG::MoveSprite(wallLeft.getSpriteID(), xPos, yPos);

		wallRight.getPosition(xPos, yPos);
		UG::MoveSprite(wallRight.getSpriteID(), xPos, yPos);

		wallTop.getPosition(xPos, yPos);
		UG::MoveSprite(wallTop.getSpriteID(), xPos, yPos);

		UG::MoveSprite(bl1.getSpriteID(), 10, 10);
		UG::MoveSprite(bl2.getSpriteID(), 500, 500);

		pick1.getPosition(xPos, yPos);
		pick1.SetPosition(200, 500);
		UG::MoveSprite(pick1.getSpriteID(), 200, 500);

		//All draws
		//Extras
		UG::DrawSprite(wallBot.getSpriteID());
		UG::DrawSprite(wallLeft.getSpriteID());
		UG::DrawSprite(wallRight.getSpriteID());
		UG::DrawSprite(wallTop.getSpriteID());

		UG::DrawSprite(bl1.getSpriteID());
		UG::DrawSprite(bl2.getSpriteID());

		UG::DrawSprite(pick1.getSpriteID());

		//Players
		UG::DrawSprite(playerOne.getSpriteID());
		UG::DrawSprite(playerOneGun.getSpriteID());

		UG::DrawSprite(playerTwo.getSpriteID());
		UG::DrawSprite(playerTwoGun.getSpriteID());


		//--------------------------------------------------------------------------
		//--------------------------------------------------------------------------

		/////////////////////////////////////////////
		//
		//		Update loop is here. Any updating that
		//		needs doing, do it here.
		//
		/////////////////////////////////////////////

		do
		{
			//DeltaTime is time inbetween each update/frame.
			float fDeltaTime = UG::GetDeltaTime();
			pickupTimer++;

			if (pickupTimer >= 300)
			{
				if (pick1.isSpeedBoost())
				{
					pick1.setSpeedBoost(false);

					Vector2 pl1Vel = playerOne.getVelocity();
					Vector2 pl2Vel = playerTwo.getVelocity();

					if ((pl1Vel.x > pl2Vel.x) && (pl1Vel.y > pl2Vel.y))//If player one = bigger vel = has pickup. Restore.
					{
						pl1Vel.x = pl2Vel.x;
						pl1Vel.y = pl2Vel.y;
					}
					else if ((pl1Vel.x < pl2Vel.x) && (pl1Vel.y < pl2Vel.y))
					{
						pl2Vel.x = pl1Vel.x;
						pl2Vel.y = pl1Vel.y;
					}
				}
			}
			

			wallLeft.Update(fDeltaTime);
			wallRight.Update(fDeltaTime);
			wallBot.Update(fDeltaTime);
			wallTop.Update(fDeltaTime);


			//\////////////////////////////////////////////////////////////////////////////////////////////
			//\////////////////////////////////////////////////////////////////////////////////////////////
			//\////////////////////////////////////////////////////////////////////////////////////////////
			//\//////////////////////////////////// COLLISION TESTING /////////////////////////////////////S

			if (pick1.TestCollision(playerOne))
			{
				UG::StopDrawingSprite(pick1.getSpriteID());

				pick1.setSpeedBoost(true);

				Vector2 plVel = playerOne.getVelocity();
				plVel.x *= 1.4;
				plVel.y *= 1.4;
				playerOne.SetMovementSpeed(plVel);
			}

			if (pick1.TestCollision(playerTwo))
			{
				std::cout << "DIAMONDS" << std::endl;
				UG::StopDrawingSprite(pick1.getSpriteID());

				pick1.setSpeedBoost(true);

				float delt = 0;
				playerTwo.getDeltaRotate(delt);
				playerTwo.setDeltaRotate(delt*1.4);
			}

			if (playerOne.TestIfHit(bl2))//Player one collision with bullet.
			{
				/*
				//	Does a full reset of the stage. Starts the winner at the higher position on screen right.
				*/
				playerOne.SetPosition(Vector2(m_screenWidth*0.2f, m_screenHeight*0.3f));
				playerTwo.SetPosition(Vector2(m_screenWidth*0.8f, m_screenHeight*0.7f));


				bl1.setDirection(0, 0);
				bl2.setDirection(0, 0);
				bl1.setSpeed(0);
				bl2.setSpeed(0);

				bl1.setPosition(-100, -100);
				bl2.setPosition(-100, -100);
			}

			if (playerTwo.TestIfHit(bl1))
			{
				/*
				//	Does a full reset of the stage. Starts the winner at the higher position on screen right.
				*/
				playerOne.SetPosition(Vector2(m_screenWidth*0.8f, m_screenHeight*0.7f));
				playerTwo.SetPosition(Vector2(m_screenWidth*0.2f, m_screenHeight*0.3f));

				bl1.setDirection(0, 0);
				bl2.setDirection(0, 0);
				bl1.setSpeed(0);
				bl2.setSpeed(0);

				bl1.setPosition(-100, -100);
				bl2.setPosition(-100, -100);
			}

			if ((bl1.TestCollision(wallBot)) || (bl1.TestCollision(wallLeft)) || (bl1.TestCollision(wallRight)) || (bl1.TestCollision(wallTop)))
			{
				
				Vector2 bullPos(0, 0);
				bl1.getPosition(bullPos);


				bullPos = bl1.getPerpendicularAngle();
				bl1.setDirection(bullPos);

				bl1.getPosition(bullPos);
				
			}

			if ((bl2.TestCollision(wallBot)) || (bl2.TestCollision(wallLeft)) || (bl2.TestCollision(wallRight)) || (bl2.TestCollision(wallTop)))
			{

				Vector2 bullPos(0, 0);
				bl2.getPosition(bullPos);

				bullPos = bl2.getPerpendicularAngle();
				bl2.setDirection(bullPos);

				bl2.getPosition(bullPos);

			}

			//Player one shooting updating
			
			playerOne.Update(fDeltaTime);//Actual update
			playerOne.getPosition(xPos, yPos);
			Vector2 plSize = playerOne.getSize();


			//PlayerOne wall tests

			if (playerOne.TestCollision(wallBot))
			{
				playerOne.getPosition(xPos, yPos);
				playerOne.SetPosition(xPos, yPos+1);
			}
			if (playerOne.TestCollision(wallLeft))
			{
				playerOne.getPosition(xPos, yPos);
				playerOne.SetPosition(xPos + 1, yPos);
			}

			if (playerOne.TestCollision(wallTop))
			{
				playerOne.getPosition(xPos, yPos);
				playerOne.SetPosition(xPos, yPos-1);
			}
			
			if (playerOne.TestCollision(wallRight))
			{
				playerOne.getPosition(xPos, yPos);
				playerOne.SetPosition(xPos - 1, yPos);
			}

			bool p1Fired = playerOneGun.checkFiring();
			bool p2Fired = playerTwoGun.checkFiring();

			if (p1Fired)
			{
				Vector2 ang(0,0);
				ang = playerOneGun.getRotateVector();
				std::cout << "x " << ang.x << " Y: " << ang.y << std::endl;
				bl1.setDirection(ang);
				bl1.setPosition(Vector2(xPos, yPos));
				bl1.setSpeed(bulletSpeed);
			}


			//Updates for player two shooting
			playerTwo.Update(fDeltaTime);
			playerTwo.getPosition(xPos, yPos);
			if (p2Fired)
			{
				Vector2 ang(0, 0);
				ang = playerTwoGun.getRotateVector();
				std::cout << "x " << ang.x << " Y: " << ang.y << std::endl;
				bl2.setDirection(ang);
				bl2.setPosition(Vector2(xPos, yPos));
				bl2.setSpeed(bulletSpeed);
			}


			//Player One Gun updating
			playerOneGun.Update(fDeltaTime);//Actual update
			playerOne.getPosition(xPos, yPos);//Using player one's pos because this gun needs to be on top of it
			UG::MoveSprite(playerOneGun.getSpriteID(), xPos, yPos);

			//PlayerTwo wall tests

			if (playerTwo.TestCollision(wallBot))
			{
				playerTwo.getPosition(xPos, yPos);
				playerTwo.SetPosition(xPos, yPos + 1);
			}
			if (playerTwo.TestCollision(wallLeft))
			{
				playerTwo.getPosition(xPos, yPos);
				playerTwo.SetPosition(xPos + 1, yPos);
			}

			if (playerTwo.TestCollision(wallTop))
			{
				playerTwo.getPosition(xPos, yPos);
				playerTwo.SetPosition(xPos, yPos - 1);
			}

			if (playerTwo.TestCollision(wallRight))
			{
				playerTwo.getPosition(xPos, yPos);
				playerTwo.SetPosition(xPos - 1, yPos);
			}


			//Player Two Gun updating
			playerTwoGun.Update(fDeltaTime);//Actual update
			playerTwo.getPosition(xPos, yPos);//Using player one's pos because this gun needs to be on top of it
			UG::MoveSprite(playerTwoGun.getSpriteID(), xPos, yPos);


			//Bullets updating

			bl1.Update(fDeltaTime);
			bl2.Update(fDeltaTime);

			float x; float y; playerOne.getPosition(x, y);

			std::cout << "X: " << x << " Y: " << y << std::endl;

			//Escape rope. 
			//Legit though, for exiting the program just press your ESC button or click the x in the window.
			if (UG::IsKeyDown(UG::KEY_ESCAPE)) UG::Close(); 

			UG::ClearScreen();//Clears screen for next frame.

		} while (UG::Process());

		//--------------------------------------------------------------------------
		//--------------------------------------------------------------------------







		//		   Clean up


		//			  STOP DRAWING 
		UG::StopDrawingSprite(playerOne.getSpriteID());
		UG::StopDrawingSprite(playerOneGun.getSpriteID());
		UG::StopDrawingSprite(playerTwo.getSpriteID());
		UG::StopDrawingSprite(playerTwoGun.getSpriteID());

		UG::StopDrawingSprite(wallBot.getSpriteID());
		UG::StopDrawingSprite(wallLeft.getSpriteID());
		UG::StopDrawingSprite(wallRight.getSpriteID());
		UG::StopDrawingSprite(wallTop.getSpriteID());

		UG::StopDrawingSprite(pick1.getSpriteID());

		//			  DESTROY SPRITES
		UG::DestroySprite(playerOne.getSpriteID());
		UG::DestroySprite(playerOneGun.getSpriteID());
		UG::DestroySprite(playerTwo.getSpriteID());
		UG::DestroySprite(playerTwoGun.getSpriteID());

		UG::DestroySprite(wallBot.getSpriteID());
		UG::DestroySprite(wallLeft.getSpriteID());
		UG::DestroySprite(wallRight.getSpriteID());
		UG::DestroySprite(wallTop.getSpriteID());

		UG::DestroySprite(pick1.getSpriteID());

		//Tell the UG Framework to shutdown
		UG::Dispose();

	}
	return 0;
}

int randomNum(int seed)
{
	srand(seed*13.2);
	return rand() % 200 + 200;
}