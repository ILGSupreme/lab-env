#ifndef __SAMMATHVECTORS__H__
#define __SAMMATHVECTORS__H__
#include <assert.h>
#include <math.h>
#include <iostream>

struct Vector2f
{
	/**
	*	Vector2
	*	Creates a Vector with 0,0 values
	*/
	Vector2f();
	/**
	*	Vector2
	*	Creates a Vector with x, y values
	*/
	Vector2f(float x, float y);
	/**
	*	Vector2f
	*	two data values
	*/
	float data[2];
	/**
	*	ScalarProd
	*	@param return returns a float
	*/
	float scalarProd(const Vector2f &_vec);
	/**
	*	Normalise
	*	Normalises the vector
	*/
	void normalise();
	/**
	*	Normalize
	*	returns a normalised vector
	*/
	Vector2f getnormalize();
	/**
	*	Lenght
	*	returns the lenght of the vector
	*/
	float lenght();
	/**
	*	Overloaded [] operator
	*	returns the data
	*/
	float operator[] (int a);
	/**
	*	Overloaded [] operator
	*	returns the data
	*/

	void SetValues(float x, float y);

	const float operator[](int num) const;
	bool operator == (Vector2f& vec);
	friend Vector2f operator*(const float numb,const Vector2f & _vec);
	friend Vector2f operator*(const Vector2f & _vec, const float numb);
	friend Vector2f operator-(const Vector2f & _vec1,const Vector2f & _vec2);
	friend Vector2f operator+(const Vector2f & _vec1,const Vector2f & _vec2);
};

struct Vector3f
{
	/**
	*	Vector3
	*	Creates a Vector with 0,0,0 values
	*/
	Vector3f();
	/**
	*	Vector3
	*	Creates a Vector with x, y,z values
	*/
	Vector3f(float x, float y, float z);
	/**
	*	Vector3f
	*	three data values
	*/
	float data[3];
	/**
	*	ScalarProd
	*	@param return returns a float
	*/
	float scalarProd(const Vector3f & _vec);
	/**
	*	CrossProduct
	*	Cross Product of the vector
	*/
	Vector3f crossProduct(const Vector3f & other);
	/**
	*	Normalise
	*	Normalises the vector
	*/
	void normalize();
	/**
	*	Normalize
	*	returns a normalised vector
	*/
	Vector3f getnormalize();
	/**
	*	Lenght
	*	returns the lenght of the vector
	*/
	float lenght();
	/**
	*	Overloaded [] operator
	*	returns the data
	*/
	float& operator[] (int a);
	/**
	*	Overloaded [] operator
	*	returns the data
	*/

	void SetValues(float x, float y, float z);

	const float operator[](int a) const;
	bool operator == (Vector3f& vec);
	friend Vector3f operator*(const float numb, const Vector3f & _vec);
	friend Vector3f operator*(const Vector3f & _vec, const float numb);
	friend Vector3f operator-(const Vector3f & _vec1, const Vector3f & _vec2);
	friend Vector3f operator+(const Vector3f & _vec1, const Vector3f & _vec2);
};

struct Vector3d
{
	/**
	*	Vector3
	*	Creates a Vector with 0,0,0 values
	*/
	Vector3d();
	/**
	*	Vector3
	*	Creates a Vector with x, y,z values
	*/
	Vector3d(double x, double y, double z);
	/**
	*	Vector3
	*	three data values
	*/
	double data[3];
	/**
	*	ScalarProd
	*	@param return returns a float
	*/
	double scalarProd(const Vector3d & _vec);
	/**
	*	CrossProduct
	*	Cross Product of the vector
	*/
	Vector3d crossProduct(const Vector3d & other);
	/**
	*	Normalise
	*	Normalises the vector
	*/
	void normalize();
	/**
	*	Normalise
	*	Normalises the vector
	*/
	Vector3d getnormalize();
	/**
	*	Lenght
	*	returns the lenght of the vector
	*/
	double lenght();
	/**
	*	Overloaded [] operator
	*	returns the data
	*/
	double operator[] (int a);
	/**
	*	Overloaded [] operator
	*	returns the data
	*/

	void SetValues(double x, double y, double z);

	const double operator[](int a) const;
	bool operator == (Vector3d& vec);
	friend Vector3d operator*(const double numb, const Vector3d & _vec);
	friend Vector3d operator*(const Vector3d & _vec , const double numb);
	friend Vector3d operator-(const Vector3d & _vec1, const Vector3d & _vec2);
	friend Vector3d operator+(const Vector3d & _vec1, const Vector3d & _vec2);
};

struct Vector4f
{
	/**
	*	Vector4
	*	Creates a Vector with 0,0,0,0 values
	*/
	Vector4f();
	/**
	*	Vector4
	*	Creates a Vector with x,y,z values
	*/
	Vector4f(float x,float y,float z);
	/**
	*	Vector4
	*	Creates a Vector with x,y,z,w values
	*/
	Vector4f(float x, float y, float z,float w);
	/**
	*	Vector4
	*	four data values
	*/
	float data[4];
	/**
	*	ScalarProd
	*	@param return returns a float
	*/
	float scalarProd(const Vector4f & _vec);
	/**
	*	Normalise
	*	Normalises the vector
	*/
	void normalize();
	/**
	*	Normalise
	*	Normalises the vector
	*/
	Vector4f getnormalize();
	/**
	*	Lenght
	*	returns the lenght of the vector
	*/
	float lenght();
	/**
	*	Overloaded [] operator
	*	returns the data
	*/
	float& operator[] (int a);
	/**
	*	Overloaded [] operator
	*	returns the data
	*/

	void SetValues(float x, float y, float z , float w);

	const float operator[](int a) const;
	friend Vector4f operator*(const float numb, const Vector4f & _vec);
	friend Vector4f operator*(const Vector4f & _vec, const float numb);
	friend Vector4f operator-(const Vector4f & _vec1, const Vector4f & _vec2);
	friend Vector4f operator+(const Vector4f & _vec1, const Vector4f & _vec2);
};

struct Vector4d
{
	/**
	*	Vector4
	*	Creates a Vector with 0,0,0,0 values
	*/
	Vector4d();
	/**
	*	Vector4
	*	Creates a Vector with x,y,z values
	*/
	Vector4d(double x, double y, double z);
	/**
	*	Vector4
	*	Creates a Vector with x,y,z,w values
	*/
	Vector4d(double x, double y, double z, double w);
	/**
	*	Vector4
	*	four data values
	*/
	double data[4];
	/**
	*	ScalarProd
	*	@param return returns a float
	*/
	double scalarProd(const Vector4d & _vec);
	/**
	*	Normalise
	*	Normalises the vector
	*/
	void normalize();
	/**
	*	Normalise
	*	Normalises the vector
	*/
	Vector4d getnormalize();
	/**
	*	Lenght
	*	returns the lenght of the vector
	*/
	double lenght();
	/**
	*	Overloaded [] operator
	*	returns the data
	*/
	double operator[] (int a);
	/**
	*	Overloaded [] operator
	*	returns the data
	*/

	void SetValues(double x, double y, double z, double w);

	double operator[](const int a)const;
	friend Vector4d operator*(const double numb, const Vector4d & _vec);
	friend Vector4d operator*(const Vector4d & _vec, const double numb);
	friend Vector4d operator-(const Vector4d & _vec1, const Vector4d & _vec2);
	friend Vector4d operator+(const Vector4d & _vec1, const Vector4d & _vec2);
};

#endif // !__SAMMATHVECTORS__H__
