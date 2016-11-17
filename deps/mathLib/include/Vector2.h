#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "mathLib.h"

//	\\	example	---- Represents opening of section.
//\\	example ---- Represents opening of Sub-section.
//\\				 Represents closing of  most recent sub-section.
//	\\/ example		 Represents closing of Section.

class DLLEXPORT Vector2
{
public:


	//	\\	CONSTRUCTORS
	Vector2();
	Vector2(float a_x, float a_y);
	Vector2(const Vector2& a_v2);
	//	\\/ CONSTRUCTORS

	//	\\	DESTRUCTOR
	~Vector2();
	//	\\/DESTRUCTOR

	//	\\	FUNCTIONS

	//\\	Vector2 Access
	void	Get(float& a_x, float& a_y) const;
	void	Set(const float a_x, const float a_y);
	void	Set(Vector2& a_v2);
	//\\/

	//\\	Vector2 Returns
	Vector2 Scale(float a_scalar);
	Vector2 getUnit();
	Vector2 Distance(Vector2& a_v2);

	Vector2 Lerp(Vector2 a_A, Vector2 a_B, float a_T);

	Vector2 QuadBezier(Vector2 a_A, Vector2 a_B, Vector2 a_C, float a_T);
	Vector2 HermiteSpline(Vector2 point0, Vector2 point1, Vector2 tangent0, Vector2 tangent1, float a_t);
	Vector2 CardinalSpline(Vector2 point0, Vector2 point1, Vector2 point2, float a_a, float a_t);
	Vector2 CatmulRomSpline(Vector2 point0, Vector2 point1, Vector2 point2, float a_t);

	Vector2 getPerpendicular();
	//\\

	//\\	Other returns
	float Magnitude();
	float MagnitudeSquared();

	float Length();
	float LengthSquared();

	float DotProduct(Vector2& a_v2);
	float DotProduct(Vector2& a_v2, Vector2& a_v2b);

	float Modulus();

	bool  isUnit();
	bool  isNormal();

	void  Swap(Vector2& a_v2, Vector2& a_v21);

	void  Rotate(float a_fAngle);

	void  Normalise();
	//\\

	//	\\/FUNCTIONS

	//	\\	OVERLOADING

	//\\	VECTOR2 to VECTOR2
	const Vector2 operator -	() const;//Flips to negatives.

	Vector2		operator +		(const Vector2& a_v2) const;
	Vector2&	operator +=		(const Vector2& a_v2);

	Vector2		operator -		(const Vector2& a_v2) const;
	Vector2&	operator -=		(const Vector2& a_v2);

	Vector2		operator *		(const Vector2& a_v2) const;
	Vector2&	operator *=		(const Vector2& a_v2);

	Vector2		operator /		(const Vector2& a_v2) const;
	Vector2&	operator /=		(const Vector2& a_v2);
	//\\

	//\\	VECTOR2 to FLOAT
	Vector2		operator +		(const float& a_fl) const;
	Vector2&	operator +=		(const float& a_fl);
	
	Vector2		operator -		(const float& a_fl) const;
	Vector2&	operator -=		(const float& a_fl);

	Vector2		operator *		(const float& a_fl) const;
	Vector2&	operator *=		(const float& a_fl);

	Vector2		operator /		(const float& a_fl) const;
	Vector2&	operator /=		(const float& a_fl);
	//\\

	//\\	FLOAT to VECTOR2
	friend const Vector2 operator *	(const float a_f, const Vector2& a_v2);
	friend const Vector2 operator / (const float a_f, const Vector2& a_v2);
	//\\

	//\\	BOOL
	bool		operator ==		(const Vector2& a_v2) const;
	bool		operator !=		(const Vector2& a_v2) const;
	//\\

	//\\ Usefuls
	void		Zero();
	void		One();
	float		Sum()	const;
	float		Min()	const;
	float		Max()	const;
	//\\
	//	\\/OVERLOADING

	//CASTING OPERATORS

	operator float*								();
	operator const float*						() const;

	//	\\	VARIABLES
	float x;
	float y;
	float i[2];
	//	\\/VARIABLES

};

// VECTOR2 , VECTOR3, VECTOR 4
//Constructors
//Destructor
//static ZERO
//Vector(+, +=, -, -=, *, *=, / , /=, != , == ) Vector (Vector + Vector etc)
//Float(+, +=, -, -=, *, *=, / , /=) Vector (Float + Vector etc)
//Vector(+, +=, -, -=, *, *=, / , /=) Float (Vector + float etc)
//Dot Product
//Magnitude
//Scale
//Normalize
//Angle
//Distance
//Modulus
//Rotate


#endif //__VECTOR2_H__
