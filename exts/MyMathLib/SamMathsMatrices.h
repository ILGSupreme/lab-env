///!-------Sampad-3-----2014/09/22-----
///!--Matrix Library
#ifndef ___SAMMATHSMATRICES__H__
#define ___SAMMATHSMATRICES__H__
#include <assert.h>
#include <iostream>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES 
#endif // !_USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "SamMathsVectors.h"

struct Matrix3D
{
	/**
	*	Matrix 3x3 Constructor.
	* 	@Note : Row major matrix.
	*/
	Matrix3D();
	/**
	*	Matrix 3x3 Constructor.
	*	Constructs the 3x3 matrix with three vectors. 
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*/
	Matrix3D(Vector3f vec1, Vector3f vec2, Vector3f vec3);
	/**
	*	Matrix 3x3 Constructor.
	*	Constructs the 3x3 matrix with three vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*/
	Matrix3D(Vector3d vec1, Vector3d vec2, Vector3d vec3);

	double data[3][3];


	/**
	*	overloaded operator+
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix3D operator+(const Matrix3D & matrix, const Matrix3D &_matrix);


	/**
	*	overloaded operator-
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix3D operator-(const Matrix3D & matrix ,const Matrix3D &_matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3D operator*(const float &scalar, const Matrix3D & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3D operator*(const double &scalar, const Matrix3D & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3D operator*(const int &scalar, const Matrix3D & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3D operator*(const Matrix3D & matrix, const float &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3D operator*(const Matrix3D & matrix, const double &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3D operator*(const Matrix3D & matrix, const int &scalar);


	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector3f operator*(const Vector3f & vector,Matrix3D matrix);

	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector3f operator*(Matrix3D matrix, const Vector3f & vector);


	/**
	*	overloaded operator*
	*	@param matrix
	*	@param -matrix
	*/
	friend Matrix3D operator*(const Matrix3D & matrix, const Matrix3D & _matrix);


	/**
	*	overloaded operator[]
	*	@param return returns a pointer to a specific data.
	*/
	double* operator[](int numb);

	/**
	*	Inverts the matrix if it can be inverted.
	*	@param return	returns double pointer
	*/
	void Invert();

	/**
	*	returns the inverted matrix of this one.
	*	@param return void
	*/
	Matrix3D GetInverse();
	/**
	*	Transposes the matrix
	*	@param return	returns void
	*/
	void Transpose();
	/**
	*	Returns a transposed matrix.
	*	@param return returns A Matrix3D
	*/
	Matrix3D GetTranspose();
};

struct Matrix3F
{
	/**
	*	Matrix 3x3 Constructor.
	* 	@Note : Row major matrix.
	*/
	Matrix3F();
	/**
	*	Matrix 3x3 Constructor.
	*	Constructs the 3x3 matrix with three vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*/
	Matrix3F(Vector3f vec1, Vector3f vec2, Vector3f vec3);
	/**
	*	Matrix 3x3 Constructor.
	*	Constructs the 3x3 matrix with three vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*/
	Matrix3F(Vector3d vec1, Vector3d vec2, Vector3d vec3);

	float data[3][3];


	/**
	*	overloaded operator+
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix3F operator+(const Matrix3F & matrix, const Matrix3F &_matrix);


	/**
	*	overloaded operator-
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix3F operator-(const Matrix3F & matrix, const Matrix3F &_matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3F operator*(const float &scalar, const Matrix3F & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3F operator*(const double &scalar, const Matrix3F & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3F operator*(const int &scalar, const Matrix3F & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3F operator*(const Matrix3F & matrix, const float &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3F operator*(const Matrix3F & matrix, const double &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix3F operator*(const Matrix3F & matrix, const int &scalar);


	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector3f operator*(const Vector3f & vector, Matrix3F matrix);

	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector3f operator*(Matrix3F matrix, const Vector3f & vector);


	/**
	*	overloaded operator*
	*	@param matrix
	*	@param -matrix
	*/
	friend Matrix3F operator*(const Matrix3F & matrix, const Matrix3F & _matrix);


