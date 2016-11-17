#pragma once

#ifndef __SIMPLEMATHS_H__
#define __SIMPLEMATHS_H__

#include "mathLib.h"

class DLLEXPORT SimpleMaths
{
public:

	SimpleMaths();
	~SimpleMaths();

	//////////////////////////////////////////////////////////////////////////////////////////////
	//\
	//\		METHODS
	//\
	//////////////////////////////////////////////////////////////////////////////////////////////

	float calcDisplacement(float a_vel, float a_time);
	float calcPosition(float a_oldPosition, float a_vel, float a_elapsedTime);
	float calcAvgVelocity(float a_startPos, float a_endPos, float a_time);
	float calcAccelerationSeconds(float startVel, float finalVel, float elapsed_time);
	float calcAccelerationMinutes(float startVel, float finalVel, float elapsed_time);

	float convertToRadians(float a_degrees);
	float convertToDegrees(float a_radians);

	float add(float a_a, float a_b);
	float subtract(float a_a, float a_b);
	float multiply(float a_a, float a_b);
	float divide(float a_a, float a_b);
	float squareRoot(float a_a);
	float square(float a_a);
	float cube(float a_a);
	float powerOfN(float a_a, float a_n);


//	bool boundingCircles(Vector2 a_circle1, Vector2 a_circle2);

	//////////////////////////////////////////////////////////////////////////////////////////////
	//\
	//\		VALUES
	//\
	//////////////////////////////////////////////////////////////////////////////////////////////

	const double dPI = 3.1415926535897f;//Double rep of PI.
	const float fPI = 3.1415f;//float rep of PI.

	const float PI = 3.1415926535897f;//Standard rep of PI.
	const float HALFPI = 1.57079632679f; // Half of PI.
	const float DOUBLEPI = 6.28318530718f; // Double of PI.

protected:
private:

};

#endif //__SIMPLEMATHS_H__