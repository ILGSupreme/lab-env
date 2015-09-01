#include "SamMathsVectors.h"
///VECTOR2
Vector2f::Vector2f()
{
	data[0] = 0;
	data[1] = 0;
}

Vector2f::Vector2f(float x, float y)
{
	data[0] = x;
	data[1] = y;
}

float Vector2f::lenght()
{
	return sqrt(pow(data[0], 2) + pow(data[1], 2));
}

void Vector2f::normalise()
{
	data[0] = data[0] / this->lenght();
	data[1] = data[1] / this->lenght();
}

Vector2f Vector2f::getnormalize()
{
	return Vector2f(data[0] / this->lenght(), data[1] / this->lenght());
}

float Vector2f::scalarProd(const Vector2f &_vec)
{
	return (_vec[0] * data[0] + _vec[1] * data[1]);
}

Vector2f operator+(const Vector2f & _vec1, const Vector2f & _vec2)
{
	Vector2f newvec = Vector2f();
	newvec.data[0] = _vec1[0] + _vec2[0];
	newvec.data[1] = _vec1[1] + _vec2[1];
	return newvec;
}

Vector2f operator-(const Vector2f & _vec1, const Vector2f & _vec2)
{
	Vector2f newvec = Vector2f();
	newvec.data[0] = _vec1[0] - _vec2[0];
	newvec.data[1] = _vec1[1] - _vec2[1];
	return newvec;
}

Vector2f operator*(const float numb,const Vector2f& _vec)
{
	Vector2f newvec = Vector2f();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	return newvec;
}
Vector2f operator*(const Vector2f& _vec, const float numb)
{
	Vector2f newvec = Vector2f();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	return newvec;
}

float Vector2f::operator[](int num)
{
	return this->data[num];
}

const float Vector2f::operator[](int num) const
{
	return this->data[num];
}

bool Vector2f::operator==(Vector2f& data)
{
	if (this->data[0] == data[0] && this->data[1] == data[1])
	{
		return true;
	}
	return false;
}


void Vector2f::SetValues(float x, float y)
{
	this->data[0] = x;
	this->data[1] = y;
}

///VECTOR3
Vector3f::Vector3f()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}

Vector3f::Vector3f(float x,float y,float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

float Vector3f::lenght()
{
	return sqrt(pow(data[0], 2) + pow(data[1], 2) + pow(data[2], 2));
}

void Vector3f::normalize()
{
	data[0] = data[0] / this->lenght();
	data[1] = data[1] / this->lenght();
	data[2] = data[2] / this->lenght();
}

Vector3f Vector3f::getnormalize()
{
	return Vector3f(data[0] / this->lenght(), data[1] / this->lenght(), data[2] / this->lenght());
}

float Vector3f::scalarProd(const Vector3f &_vec)
{
	return (_vec[0] * data[0] + _vec[1] * data[1] + _vec[2] * data[2]);
}

Vector3f Vector3f::crossProduct(const Vector3f & other)
{
	Vector3f cross = Vector3f();
	cross.data[0] = (data[1] * other[2]) - (data[2] * other[1]);
	cross.data[1] = (data[2] * other[0]) - (data[0] * other[2]);
	cross.data[2] = (data[0] * other[1]) - (data[1] * other[0]);
	return cross;
}

Vector3f operator+(const Vector3f & _vec1, const Vector3f & _vec2)
{
	Vector3f newvec = Vector3f();
	newvec.data[0] = _vec1[0] + _vec2[0];
	newvec.data[1] = _vec1[1] + _vec2[1];
	newvec.data[2] = _vec1[2] + _vec2[2];
	return newvec;
}

Vector3f operator-(const Vector3f & _vec1, const Vector3f & _vec2)
{
	Vector3f newvec = Vector3f();
	newvec.data[0] = _vec1[0] - _vec2[0];
	newvec.data[1] = _vec1[1] - _vec2[1];
	newvec.data[2] = _vec1[2] - _vec2[2];
	return newvec;
}

Vector3f operator*(const float numb, const Vector3f& _vec)
{
	Vector3f newvec = Vector3f();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	return newvec;
}
Vector3f operator*(const Vector3f& _vec, const float numb)
{
	Vector3f newvec = Vector3f();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	return newvec;
}

float& Vector3f::operator[](const int num)
{
	return this->data[num];
}

const float Vector3f::operator[](const int num)const
{
	return this->data[num];
}

bool Vector3f::operator==(Vector3f& data)
{
	if (this->data[0] == data[0] && this->data[1] == data[1] && this->data[2] == data[2])
	{
		return true;
	}
	return false;
}

void Vector3f::SetValues(float x, float y, float z)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
}