	/**
	*	overloaded operator[]
	*	@param return returns a pointer to a specific data.
	*/
	float* operator[](int numb);

	/**
	*	Inverts the matrix if it can be inverted.
	*	@param return	returns double pointer
	*/
	void Invert();

	/**
	*	returns the inverted matrix of this one.
	*	@param return void
	*/
	Matrix3F GetInverse();
	/**
	*	Transposes the matrix
	*	@param return	returns void
	*/
	void Transpose();
	/**
	*	Returns a transposed matrix.
	*	@param return a Matrix3D
	*/
	Matrix3F GetTranspose();
	/*
	*	cast operator
	*/
	operator float*();
};



struct Matrix4D
{
	Matrix4D(const Matrix4D &other);
	/**
	*	Matrix 4x4 Constructor.
	* 	@Note : Row major matrix.
	*/
	Matrix4D();
	/**
	*	Matrix 4x4 Constructor.
	*	Constructs the 3x3 matrix with four vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*	@param vec4
	*/
	Matrix4D(Vector4f vec1, Vector4f vec2, Vector4f vec3, Vector4f vec4);
	/**
	*	Matrix 4x4 Constructor.
	*	Constructs the 4x4 matrix with four vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*	@param vec4
	*/
	Matrix4D(Vector4d vec1, Vector4d vec2, Vector4d vec3, Vector4d vec4);


	Matrix4D& operator=(const Matrix4D & other);

	double data[4][4];
	/**
	*	_data.
	*	This data is only for converting the data into floats so i can use it for opengl functions.
	*/
	float _data[4][4];
	/**
	*	overloaded operator+
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix4D operator+(const Matrix4D & matrix, const Matrix4D &_matrix);

	/**
	*	overloaded operator-
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix4D operator-(const Matrix4D & matrix, const Matrix4D &_matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4D operator*(const float &scalar, const Matrix4D & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4D operator*(const double &scalar, const Matrix4D & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4D operator*(const int &scalar, const Matrix4D & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4D operator*(const Matrix4D & matrix, const float &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4D operator*(const Matrix4D & matrix, const double &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4D operator*(const Matrix4D & matrix, const int &scalar);

	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector4f operator*(const Vector4f & vector, Matrix4D matrix);

	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector4f operator*(Matrix4D matrix, const Vector4f & vector);

	/**
	*	overloaded operator*
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix4D operator*(const Matrix4D & matrix, const Matrix4D & _matrix);

	/**
	*	overloaded operator[]
	*	@param numb
	*	@param	return	returns a pointer to a specific data.
	*/
	double* operator[](int numb);


	/**
	*	overloaded operator float()
	*	@param return	returns a float pointer
	*/
	operator float*();


	/**
	*	overloaded operator float()
	*	@param return	returns a const float pointer
	*/
	operator const float*() const;


	/**
	*	Inverts the matrix if it can be inverted.
	*	@param return	returns void
	*/
	void Invert();

	/**
	*	returns the inverted matrix of this one.
	*	@param return	returns Matrix4D
	*/
	Matrix4D GetInverse();

	/**
	* Transposes the matrix
	*	@param return returns void
	*/
	void Transpose();

	/**
	* Returns a transposed matrix.
	*	@param return	returns Matrix4D
	*/
	Matrix4D GetTranspose();

};

