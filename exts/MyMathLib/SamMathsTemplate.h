#ifndef __SAMMATHSTEMPLATE__H
#define __SAMMATHSTEMPLATE__H
#include <assert.h>
#include <math.h>
#include <iostream>
#define NDEBUG 

/*!
The Template Vector Struct
*/
template<int n,typename T>
struct Vector
{
public:
	Vector();
	T data[n];
};

template<class a, int n, typename T>
Vector<n, T> operator*(const a types, const Vector<n, T>& _vect);

template<class a, int n, typename T>
Vector<n, T> operator*(const Vector<n, T> &_vect, const a types);

template<int n, typename T>
Vector<n, T> operator+(const Vector<n, T>& a, const Vector<n, T>& b);

template<int n, typename T>
Vector<n, T> operator-(const Vector<n, T>& a, const Vector<n, T>& b);


//
//
/*!
The Template Matrix Struct
*/
template <int rows, int cols,typename T>
struct Matrix
{
public:
	Matrix();
	T data[rows][cols];
};

template<int rows,int cols,typename T>
Matrix<rows,cols,T> operator+(const Matrix<rows,cols,T> &_matrix);

template<int rows,int cols,typename T>
Matrix<rows,cols,T> operator-(const Matrix<rows,cols,T> &_matrix);

///DONE 
template<int rows,int cols,class integer,typename T>
Matrix<rows, cols, T> operator*(const integer &scalar,const Matrix<rows,cols,T>& matrix);

///FUNCTION OPERATION
template<int rows, int cols, class integer, typename T>
Matrix<rows, cols, T> operator*(const Matrix<rows, cols, T>& matrix, const integer &scalar);

///DONE!
//GENERAL TEMPLATE FUNCTION
template<int rows,int cols,int rows2,int cols2,typename T>
Matrix<rows, cols2, T> operator*(const Matrix<rows, cols, T> & matrix,const Matrix<rows2,cols2,T> & _matrix);

//EXPLICIT TEMPLATE FUNCTION
Matrix<4, 4, float> operator*(Matrix<4, 4, float> & matrix,Matrix<4, 4, float> & _matrix);

//Matrix operator*(const Matrix &_matrix);
//Matrix operator*(const double &constnumb);
//friend Matrix operator*(const double &scalar, const Matrix &_matrix);


typedef Vector<2,float> vec2;
typedef Vector<3,float> vec3;
typedef Vector<4,float> vec4;
typedef Matrix<3, 3,float> Mat33;
typedef Matrix<4, 4,float> Mat44;

//EXPLICIT declaration of different vectors

template <> struct Vector<2,float> {
	Vector();
	Vector(float x, float y);
	union 
	{
		float data[2];
		struct 
		{ 
			float x, y; 
		}; 
	}; 
	float lenght();
	void normalize();
	float scalarProduct(Vector<2, float> _vect);
	float operator[](int a);
};

template <> struct Vector<3,float> {
	Vector();
	Vector(float x, float y, float z);
	union 
	{ 
		float data[3]; 
		struct 
		{ 
			float x, y, z; 
		};
	};
	Vector<3,float> crossProduct(const Vector<3,float> other);
	float lenght();
	void normalize();
	float scalarProduct(Vector<3,float> _vect);
	float operator[](int a);
};

template <> struct Vector<4,float> { 
	Vector();
	Vector(float x, float y, float z);
	Vector(float x, float y, float z, float w);
	union 
	{ 
		float data[4]; 
		struct
		{
			float x, y, z, w;
		};
	}; 
	float lenght();
	void normalize();
	float scalarProduct(Vector<4, float> _vect);
	float operator[](int a);
};


//EXPLICIT DECLARATION OF MATRICES

template <> struct Matrix<3, 3, float>
{
	Matrix();
	//integer works as a changer to colom wise or row wise.
	//Matrix(vec3 r1, vec3 r2, vec3 r3,int rc);
	union
	{
		float data[3][3];
		struct
		{
			vec3 r1;
			vec3 r2;
			vec3 r3;
		};
	};
};

template <> struct Matrix<4, 4, float>
{
	Matrix();
	//integer works as a changer to colom wise or row wise.
	//Matrix(vec3 r1, vec3 r2, vec3 r3,int rc);
	union
	{
		float data[4][4];
		struct
		{
			vec4 r1;
			vec4 r2;
			vec4 r3;
			vec4 r4;
		};
	};
};


#endif // !__SAMMATHSTEMPLATE__H