///VECTOR DOUBLE

Vector3d::Vector3d()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}

Vector3d::Vector3d(double x, double y, double z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

double Vector3d::lenght()
{
	return sqrt(pow(data[0], 2) + pow(data[1], 2) + pow(data[2], 2));
}

void Vector3d::normalize()
{
	data[0] = data[0] / this->lenght();
	data[1] = data[1] / this->lenght();
	data[2] = data[2] / this->lenght();
}

Vector3d Vector3d::getnormalize()
{
	return Vector3d(data[0] / this->lenght(), data[1] / this->lenght(), data[2] / this->lenght());
}

double Vector3d::scalarProd(const Vector3d &_vec)
{
	return (_vec[0]*data[0] + _vec[1] * data[1] + _vec[2] * data[2]);
}

Vector3d Vector3d::crossProduct(const Vector3d & other)
{
	Vector3d cross = Vector3d();
	cross.data[0] = (data[1] * other[2]) - (data[2] * other[1]);
	cross.data[1] = (data[2] * other[0]) - (data[0] * other[2]);
	cross.data[2] = (data[0] * other[1]) - (data[1] * other[0]);
	return cross;
}

Vector3d operator+(const Vector3d & _vec1, const Vector3d & _vec2)
{
	Vector3d newvec = Vector3d();
	newvec.data[0] = _vec1[0] + _vec2[0];
	newvec.data[1] = _vec1[1] + _vec2[1];
	newvec.data[2] = _vec1[2] + _vec2[2];
	return newvec;
}

Vector3d operator-(const Vector3d & _vec1, const Vector3d & _vec2)
{
	Vector3d newvec = Vector3d();
	newvec.data[0] = _vec1[0] - _vec2[0];
	newvec.data[1] = _vec1[1] - _vec2[1];
	newvec.data[2] = _vec1[2] - _vec2[2];
	return newvec;
}

Vector3d operator*(const double numb, const Vector3d& _vec)
{
	Vector3d newvec = Vector3d();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	return newvec;
}
Vector3d operator*(const Vector3d& _vec, const double numb)
{
	Vector3d newvec = Vector3d();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	return newvec;
}

double Vector3d::operator[](int num)
{
	return this->data[num];
}

const double Vector3d::operator[](const int num) const
{
	return this->data[num];
}

bool Vector3d::operator==(Vector3d& data)
{
	if (this->data[0] == data[0] && this->data[1] == data[1] && this->data[2] == data[2])
	{
		return true;
	}
	return false;
}


void Vector3d::SetValues(double x, double y, double z)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
}

///VECTOR4 float

Vector4f::Vector4f()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
}

Vector4f::Vector4f(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = 1;
}

Vector4f::Vector4f(float x, float y, float z,float w)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

float Vector4f::lenght()
{
	return sqrt(pow(data[0], 2) + pow(data[1], 2) + pow(data[2], 2) + pow(data[3],2));
}

void Vector4f::normalize()
{
	data[0] = data[0] / this->lenght();
	data[1] = data[1] / this->lenght();
	data[2] = data[2] / this->lenght();
	data[3] = data[3] / this->lenght();
}

Vector4f Vector4f::getnormalize()
{
	return Vector4f(data[0] / this->lenght(), data[1] / this->lenght(), data[2] / this->lenght(), data[3] / this->lenght());
}

float Vector4f::scalarProd(const Vector4f &_vec)
{
	return (_vec[0]*data[0] + _vec[1] * data[1] + _vec[2] * data[2] + _vec[3] * data[3]);
}