struct Matrix4F
{
	Matrix4F(const Matrix4F&other);
	/**
	*	Matrix 4x4 Constructor.
	* 	@Note : Row major matrix.
	*/
	Matrix4F();
	/**
	*	Matrix 4x4 Constructor.
	*	Constructs the 3x3 matrix with four vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*	@param vec4
	*/
	Matrix4F(Vector4f vec1, Vector4f vec2, Vector4f vec3, Vector4f vec4);
	/**
	*	Matrix 4x4 Constructor.
	*	Constructs the 4x4 matrix with four vectors.
	*	Note : this is Row major.
	*	@param vec1
	*	@param vec2
	*	@param vec3
	*	@param vec4
	*/
	Matrix4F(Vector4d vec1, Vector4d vec2, Vector4d vec3, Vector4d vec4);


	Matrix4F& operator=(const Matrix4F & other);

	float data[4][4];
	/**
	*	_data.
	*	This data is only for converting the data into floats so i can use it for opengl functions.
	*/
	/**
	*	overloaded operator+
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix4F operator+(const Matrix4F & matrix, const Matrix4F &_matrix);

	/**
	*	overloaded operator-
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix4F operator-(const Matrix4F & matrix, const Matrix4F &_matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4F operator*(const float &scalar, const Matrix4F & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4F operator*(const double &scalar, const Matrix4F & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4F operator*(const int &scalar, const Matrix4F & matrix);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4F operator*(const Matrix4F & matrix, const float &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4F operator*(const Matrix4F & matrix, const double &scalar);

	/**
	*	overloaded operator*
	*	@param scalar
	*	@param matrix
	*/
	friend Matrix4F operator*(const Matrix4F & matrix, const int &scalar);

	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector4f operator*(const Vector4f & vector, Matrix4F matrix);

	/**
	*	overloaded operator*
	*	@param vector
	*	@param matrix
	*/
	friend Vector4f operator*(Matrix4D matrix, const Vector4f & vector);

	/**
	*	overloaded operator*
	*	@param matrix
	*	@param _matrix
	*/
	friend Matrix4F operator*(const Matrix4F & matrix, const Matrix4F & _matrix);

	/**
	*	overloaded operator[]
	*	@param numb
	*	@param	return	returns a pointer to a specific data.
	*/
	float* operator[](int numb);


	/**
	*	overloaded operator float()
	*	@param return	returns a float pointer
	*/
	operator float*();


	/**
	*	overloaded operator float()
	*	@param return	returns a const float pointer
	*/
	operator const float*() const;


	/**
	*	Inverts the matrix if it can be inverted.
	*	@param return	returns void
	*/
	void Invert();

	/**
	*	returns the inverted matrix of this one.
	*	@param return	returns Matrix4D
	*/
	Matrix4F GetInverse();

	/**
	* Transposes the matrix
	*	@param return returns void
	*/
	void Transpose();

	/**
	* Returns a transposed matrix.
	*	@param return	returns Matrix4D
	*/
	Matrix4F GetTranspose();

	Matrix3F GetMatrix3F();

};



namespace Mat3
{
	/**
	*	Identity Matrix
	*	@param return returns a Identity Matrix
	*/
	Matrix3D InitIdentityMat3();


	/**
	*	Rotation Matrix
	*	@param angle	angle is in radians
	*	@param return returns a Rotation Matrix
	*/
	Matrix3D InitRotationMat3X(float angle);


	/**
	*	Rotation Matrix
	*	@param angle	angle is in radians
	*	@param return returns a Rotation Matrix
	*/
	Matrix3D InitRotationMat3Y(float angle);


	/**
	*	Rotation Matrix
	*	@param angle	angle is in radians
	*	@param return	returns a Rotation Matrix
	*/
	Matrix3D InitRotationMat3Z(float angle);


	/**
	*	Scale Matrix
	*	@param vec	the scale vector
	*	@param return returns a Matrix
	*/
	Matrix3D InitScalingMat3(Vector3f vec);


	/**
	*	Translation Matrix
	*	@param vec	the translate vector
	*	@param return returns a Matrix
	*/
	Matrix3D InitTranslateMat3(Vector3f vec);



