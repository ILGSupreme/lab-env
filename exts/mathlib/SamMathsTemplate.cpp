#include "SamMathsTemplate.h"

///--------------VECTOR OPERATIONS!----------------///

///Constructors

template<int n,typename T>
Vector<n,T>::Vector()
{
	for (int i = 0; i < n; i++)
	{
		this->data[i] = 0;
	}
}

Vector<2, float>::Vector()
{
	for (int i = 0; i < 2; i++)
	{
		this->data[i] = 0;
	}
}

Vector<2, float>::Vector(float x,float y)
{
	this->data[0] = x;
	this->data[1] = y;
}

Vector<3, float>::Vector()
{
	for (int i = 0; i < 3; i++)
	{
		this->data[i] = 0;
	}
}

Vector<3, float>::Vector(float x, float y, float z)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
}

Vector<4, float>::Vector()
{
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
	this->data[3] = 1;
}

Vector<4, float>::Vector(float x, float y, float z)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
	this->data[3] = 1;
}

Vector<4, float>::Vector(float x, float y, float z, float w)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
	this->data[3] = w;
}

//ADDITION OPERATOR

template<int n,typename T>
Vector<n,T> operator+(const Vector<n,T>& a, const Vector<n,T> &b)
{
	Vector<n,T> sum = Vector<n,T>();
	for (int i = 0; i < n; i++)
	{
		sum.data[i] = a.data[i] + b.data[i];
	}
	return sum;
}
//SUBTRACTION OPERATION
template<int n,typename T>
Vector<n,T> operator-(const Vector<n,T>& a,const Vector<n,T> &b)
{
	Vector<n,T> sub = Vector<n,T>();
	for (int i = 0; i < n; i++)
	{
		sub.data[i] = a.data[i] - b.data[i];
	}
	return sub;
}
//LENGHT OPERATION

float Vector<2, float>::lenght()
{
	float a = 0;
	for (int i = 0; i < 2; i++)
	{
		a += pow(this->data[i], 2);
	}
	a = sqrt(a);
	return a;
}
float Vector<3,float>::lenght()
{
	float a = 0;
	for (int i = 0; i < 3; i++)
	{
		a += pow(this->data[i], 2);
	}
	a = sqrt(a);
	return a;
}

float Vector<4, float>::lenght()
{
	float a = 0;
	for (int i = 0; i < 4; i++)
	{
		a += pow(this->data[i], 2);
	}
	a = sqrt(a);
	return a;
}
///NORMALIZE OPERATION

void Vector<2, float>::normalize()
{
	float _lgth = this->lenght();
	for (int i = 0; i < 2; i++)
	{
		this->data[i] = this->data[i] / _lgth;
	}
}

void Vector<3,float>::normalize()
{
	float _lgth = this->lenght();
	for (int i = 0; i < 3; i++)
	{
		this->data[i] = this->data[i] / _lgth;
	}
}

void Vector<4, float>::normalize()
{
	float _lgth = this->lenght();
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = this->data[i] / _lgth;
	}
}


///SCALAR OPERATION

float Vector<2, float>::scalarProduct(Vector<2, float> _vect)
{
	Vector<2, float> vc = Vector<2, float>(0, 0);
	float res = 0;
	for (int i = 0; i < 2; i++)
	{
		vc.data[i] = data[i] * _vect.data[i];
	}
	for (int i = 0; i < 2; i++)
	{
		res += vc.data[i];
	}
	return res;
}


//Scalar product
float Vector<3,float>::scalarProduct(Vector<3,float> _vect)
{
	Vector<3,float> vc = Vector<3,float>(0,0,0);
	float res = 0;
	for (int i = 0; i < 3; i++)
	{
		vc.data[i] = data[i] * _vect.data[i];
	}
	for (int i = 0; i < 3; i++)
	{
		res += vc.data[i];
	}
	return res;
}

float Vector<4, float>::scalarProduct(Vector<4, float> _vect)
{
	Vector<4, float> vc = Vector<4, float>(0, 0, 0);
	float res = 0;
	for (int i = 0; i < 4; i++)
	{
		vc.data[i] = data[i] * _vect.data[i];
	}
	for (int i = 0; i < 4; i++)
	{
		res += vc.data[i];
	}
	return res;
}