Vector4f operator+(const Vector4f & _vec1, const Vector4f & _vec2)
{
	Vector4f newvec = Vector4f();
	newvec.data[0] = _vec1[0] + _vec2[0];
	newvec.data[1] = _vec1[1] + _vec2[1];
	newvec.data[2] = _vec1[2] + _vec2[2];
	newvec.data[3] = _vec1[3] + _vec2[3];
	return newvec;
}

Vector4f operator-(const Vector4f & _vec1, const Vector4f & _vec2)
{
	Vector4f newvec = Vector4f();
	newvec.data[0] = _vec1[0] - _vec2[0];
	newvec.data[1] = _vec1[1] - _vec2[1];
	newvec.data[2] = _vec1[2] - _vec2[2];
	newvec.data[3] = _vec1[3] - _vec2[3];
	return newvec;
}

Vector4f operator*(const float numb, const Vector4f& _vec)
{
	Vector4f newvec = Vector4f();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	newvec.data[3] = _vec[3] * numb;
	return newvec;
}
Vector4f operator*(const Vector4f& _vec, const float numb)
{
	Vector4f newvec = Vector4f();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	newvec.data[3] = _vec[3] * numb;
	return newvec;
}


float& Vector4f::operator[](int num)
{
	return this->data[num];
}

const float Vector4f::operator[](const int num)const
{
	return this->data[num];
}

void Vector4f::SetValues(float x, float y, float z , float w)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
	this->data[3] = w;
}

//VECTOR 4 Double

Vector4d::Vector4d()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
}

Vector4d::Vector4d(double x, double y, double z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = 1;
}

Vector4d::Vector4d(double x, double y, double z, double w)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

double Vector4d::lenght()
{
	return sqrt(pow(data[0], 2) + pow(data[1], 2) + pow(data[2], 2) + pow(data[3], 2));
}

void Vector4d::normalize()
{
	data[0] = data[0] / this->lenght();
	data[1] = data[1] / this->lenght();
	data[2] = data[2] / this->lenght();
	data[3] = data[3] / this->lenght();
}

Vector4d Vector4d::getnormalize()
{
	return Vector4d(data[0] / this->lenght(), data[1] / this->lenght(), data[2] / this->lenght(), data[3] / this->lenght());
}

double Vector4d::scalarProd(const Vector4d &_vec)
{
	return (_vec[0] * data[0] + _vec[1] * data[1] + _vec[2] * data[2] + _vec[3] * data[3]);
}

Vector4d operator+(const Vector4d & _vec1, const Vector4d & _vec2)
{
	Vector4d newvec = Vector4d();
	newvec.data[0] = _vec1[0] + _vec2[0];
	newvec.data[1] = _vec1[1] + _vec2[1];
	newvec.data[2] = _vec1[2] + _vec2[2];
	newvec.data[3] = _vec1[3] + _vec2[3];
	return newvec;
}

Vector4d operator-(const Vector4d & _vec1, const Vector4d & _vec2)
{
	Vector4d newvec = Vector4d();
	newvec.data[0] = _vec1[0] - _vec2[0];
	newvec.data[1] = _vec1[1] - _vec2[1];
	newvec.data[2] = _vec1[2] - _vec2[2];
	newvec.data[3] = _vec1[3] - _vec2[3];
	return newvec;
}

Vector4d operator*(const double numb, const Vector4d& _vec)
{
	Vector4d newvec = Vector4d();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	newvec.data[3] = _vec[3] * numb;
	return newvec;
}
Vector4d operator*(const Vector4d& _vec, const double numb)
{
	Vector4d newvec = Vector4d();
	newvec.data[0] = _vec[0] * numb;
	newvec.data[1] = _vec[1] * numb;
	newvec.data[2] = _vec[2] * numb;
	newvec.data[3] = _vec[3] * numb;
	return newvec;
}


double Vector4d::operator[](const int num) const
{
	return this->data[num];
}

double Vector4d::operator[](int num)
{
	return this->data[num];
}

void Vector4d::SetValues(double x, double y, double z, double w)
{
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
	this->data[3] = w;
}