	/**
	*	Arbitary Rotation Matrix
	*	@param vec	the translate vector
	*	@param float	the angle of rotation
	*	@param return returns a Matrix
	*/
	Matrix3D InitRotationArbM3(Vector3f vec, float angle);

	/// MATRIX3 FLOAT

	/**
	*	Identity Matrix
	*	@param return returns a Identity Matrix
	*/
	Matrix3F InitIdentityMat3F();


	/**
	*	Rotation Matrix
	*	@param angle	angle is in radians
	*	@param return returns a Rotation Matrix
	*/
	Matrix3F InitRotationMat3XF(float angle);


	/**
	*	Rotation Matrix
	*	@param angle	angle is in radians
	*	@param return returns a Rotation Matrix
	*/
	Matrix3F InitRotationMat3YF(float angle);


	/**
	*	Rotation Matrix
	*	@param angle	angle is in radians
	*	@param return	returns a Rotation Matrix
	*/
	Matrix3F InitRotationMat3ZF(float angle);


	/**
	*	Scale Matrix
	*	@param vec	the scale vector
	*	@param return returns a Matrix
	*/
	Matrix3F InitScalingMat3F(Vector3f vec);


	/**
	*	Translation Matrix
	*	@param vec	the translate vector
	*	@param return returns a Matrix
	*/
	Matrix3F InitTranslateMat3F(Vector3f vec);



	/**
	*	Arbitary Rotation Matrix
	*	@param vec	the translate vector
	*	@param float	the angle of rotation
	*	@param return returns a Matrix
	*/
	Matrix3F InitRotationArbM3F(Vector3f vec, float angle);

}

namespace Mat4
{
	/**
	*	Identity Matrix
	*	@return		returns a Identity Matrix
	*/
	Matrix4D InitIdentityMat4D();

	/**
	*	Rotation Matrix
	*	@param	return		returns a Rotation Matrix according to X axis
	*/
	Matrix4D InitRotationMat4XD(float angle);

	/**
	*	Rotation Matrix
	*	@param	return		returns a Rotation Matrix according to Y axis
	*/
	Matrix4D InitRotationMat4YD(float angle);

	/**
	*	Rotation Matrix
	*	@param	return		returns a Rotation Matrix according to Z axis
	*/
	Matrix4D InitRotationMat4ZD(float angle);

	/**
	*	Arbitary Rotation Matrix
	*	@return	return		returns a Arbitary Rotation Matrix
	*/
	Matrix4D InitRotationArbM4D(Vector3f vec, float angle);

	/**
	*	Translation Matrix
	*	@return	returns a Translation Matrix
	*/
	Matrix4D InitTranslationMat4D(const Vector3f& vec);

	/**
	*	Scale Matrix
	*	@return	returns a Scale Matrix
	*/
	Matrix4D InitScalingMat4D(const Vector3f &vec);

	/**
	*	Frustrum Matrix
	*	Creates the frustrum perspective matrix
	*	@param  left
	*	@param	right
	*	@param	bottom
	*	@param	top
	*	@param	near
	*	@param	far
	*	returns a Frustrum perspective matrix
	*/
	Matrix4D InitFrustrumMat4D(float left, float right, float bottom, float top, float near, float far);

	/**
	*	Perspective Matrix
	*	Creates the perspective matrix
	*	@param fov	Field of View
	*	@param aspect Aspect ratio of window
	*	@param n	near value of camera
	*	@param far far value of camera
	*	returns a perspective matrix
	*/
	Matrix4D InitPerspectiveMat4D(float fov, float aspect, float n, float f);

	/**
	*	Orthogonal Perspecitve matrix
	*	Creates the Orthogonal Perspecitve matrix
	*	@param  left		left value
	*	@param	right		right value
	*	@param	bottom		bottom value
	*	@param	top			top value
	*	@param near			near value
	*	@param far			far value
	*	returns a  Orthogonal Perspecitve matrix
	*/
	Matrix4D InitOrthoPerspective4D(float left, float right, float bottom, float top, float near, float far);

