#ifndef __Vector3_H__
#define __Vector3_H__

#include "mathLib.h"

//	\\	example	---- Represents opening of section.
//\\	example ---- Represents opening of Sub-section.
//\\				 Represents closing of  most recent sub-section.
//	\\/ example		 Represents closing of Section.

class DLLEXPORT Vector3
{
public:


	//	\\	CONSTRUCTORS
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	Vector3(const Vector3& a_v3);
	//	\\/ CONSTRUCTORS

	// \\ CASTING OPERATORS
	operator float*              ();
	operator const               float* () const;
	// \\/

	//	\\	DESTRUCTOR
	~Vector3();
	//	\\/DESTRUCTOR

	//	\\	FUNCTIONS

	//\\	Vector3 access
	void	Get(float& a_x, float& a_y, float& a_z) const;
	void    Get(Vector3& a_v3);
	void	Set(const float a_x, const float a_y, const float a_z);

	//\\
	//\\	Vector3 Returns
	Vector3 Scale(float a_scalar);

	Vector3 getUnit();

	Vector3 CrossProduct(Vector3& a_v3);
	Vector3 CrossProduct(Vector3& a_v3, Vector3& a_v3b);
	//\\

	//\\	Other returns

	float Distance(const Vector3& a_v3);
	float Distance(const Vector3& a_v3, const Vector3& a_v3b);

	float DistanceSquared(const Vector3& a_v3);
	float DistanceSquared(const Vector3& a_v3, const Vector3& a_v3b);

	float Dot(const Vector3& a_v3) const;
	float Dot(const Vector3& a_v3, const Vector3& a_v3b) const;

	void Truncate(float a_fMaxLength);

	void  Normalise();

	float Magnitude();
	float MagnitudeSquared();

	float Length();
	float LengthSquared();

	void Swap(Vector3& a_v3, Vector3& a_v31);

	void RotateX(float a_fAngle);
	void RotateY(float a_fAngle);
	void RotateZ(float a_fAngle);

	float Modulus();

	bool isNormal();
	bool isUnit();

	void  Zero();
	void  One();
	float Sum() const;
	float Min() const;
	float Max() const;
	//\\

	//	\\/FUNCTIONS

	//	\\	OVERLOADING

	//\\	Vector3 to Vector3
	void	    operator = (const Vector3& a_v3);
	Vector3		operator +		(const Vector3& a_v3) const;
	Vector3&	operator +=		(const Vector3& a_v3);

	Vector3		operator -		(const Vector3& a_v3) const;
	Vector3&	operator -=		(const Vector3& a_v3);

	Vector3		operator *		(const Vector3& a_v3) const;
	Vector3&	operator *=		(const Vector3& a_v3);

	Vector3		operator /		(const Vector3& a_v3) const;
	Vector3&	operator /=		(const Vector3& a_v3);
	//\\

	//\\	Vector3 to FLOAT
	Vector3		operator +		(const float& a_fl) const;
	Vector3&	operator +=		(const float& a_fl);

	Vector3		operator -		(const float& a_fl) const;
	Vector3&	operator -=		(const float& a_fl);

	Vector3		operator *		(const float& a_fl) const;
	Vector3&	operator *=		(const float& a_fl);

	Vector3		operator /		(const float& a_fl) const;
	Vector3&	operator /=		(const float& a_fl);
	//\\

	//\\	FLOAT to Vector3
	friend const Vector3 operator * (const float a_f, const Vector3 a_v3);
	friend const Vector3 operator / (const float a_f, const Vector3 a_v3);
	//\\

	//\\	BOOL
	bool		operator ==		(const Vector3& a_v3) const;
	bool		operator !=		(const Vector3& a_v3) const;
	//\\
		//	\\/OVERLOADING

//	\\	VARIABLES
	float x;
	float y;
	float z;
	float i[3];
	static const Vector3 ONE;
	static const Vector3 ZERO;
	static const Vector3 AXIS_X;
	static const Vector3 AXIS_Y;
	static const Vector3 AXIS_Z;
	float radius; //If being used for a circle, it'll have a radius.
				  //	\\/VARIABLES

};
#endif //__VECTOR3_H__