///CROSS PRODUCT OPERATIION

Vector<3,float> Vector<3,float>::crossProduct(const Vector<3,float> other)
{
	Vector<3,float> cross = Vector<3,float>(0,0,0);
	cross.data[0] = (this->data[1] * other.data[2]) - (this->data[2] * other.data[1]);
	cross.data[1] = (this->data[2] * other.data[0]) - (this->data[0] * other.data[2]);
	cross.data[2] = (this->data[0] * other.data[1]) - (this->data[1] * other.data[0]);

	return cross;
}

///MULTIPLICATION OPERATION
//
template<class a, int n,typename T>
Vector<n,T> operator*(const a types, const Vector<n,T>& _vect)
{
	Vector<n,T> mult = Vector<n,T>();
	for (int i = 0; i < n; i++)
	{
		mult.data[i] = _vect.data[i] * types;
	}
	return mult;
}

template<class a, int n,typename T>
Vector<n,T> operator*(const Vector<n,T> &_vect, const a types)
{
	Vector<n,T> mult = Vector<n,T>();
	for (int i = 0; i < n; i++)
	{
		mult.data[i] = _vect.data[i] * types;
	}
	return mult;
}


///[] OPERATOR
float Vector<2, float>::operator[](int a)
{
	return this->data[a];
}

float Vector<3, float>::operator[](int a)
{
	return this->data[a];
}

float Vector<4, float>::operator[](int a)
{
	return this->data[a];
}


/////-------------------MATRIX OPERATIONS!-----------------------------/////

/////CONSTRUCTORS!
template<int rows,int cols,typename T>
Matrix<rows, cols, T>::Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int c = 0; c < cols; c++)
		{
			this->data[i][c] = 0;
		}
	}
}

Matrix<3, 3, float>::Matrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int c = 0; c < 3; c++)
		{
			this->data[i][c] = 0;
		}
	}
}

Matrix<4, 4, float>::Matrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int c = 0; c < 4; c++)
		{
			this->data[i][c] = 0;
		}
	}
}


template<int rows, int cols, class integer, typename T>
Matrix<rows, cols, T> operator*(const integer &scalar, const Matrix<rows, cols, T>& matrix)
{
	Matrix<rows, cols, T> newmatrix = Matrix<rows, cols, T>();
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			double numb = matrix.data[r][c] * scalar;
			newmatrix.data[r][c] = numb;
		}
	}
	return newmatrix;
}

template<int rows, int cols, class integer, typename T>
Matrix<rows, cols, T> operator*(const Matrix<rows, cols, T>& matrix, const integer &scalar)
{
	Matrix<rows, cols, T> newmatrix = Matrix<rows, cols, T>();
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			double numb = matrix.data[r][c] * scalar;
			newmatrix.data[r][c] = numb;
		}
	}
	return newmatrix;
}

template<int rows,int cols,int rows2,int cols2,typename T>
Matrix<rows, cols2, T> operator*(const Matrix<rows, cols, T> & matrix, const Matrix<rows2, cols2, T> & _matrix)
{
	try
	{
		if (cols == rows2)
		{
			Matrix<rows, cols2, T> newmatrix = Matrix<rows, cols2, T>();
			for (int ro = 0; ro < rows; ro++)
			{
				for (int col_a = 0; col_a < cols2; col_a++)
				{
					int sum = 0;
					for (int c = 0; c < cols; c++)
					{
						sum += matrix.data[ro][c] * _matrix.data[c][col_a];
					}
					std::cout << sum << std::endl;
					newmatrix.data[ro][col_a] = sum;
				}
			}
			return newmatrix;
		}
		else
		{
			throw std::exception("Multiplication with different FirstMatrix[Col] and SecondMatrix[Row] cant be done");
		}
	}
	catch (std::exception e)
	{
		throw e.what();
	}
}



Matrix<4, 4,float> operator*(Matrix<4, 4, float>& matrix, Matrix<4, 4, float>& _matrix)
{
	///IMPLEMENTATION NEEDED!
	Matrix<4,4,float> test = Matrix<4, 4, float>();
	return test;
}