	/**
	*	LookAt Matrix
	*	The lookAt matrix constructs a view matrix that simulates a camera
	*	@param	vec_eye		the cameras position
	*	@param	center		the position of the object you want the camera facing at
	*	@param	up			the up vector of the camera
	*	@param return		returns the "camera matrix" Matrix
	*/
	Matrix4D InitLookAtMat4D(const Vector3f& vec_eye, const Vector3f& center, const Vector3f& up);

	/**
	*	Multiplication Function for Matrix
	*	this free function is for speed.
	*/
	void M4Prod(const Matrix4D & matrix, const Matrix4D & _matrix, Matrix4D & resmatrix);



	/**
	*	Identity Matrix
	*	@return		returns a Identity Matrix
	*/
	Matrix4F InitIdentityMat4F();

	/**
	*	Rotation Matrix
	*	@param	return		returns a Rotation Matrix according to X axis
	*/
	Matrix4F InitRotationMat4XF(float angle);

	/**
	*	Rotation Matrix
	*	@param	return		returns a Rotation Matrix according to Y axis
	*/
	Matrix4F InitRotationMat4YF(float angle);

	/**
	*	Rotation Matrix
	*	@param	return		returns a Rotation Matrix according to Z axis
	*/
	Matrix4F InitRotationMat4ZF(float angle);

	/**
	*	Arbitary Rotation Matrix
	*	@return	return		returns a Arbitary Rotation Matrix
	*/
	Matrix4F InitRotationArbM4F(Vector3f vec, float angle);

	/**
	*	Translation Matrix
	*	@return	returns a Translation Matrix
	*/
	Matrix4F InitTranslationMat4F(const Vector3f& vec);

	/**
	*	Scale Matrix
	*	@return	returns a Scale Matrix
	*/
	Matrix4F InitScalingMat4F(const Vector3f &vec);

	/**
	*	Frustrum Matrix
	*	Creates the frustrum perspective matrix
	*	@param  left
	*	@param	right
	*	@param	bottom
	*	@param	top
	*	@param	near
	*	@param	far
	*	returns a Frustrum perspective matrix
	*/
	Matrix4F InitFrustrumMat4F(float left, float right, float bottom, float top, float near, float far);

	/**
	*	Perspective Matrix
	*	Creates the perspective matrix
	*	@param fov	Field of View
	*	@param aspect Aspect ratio of window
	*	@param n	near value of camera
	*	@param far far value of camera
	*	returns a perspective matrix
	*/
	Matrix4F InitPerspectiveMat4F(float fov, float aspect, float n, float f);

	/**
	*	Orthogonal Perspecitve matrix
	*	Creates the Orthogonal Perspecitve matrix
	*	@param  left		left value
	*	@param	right		right value
	*	@param	bottom		bottom value
	*	@param	top			top value
	*	@param near			near value
	*	@param far			far value
	*	returns a  Orthogonal Perspecitve matrix
	*/
	Matrix4F InitOrthoPerspective4F(float left, float right, float bottom, float top, float near, float far);

	/**
	*	LookAt Matrix
	*	The lookAt matrix constructs a view matrix that simulates a camera
	*	@param	vec_eye		the cameras position
	*	@param	center		the position of the object you want the camera facing at
	*	@param	up			the up vector of the camera
	*	@param return		returns the "camera matrix" Matrix
	*/
	Matrix4F InitLookAtMat4F(const Vector3f& vec_eye, const Vector3f& center, const Vector3f& up);
}

namespace SMUtility
{
	/**
	* Changes degrees to radians
	* @param angle		angle in degrees
	* @param return		returns float
	*/
	float DegreesToRadians(float angle);
	/**
	* Changes radians to degrees
	*	@param rad		rad in radians
	*	@param return	returns float
	*/
	float RadiansToDegrees(float rad);
}


#endif // !___SAMMATHSMATRICES__H__
