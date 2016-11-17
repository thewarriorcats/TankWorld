
#include "mathLib.h"

#ifndef __MATRIX4_H__
#define	__MATRIX4_H__


class DLLEXPORT Matrix4
{
public:
	//\===========================================================================================
	//\ Member Variables held in unnamed union for accessibility
	//\===========================================================================================
	union
	{
		struct
		{
			float			m[4][4];
		};
		struct
		{
			float           f[16];
		};
		struct
		{
			float		m_11, m_12, m_13, m_14;
			float		m_21, m_22, m_23, m_24;
			float		m_31, m_32, m_33, m_34;
			float		m_41, m_42, m_43, m_44;
		};
	};
	//\===========================================================================================
	//\ Constants
	//\===========================================================================================
	static const Matrix4 ZERO;
	static const Matrix4 ONE;
	static const Matrix4 IDENTITY;
	//\===========================================================================================
	//\ Constructors
	//\===========================================================================================
	Matrix4();
	explicit Matrix4(const float* a_mat);
	Matrix4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44);
	Matrix4(const Matrix3& a_m3);
	Matrix4(const Matrix4& a_m4);
	//\===========================================================================================
	//\ Casting operators
	//\===========================================================================================
	operator float*			();
	operator const float*	() const;
	//\===========================================================================================
	//\ Component Access Operators
	//\===========================================================================================
	float&					operator			() (int iRow, int iCol);
	float					operator			() (int iRow, int iCol) const;
	//\===========================================================================================
	//\ Component Access
	//\===========================================================================================
	Vector4&				x(void);
	Vector4&				y(void);
	Vector4&				z(void);
	Vector4&				t(void);
	const Vector4&			x(void) const;
	const Vector4&			y(void) const;
	const Vector4&			z(void) const;
	const Vector4&			t(void) const;
	//\===========================================================================================
	//\ Component Access/ Retreival As Vector4
	//\===========================================================================================
	void					SetX(const Vector4& a_v4);
	void					SetY(const Vector4& a_v4);
	void					SetZ(const Vector4& a_v4);
	void					SetT(const Vector4& a_v4);
	void					GetX(Vector4& a_v4) const;
	void					GetY(Vector4& a_v4) const;
	void					GetZ(Vector4& a_v4) const;
	void					GetT(Vector4& a_v4) const;
	//\===========================================================================================
	//\ Component Access/ Retreival As Vector3
	//\===========================================================================================
	void					SetX(const Vector3& a_v3);
	void					SetY(const Vector3& a_v3);
	void					SetZ(const Vector3& a_v3);
	void					SetT(const Vector3& a_v3);
	void					GetX(Vector3& a_v3) const;
	void					GetY(Vector3& a_v3) const;
	void					GetZ(Vector3& a_v3) const;
	void					GetT(Vector3& a_v3) const;
	//\===========================================================================================
	//\ Component Row/Column Access Operators
	//\===========================================================================================
	void					SetCol(int iCol, const Vector3& vCol);
	void					SetCol(int iCol, const Vector4& vCol);

	void					GetCol(int iCol, Vector3& vCol) const;
	void					GetCol(int iCol, Vector4& vCol) const;

	void					SetRow(int iRow, const Vector3& vRow);
	void					SetRow(int iRow, const Vector4& vRow);

	void					GetRow(int iRow, Vector3& vRow) const;
	void					GetRow(int iRow, Vector4& vRow) const;
	//\===========================================================================================
	//\ Equivalence operators
	//\===========================================================================================
	bool					operator ==			(const Matrix4& a_m4) const;
	bool					operator !=			(const Matrix4& a_m4) const;
	//\===========================================================================================
	//\ Neg operator
	//\===========================================================================================
	const Matrix4			operator -			() const;
	//\===========================================================================================
	//\ Operator overloads for Addition
	//\===========================================================================================
	const Matrix4			operator  +			(const Matrix4& a_m4) const;
	const Matrix4&			operator  +=		(const Matrix4& a_m4);
	//\===========================================================================================
	//\ Operator overloads for Subtraction
	//\===========================================================================================
	const Matrix4			operator  -			(const Matrix4& a_m4) const;
	const Matrix4&			operator  -=		(const Matrix4& a_m4);
	//\===========================================================================================
	//\ Operator overloads for multiplication
	//\===========================================================================================	
	const Matrix4			operator *			(float a_fScalar) const;
//	friend ML_API const Matrix4	operator *			(float a_fScalar, const Matrix4& a_m4);
	const Matrix4&			operator *=			(float a_fScalar);

	const Vector3			operator *			(const Vector3& a_v3) const;
	friend const Vector3	operator *			(const Vector3& a_v3, const Matrix4& a_m4);

	const Vector4			operator *			(const Vector4& a_v4) const;
//	friend ML_API const Vector4	operator *			(const Vector4& a_v4, const Matrix4& a_m4);

	const Matrix4			operator *			(const Matrix4& a_m4) const;
	const Matrix4&			operator *=			(const Matrix4& a_m4);
	//\===========================================================================================	
	//\ Transpose Matrix
	//\===========================================================================================
	void				Transpose();
	void				GetTranspose(Matrix4 &mat) const;
	//\===========================================================================================	
	// General matrix functions
	//\===========================================================================================
	void				Scale(const Vector3& vec);
	void				Scale(float k);
	//\===========================================================================================	
	// Orthonormalise
	//\===========================================================================================
	void  				OrthoNormalise();
	//\===========================================================================================	
	// Inverse Matrix Functions
	//\===========================================================================================
	float 				Determinant() const;
	float 				Determinant3() const;
	bool				Inverse();
	bool				GetInverse(Matrix4 &mat) const;
	//\===========================================================================================	
	// Matrix Rotation functions
	//\===========================================================================================
	void  				RotateX(float fAngle);
	void  				RotateY(float fAngle);
	void  				RotateZ(float fAngle);
	//\===========================================================================================	
	// General matrix functions
	//\===========================================================================================
	void				Identity();
	void				Zero();







};
#endif // ! __MATRIX4_H__