///EXPLICIT DECLARATION OF TEMPLATE FUNCTION AND STRUCTS, MOSTLY FOR FOR LINKER AND COMPILER

///----------------------VECTOR

template struct Vector<2,float>;
template struct Vector<3,float>;
template struct Vector<4,float>;

template Vector<2, float> operator*(const Vector<2, float> &_vect, const float types);
template Vector<2, float> operator*(const Vector<2, float> &_vect, const int types);
template Vector<2, float> operator*(const Vector<2, float> &_vect, const double types);

template Vector<2, float> operator+(const Vector<2, float> &_vect, const Vector<2, float> &_vect2);
template Vector<2, float> operator-(const Vector<2, float> &_vect, const Vector<2, float> &_vect2);

template Vector<2, float> operator*(const float types, const Vector<2, float> &_vect);
template Vector<2, float> operator*(const double types, const Vector<2, float> & _vect);
template Vector<2, float> operator*(const int types, const Vector<2, float> & _vect);

template Vector<3,float> operator*(const Vector<3,float> &_vect, const int types);
template Vector<3,float> operator*(const Vector<3,float> &_vect, const double types);
template Vector<3, float> operator*(const Vector<3, float> &_vect, const float types);

template Vector<3, float> operator*(const float types, const Vector<3, float> &_vect);
template Vector<3, float> operator*(const double types, const Vector<3, float> & _vect);
template Vector<3, float> operator*(const int types, const Vector<3, float> & _vect);

template Vector<3,float> operator+(const Vector<3,float> &_vect, const Vector<3,float> &_vect2);
template Vector<3,float> operator-(const Vector<3,float> &_vect, const Vector<3,float> &_vect2);

template Vector<4, float> operator*(const Vector<4, float> &_vect, const float types);
template Vector<4, float> operator*(const Vector<4, float> &_vect, const int types);
template Vector<4, float> operator*(const Vector<4, float> &_vect, const double types);

template Vector<4, float> operator*(const float types, const Vector<4, float> &_vect);
template Vector<4, float> operator*(const double types, const Vector<4, float> & _vect);
template Vector<4, float> operator*(const int types, const Vector<4, float> & _vect);

template Vector<4, float> operator+(const Vector<4, float> &_vect, const Vector<4, float> &_vect2);
template Vector<4, float> operator-(const Vector<4, float> &_vect, const Vector<4, float> &_vect2);

///------------------------MATRIX

template struct Matrix<3, 3, float>;
template struct Matrix<4, 4, float>;

template Matrix<3, 3, float> operator*(const Matrix<3, 3, float>&_matrix, const Matrix<3, 3, float> & matrix);
template Matrix<4, 4, float> operator*(const Matrix<4, 4, float>&_matrix, const Matrix<4, 4, float> & matrix);

template Matrix<3, 3, float> operator*(const float & scalar, const Matrix<3, 3, float>& matrix);
template Matrix<3, 3, float> operator*(const double & scalar, const Matrix<3, 3, float>& matrix);
template Matrix<3, 3, float> operator*(const int & scalar, const Matrix<3, 3, float>& matrix);

template Matrix<3, 3, float> operator*(const Matrix<3, 3, float>& matrix, const float & scalar);
template Matrix<3, 3, float> operator*(const Matrix<3, 3, float>& matrix, const double & scalar);
template Matrix<3, 3, float> operator*(const Matrix<3, 3, float>& matrix, const int & scalar);

//template Matrix<4, 4, float> operator*(const float & scalar, const Matrix<4, 4, float>& matrix);
template Matrix<4, 4, float> operator*(const double & scalar, const Matrix<4, 4, float>& matrix);
template Matrix<4, 4, float> operator*(const int & scalar, const Matrix<4, 4, float>& matrix);

template Matrix<4, 4, float> operator*(const Matrix<4, 4, float>& matrix, const float & scalar);
template Matrix<4, 4, float> operator*(const Matrix<4, 4, float>& matrix, const double & scalar);
template Matrix<4, 4, float> operator*(const Matrix<4, 4, float>& matrix, const int & scalar);