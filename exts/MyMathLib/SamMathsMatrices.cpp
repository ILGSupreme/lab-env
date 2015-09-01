#include "SamMathsMatrices.h"
#include <stdexcept>

Matrix3D::Matrix3D()
{
	this->data[0][0] = 0, data[0][1] = 0, data[0][2] = 0;
	this->data[1][0] = 0, data[1][1] = 0, data[1][2] = 0;
	this->data[2][0] = 0, data[2][1] = 0, data[2][2] = 0;
}

Matrix3D::Matrix3D(Vector3f vec1,Vector3f vec2,Vector3f vec3)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2];
}

Matrix3D::Matrix3D(Vector3d vec1, Vector3d vec2, Vector3d vec3)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2];
}

Matrix3D Mat3::InitIdentityMat3()
{
	return Matrix3D(Vector3f(1, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1));
}

Matrix3D  Mat3::InitRotationMat3X(float angle)
{
	return Matrix3D(Vector3f(1, 0, 0), Vector3f(0, cos(angle), -sin(angle)), Vector3f(0, sin(angle), cos(angle)));
}

Matrix3D  Mat3::InitRotationMat3Y(float angle)
{
	return Matrix3D(Vector3f(cos(angle), 0, sin(angle)), Vector3f(0, 1, 0), Vector3f(-sin(angle),0,cos(angle)));
}

Matrix3D  Mat3::InitRotationMat3Z(float angle)
{
	return Matrix3D(Vector3f(cos(angle), -sin(angle), 0),Vector3f(sin(angle),cos(angle),0),Vector3f(0,0,1));
}

Matrix3D  Mat3::InitScalingMat3(Vector3f vec)
{
	return Matrix3D(Vector3f(vec[0], 0, 0), Vector3f(0, vec[1], 0), Vector3f(0, 0, vec[2]));
}

Matrix3D Mat3::InitTranslateMat3(Vector3f vec)
{
	return Matrix3D(Vector3f(1, 0,vec[0]), Vector3f(1,0,vec[1]), Vector3f(1, 0, 0));
}

Matrix3D Mat3::InitRotationArbM3(Vector3f vec, float angle)
{
	double t = 1 - cos(angle);
	double S = sin(angle);
	double C = cos(angle);

	return Matrix3D(Vector3d(C + (t*vec[0] * vec[0]), (t*(vec[0] * vec[1])) - (vec[2] * S), ((vec[0] * vec[2])*t) + (S*vec[1])),

		Vector3d(t*(vec[0] * vec[1]) + (S*vec[2]), (t*vec[1] * vec[1])+C, t*(vec[1] * vec[2]) - (S*vec[0])),

		Vector3d(t*(vec[0] * vec[2]) - (S*vec[1]), t*(vec[1] * vec[2]) + S*vec[0], t*(vec[2] * vec[2]) + C));
}

Matrix3D operator+(const Matrix3D & matrix, const Matrix3D &_matrix)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] + _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] + _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] + _matrix.data[0][2];
	newMatrix.data[1][0] = matrix.data[1][0] + _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] + _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] + _matrix.data[1][2];
	newMatrix.data[2][0] = matrix.data[2][0] + _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] + _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] + _matrix.data[2][2];
	return newMatrix;
}

Matrix3D operator-(const Matrix3D & matrix, const Matrix3D & _matrix)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] - _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] - _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] - _matrix.data[0][2];
	newMatrix.data[1][0] = matrix.data[1][0] - _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] - _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] - _matrix.data[1][2];
	newMatrix.data[2][0] = matrix.data[2][0] - _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] - _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] - _matrix.data[2][2];
	return newMatrix;
}

Matrix3D operator*(const float &scalar, const Matrix3D & matrix)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] * (double)scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * (double)scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * (double)scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * (double)scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * (double)scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * (double)scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * (double)scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * (double)scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * (double)scalar;
	return newMatrix;
}
Matrix3D operator*(const double &scalar, const Matrix3D & matrix)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3D operator*(const int &scalar, const Matrix3D & matrix)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] * (double)scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * (double)scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * (double)scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * (double)scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * (double)scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * (double)scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * (double)scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * (double)scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * (double)scalar;
	return newMatrix;
}
Matrix3D operator*(const Matrix3D & matrix, const float &scalar)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] * (double)scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * (double)scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * (double)scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * (double)scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * (double)scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * (double)scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * (double)scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * (double)scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * (double)scalar;
	return newMatrix;
}
Matrix3D operator*(const Matrix3D & matrix, const double &scalar)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3D operator*(const Matrix3D & matrix, const int &scalar)
{
	Matrix3D newMatrix = Matrix3D();
	newMatrix[0][0] = matrix.data[0][0] * (double)scalar;
	newMatrix[0][1] = matrix.data[0][1] * (double)scalar;
	newMatrix[0][2] = matrix.data[0][2] * (double)scalar;
	newMatrix[1][0] = matrix.data[1][0] * (double)scalar;
	newMatrix[1][1] = matrix.data[1][1] * (double)scalar;
	newMatrix[1][2] = matrix.data[1][2] * (double)scalar;
	newMatrix[2][0] = matrix.data[2][0] * (double)scalar;
	newMatrix[2][1] = matrix.data[2][1] * (double)scalar;
	newMatrix[2][2] = matrix.data[2][2] * (double)scalar;
	return newMatrix;
}

double* Matrix3D::operator[](int i)
{
	return this->data[i];
}

Vector3f operator*(const Vector3f & vector,Matrix3D matrix)
{
	return Vector3f(
		vector[0] * matrix[0][0] + vector[1] * matrix[1][0] + vector[2] * matrix[2][0],
		vector[0] * matrix[0][1] + vector[1] * matrix[1][1] + vector[2] * matrix[2][1],
		vector[0] * matrix[0][2] + vector[1] * matrix[1][2] + vector[2] * matrix[2][2]
		);
}

Vector3f operator*(Matrix3D matrix, const Vector3f & vector)
{
	Matrix3D mt = matrix.GetTranspose();
	return Vector3f(
		mt[0][0] * vector[0] + mt[0][1] * vector[1] + mt[0][2] * vector[2],
		mt[1][0] * vector[0] + mt[1][1] * vector[1] + mt[1][2] * vector[2],
		mt[2][0] * vector[0] + mt[2][1] * vector[1] + mt[2][2] * vector[2]
		);
}

Matrix3D operator*(const Matrix3D & matrix, const Matrix3D & _matrix)
{
	Matrix3D m3 = Matrix3D();
	m3.data[0][0] = matrix.data[0][0] * _matrix.data[0][0] + matrix.data[0][1] * _matrix.data[1][0] + matrix.data[0][2] * _matrix.data[2][0];
	m3.data[0][1] = matrix.data[0][0] * _matrix.data[0][1] + matrix.data[0][1] * _matrix.data[1][1] + matrix.data[0][2] * _matrix.data[2][1];
	m3.data[0][2] = matrix.data[0][0] * _matrix.data[0][2] + matrix.data[0][1] * _matrix.data[1][2] + matrix.data[0][2] * _matrix.data[2][2];

	m3.data[1][0] = matrix.data[1][0] * _matrix.data[0][0] + matrix.data[1][1] * _matrix.data[1][0] + matrix.data[1][2] * _matrix.data[2][0];
	m3.data[1][1] = matrix.data[1][0] * _matrix.data[0][1] + matrix.data[1][1] * _matrix.data[1][1] + matrix.data[1][2] * _matrix.data[2][1];
	m3.data[1][2] = matrix.data[1][0] * _matrix.data[0][2] + matrix.data[1][1] * _matrix.data[1][2] + matrix.data[1][2] * _matrix.data[2][2];

	m3.data[2][0] = matrix.data[2][0] * _matrix.data[0][0] + matrix.data[2][1] * _matrix.data[1][0] + matrix.data[2][2] * _matrix.data[2][0];
	m3.data[2][1] = matrix.data[2][0] * _matrix.data[0][1] + matrix.data[2][1] * _matrix.data[1][1] + matrix.data[2][2] * _matrix.data[2][1];
	m3.data[2][2] = matrix.data[2][0] * _matrix.data[0][2] + matrix.data[2][1] * _matrix.data[1][2] + matrix.data[2][2] * _matrix.data[2][2];

	return m3;
}

void Matrix3D::Transpose()
{
	Matrix3D t = Matrix3D(Vector3d(this->data[0][0], this->data[1][0], this->data[2][0]), Vector3d(this->data[0][1], this->data[1][1], this->data[2][1]), Vector3d(this->data[0][2], this->data[1][2], this->data[2][2]));
	this->data[0][0] = t.data[0][0];
	this->data[0][1] = t.data[0][1];
	this->data[0][2] = t.data[0][2];
	this->data[1][0] = t.data[1][0];
	this->data[1][1] = t.data[1][1];
	this->data[1][2] = t.data[1][2];
	this->data[2][0] = t.data[2][0];
	this->data[2][1] = t.data[2][1];
	this->data[2][2] = t.data[2][2];
}
Matrix3D Matrix3D::GetTranspose()
{
	return Matrix3D(Vector3d(this->data[0][0], this->data[1][0], this->data[2][0]), Vector3d(this->data[0][1], this->data[1][1], this->data[2][1]), Vector3d(this->data[0][2], this->data[1][2], this->data[2][2]));
}


void Matrix3D::Invert()
{
	double det = (data[0][0]*((data[1][1]*data[2][2]) - (data[2][1]*data[1][2]))) - (data[0][1]*((data[1][0]*data[2][2]) - (data[2][0]*data[1][2]))) + (data[0][2]*((data[1][0]*data[2][1]) - (data[2][0]*data[1][1])));
	if (det != 0)
	{
		double M11 = (data[1][1] * data[2][2]) - (data[1][2] * data[2][1]);//k
		double M12 = (data[0][2] * data[2][1]) - (data[0][1] * data[2][2]);//k
		double M13 = (data[0][1] * data[1][2]) - (data[0][2] * data[1][1]);//k
		double M21 = (data[1][2] * data[2][0]) - (data[1][0] * data[2][2]);//k
		double M22 = (data[0][0] * data[2][2]) - (data[0][2] * data[2][0]);//k
		double M23 = (data[0][2] * data[1][0]) - (data[0][0] * data[1][2]);//k
		double M31 = (data[1][0] * data[2][1]) - (data[1][1] * data[2][0]);//k
		double M32 = (data[0][1] * data[2][0]) - (data[0][0] * data[2][1]); //k
		double M33 = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]); // k

		Matrix3D inverse = Matrix3D(Vector3d(M11 / det, M12 / det, M13 / det), Vector3d(M21 / det, M22 / det, M23 / det), Vector3d(M31 / det, M32 / det, M33 / det));

		this->data[0][0] = inverse[0][0];
		this->data[0][1] = inverse[0][1];
		this->data[0][2] = inverse[0][2];
		this->data[1][0] = inverse[1][0];
		this->data[1][1] = inverse[1][1];
		this->data[1][2] = inverse[1][2];
		this->data[2][0] = inverse[2][0];
		this->data[2][1] = inverse[2][1];
		this->data[2][2] = inverse[2][2];
	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		throw std::runtime_error("Matrix Cant be Inversed!");
	}
}
Matrix3D Matrix3D::GetInverse()
{
	double det = (data[0][0] * ((data[1][1] * data[2][2]) - (data[2][1] * data[1][2]))) - (data[0][1] * ((data[1][0] * data[2][2]) - (data[2][0] * data[1][2]))) + (data[0][2] * ((data[1][0] * data[2][1]) - (data[2][0] * data[1][1])));
		if ( det != 0)
		{
			double M11 = (data[1][1] * data[2][2]) - (data[1][2] * data[2][1]);//k
			double M12 = (data[0][2] * data[2][1]) - (data[0][1] * data[2][2]);//k
			double M13 = (data[0][1] * data[1][2]) - (data[0][2] * data[1][1]);//k
			double M21 = (data[1][2] * data[2][0]) - (data[1][0] * data[2][2]);//k
			double M22 = (data[0][0] * data[2][2]) - (data[0][2] * data[2][0]);//k
			double M23 = (data[0][2] * data[1][0]) - (data[0][0] * data[1][2]);//k
			double M31 = (data[1][0] * data[2][1]) - (data[1][1] * data[2][0]);//k
			double M32 = (data[0][1] * data[2][0]) - (data[0][0] * data[2][1]); //k
			double M33 = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]); // k

			Matrix3D inverse = Matrix3D(Vector3d(M11/det, M12/det, M13/det), Vector3d(M21/det, M22/det, M23/det), Vector3d(M31/det, M32/det, M33/det));
			return inverse;
		}
		else
		{
			//throw std::exception("Matrix Cant be Inversed!");
			throw std::runtime_error("Matrix Cant be Inversed!");
		}
}

/// Matrix 3 FLOAT

Matrix3F::Matrix3F()
{
	this->data[0][0] = 0, data[0][1] = 0, data[0][2] = 0;
	this->data[1][0] = 0, data[1][1] = 0, data[1][2] = 0;
	this->data[2][0] = 0, data[2][1] = 0, data[2][2] = 0;
}

Matrix3F::Matrix3F(Vector3f vec1, Vector3f vec2, Vector3f vec3)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2];
}

Matrix3F::Matrix3F(Vector3d vec1, Vector3d vec2, Vector3d vec3)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2];
}

Matrix3F Mat3::InitIdentityMat3F()
{
	return Matrix3F(Vector3f(1, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1));
}

Matrix3F  Mat3::InitRotationMat3XF(float angle)
{
	return Matrix3F(Vector3f(1, 0, 0), Vector3f(0, cos(angle), -sin(angle)), Vector3f(0, sin(angle), cos(angle)));
}

Matrix3F  Mat3::InitRotationMat3YF(float angle)
{
	return Matrix3F(Vector3f(cos(angle), 0, sin(angle)), Vector3f(0, 1, 0), Vector3f(-sin(angle), 0, cos(angle)));
}

Matrix3F  Mat3::InitRotationMat3ZF(float angle)
{
	return Matrix3F(Vector3f(cos(angle), -sin(angle), 0), Vector3f(sin(angle), cos(angle), 0), Vector3f(0, 0, 1));
}

Matrix3F  Mat3::InitScalingMat3F(Vector3f vec)
{
	return Matrix3F(Vector3f(vec[0], 0, 0), Vector3f(0, vec[1], 0), Vector3f(0, 0, vec[2]));
}

Matrix3F Mat3::InitTranslateMat3F(Vector3f vec)
{
	return Matrix3F(Vector3f(1, 0, vec[0]), Vector3f(1, 0, vec[1]), Vector3f(1, 0, 0));
}

Matrix3F Mat3::InitRotationArbM3F(Vector3f vec, float angle)
{
	double t = 1 - cos(angle);
	double S = sin(angle);
	double C = cos(angle);

	return Matrix3F(Vector3d(C + (t*vec[0] * vec[0]), (t*(vec[0] * vec[1])) - (vec[2] * S), ((vec[0] * vec[2])*t) + (S*vec[1])),

		Vector3d(t*(vec[0] * vec[1]) + (S*vec[2]), (t*vec[1] * vec[1]) + C, t*(vec[1] * vec[2]) - (S*vec[0])),

		Vector3d(t*(vec[0] * vec[2]) - (S*vec[1]), t*(vec[1] * vec[2]) + S*vec[0], t*(vec[2] * vec[2]) + C));
}

Matrix3F operator+(const Matrix3F & matrix, const Matrix3F &_matrix)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] + _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] + _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] + _matrix.data[0][2];
	newMatrix.data[1][0] = matrix.data[1][0] + _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] + _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] + _matrix.data[1][2];
	newMatrix.data[2][0] = matrix.data[2][0] + _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] + _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] + _matrix.data[2][2];
	return newMatrix;
}

Matrix3F operator-(const Matrix3F & matrix, const Matrix3F & _matrix)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] - _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] - _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] - _matrix.data[0][2];
	newMatrix.data[1][0] = matrix.data[1][0] - _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] - _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] - _matrix.data[1][2];
	newMatrix.data[2][0] = matrix.data[2][0] - _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] - _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] - _matrix.data[2][2];
	return newMatrix;
}

Matrix3F operator*(const float &scalar, const Matrix3F & matrix)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3F operator*(const double &scalar, const Matrix3F & matrix)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3F operator*(const int &scalar, const Matrix3F & matrix)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3F operator*(const Matrix3F & matrix, const float &scalar)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3F operator*(const Matrix3F & matrix, const double &scalar)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}
Matrix3F operator*(const Matrix3F & matrix, const int &scalar)
{
	Matrix3F newMatrix = Matrix3F();
	newMatrix[0][0] = matrix.data[0][0] * scalar;
	newMatrix[0][1] = matrix.data[0][1] * scalar;
	newMatrix[0][2] = matrix.data[0][2] * scalar;
	newMatrix[1][0] = matrix.data[1][0] * scalar;
	newMatrix[1][1] = matrix.data[1][1] * scalar;
	newMatrix[1][2] = matrix.data[1][2] * scalar;
	newMatrix[2][0] = matrix.data[2][0] * scalar;
	newMatrix[2][1] = matrix.data[2][1] * scalar;
	newMatrix[2][2] = matrix.data[2][2] * scalar;
	return newMatrix;
}

float* Matrix3F::operator[](int i)
{
	return this->data[i];
}

Vector3f operator*(const Vector3f & vector, Matrix3F matrix)
{
	return Vector3f(
		vector[0] * matrix[0][0] + vector[1] * matrix[1][0] + vector[2] * matrix[2][0],
		vector[0] * matrix[0][1] + vector[1] * matrix[1][1] + vector[2] * matrix[2][1],
		vector[0] * matrix[0][2] + vector[1] * matrix[1][2] + vector[2] * matrix[2][2]
		);
}

Vector3f operator*(Matrix3F matrix, const Vector3f & vector)
{
	Matrix3F mt = matrix.GetTranspose();
	return Vector3f(
		mt[0][0] * vector[0] + mt[0][1] * vector[1] + mt[0][2] * vector[2],
		mt[1][0] * vector[0] + mt[1][1] * vector[1] + mt[1][2] * vector[2],
		mt[2][0] * vector[0] + mt[2][1] * vector[1] + mt[2][2] * vector[2]
		);
}

Matrix3F operator*(const Matrix3F & matrix, const Matrix3F & _matrix)
{
	Matrix3F m3 = Matrix3F();
	m3.data[0][0] = matrix.data[0][0] * _matrix.data[0][0] + matrix.data[0][1] * _matrix.data[1][0] + matrix.data[0][2] * _matrix.data[2][0];
	m3.data[0][1] = matrix.data[0][0] * _matrix.data[0][1] + matrix.data[0][1] * _matrix.data[1][1] + matrix.data[0][2] * _matrix.data[2][1];
	m3.data[0][2] = matrix.data[0][0] * _matrix.data[0][2] + matrix.data[0][1] * _matrix.data[1][2] + matrix.data[0][2] * _matrix.data[2][2];

	m3.data[1][0] = matrix.data[1][0] * _matrix.data[0][0] + matrix.data[1][1] * _matrix.data[1][0] + matrix.data[1][2] * _matrix.data[2][0];
	m3.data[1][1] = matrix.data[1][0] * _matrix.data[0][1] + matrix.data[1][1] * _matrix.data[1][1] + matrix.data[1][2] * _matrix.data[2][1];
	m3.data[1][2] = matrix.data[1][0] * _matrix.data[0][2] + matrix.data[1][1] * _matrix.data[1][2] + matrix.data[1][2] * _matrix.data[2][2];

	m3.data[2][0] = matrix.data[2][0] * _matrix.data[0][0] + matrix.data[2][1] * _matrix.data[1][0] + matrix.data[2][2] * _matrix.data[2][0];
	m3.data[2][1] = matrix.data[2][0] * _matrix.data[0][1] + matrix.data[2][1] * _matrix.data[1][1] + matrix.data[2][2] * _matrix.data[2][1];
	m3.data[2][2] = matrix.data[2][0] * _matrix.data[0][2] + matrix.data[2][1] * _matrix.data[1][2] + matrix.data[2][2] * _matrix.data[2][2];

	return m3;
}

void Matrix3F::Transpose()
{
	Matrix3F t = Matrix3F(Vector3d(this->data[0][0], this->data[1][0], this->data[2][0]), Vector3d(this->data[0][1], this->data[1][1], this->data[2][1]), Vector3d(this->data[0][2], this->data[1][2], this->data[2][2]));
	this->data[0][0] = t.data[0][0];
	this->data[0][1] = t.data[0][1];
	this->data[0][2] = t.data[0][2];
	this->data[1][0] = t.data[1][0];
	this->data[1][1] = t.data[1][1];
	this->data[1][2] = t.data[1][2];
	this->data[2][0] = t.data[2][0];
	this->data[2][1] = t.data[2][1];
	this->data[2][2] = t.data[2][2];
}
Matrix3F Matrix3F::GetTranspose()
{
	return Matrix3F(Vector3d(this->data[0][0], this->data[1][0], this->data[2][0]), Vector3d(this->data[0][1], this->data[1][1], this->data[2][1]), Vector3d(this->data[0][2], this->data[1][2], this->data[2][2]));
}


void Matrix3F::Invert()
{
	double det = (data[0][0] * ((data[1][1] * data[2][2]) - (data[2][1] * data[1][2]))) - (data[0][1] * ((data[1][0] * data[2][2]) - (data[2][0] * data[1][2]))) + (data[0][2] * ((data[1][0] * data[2][1]) - (data[2][0] * data[1][1])));
	if (det != 0)
	{
		double M11 = (data[1][1] * data[2][2]) - (data[1][2] * data[2][1]);//k
		double M12 = (data[0][2] * data[2][1]) - (data[0][1] * data[2][2]);//k
		double M13 = (data[0][1] * data[1][2]) - (data[0][2] * data[1][1]);//k
		double M21 = (data[1][2] * data[2][0]) - (data[1][0] * data[2][2]);//k
		double M22 = (data[0][0] * data[2][2]) - (data[0][2] * data[2][0]);//k
		double M23 = (data[0][2] * data[1][0]) - (data[0][0] * data[1][2]);//k
		double M31 = (data[1][0] * data[2][1]) - (data[1][1] * data[2][0]);//k
		double M32 = (data[0][1] * data[2][0]) - (data[0][0] * data[2][1]); //k
		double M33 = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]); // k

		Matrix3F inverse = Matrix3F(Vector3d(M11 / det, M12 / det, M13 / det), Vector3d(M21 / det, M22 / det, M23 / det), Vector3d(M31 / det, M32 / det, M33 / det));

		this->data[0][0] = inverse[0][0];
		this->data[0][1] = inverse[0][1];
		this->data[0][2] = inverse[0][2];
		this->data[1][0] = inverse[1][0];
		this->data[1][1] = inverse[1][1];
		this->data[1][2] = inverse[1][2];
		this->data[2][0] = inverse[2][0];
		this->data[2][1] = inverse[2][1];
		this->data[2][2] = inverse[2][2];
	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		throw std::runtime_error("Matrix Cant be Inversed!");
	}
}
Matrix3F Matrix3F::GetInverse()
{
	double det = (data[0][0] * ((data[1][1] * data[2][2]) - (data[2][1] * data[1][2]))) - (data[0][1] * ((data[1][0] * data[2][2]) - (data[2][0] * data[1][2]))) + (data[0][2] * ((data[1][0] * data[2][1]) - (data[2][0] * data[1][1])));
	if (det != 0)
	{
		double M11 = (data[1][1] * data[2][2]) - (data[1][2] * data[2][1]);//k
		double M12 = (data[0][2] * data[2][1]) - (data[0][1] * data[2][2]);//k
		double M13 = (data[0][1] * data[1][2]) - (data[0][2] * data[1][1]);//k
		double M21 = (data[1][2] * data[2][0]) - (data[1][0] * data[2][2]);//k
		double M22 = (data[0][0] * data[2][2]) - (data[0][2] * data[2][0]);//k
		double M23 = (data[0][2] * data[1][0]) - (data[0][0] * data[1][2]);//k
		double M31 = (data[1][0] * data[2][1]) - (data[1][1] * data[2][0]);//k
		double M32 = (data[0][1] * data[2][0]) - (data[0][0] * data[2][1]); //k
		double M33 = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]); // k

		Matrix3F inverse = Matrix3F(Vector3d(M11 / det, M12 / det, M13 / det), Vector3d(M21 / det, M22 / det, M23 / det), Vector3d(M31 / det, M32 / det, M33 / det));
		return inverse;
	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		throw std::runtime_error("Matrix Cant be Inversed!");
	}
}

Matrix3F::operator float *()
{
	return &this->data[0][0];
}




///// MATRIX 4 DOUBLE

Matrix4D::Matrix4D(const Matrix4D &other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
}




Matrix4D::Matrix4D()
{
	this->data[0][0] = 0, this->data[0][1] = 0, this->data[0][2] = 0, this->data[0][3]=0;
	this->data[1][0] = 0, this->data[1][1] = 0, this->data[1][2] = 0, this->data[1][3]=0;
	this->data[2][0] = 0, this->data[2][1] = 0, this->data[2][2] = 0; this->data[2][3]=0;
	this->data[3][0] = 0; this->data[3][1] = 0, this->data[3][2] = 0; this->data[3][3]=0;
}

Matrix4D::Matrix4D(Vector4f vec1, Vector4f vec2, Vector4f vec3,Vector4f vec4)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2], this->data[0][3] = vec1[3];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2], this->data[1][3] = vec2[3];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2], this->data[2][3] = vec3[3];
	this->data[3][0] = vec4[0], this->data[3][1] = vec4[1], this->data[3][2] = vec4[2], this->data[3][3] = vec4[3];
}

Matrix4D::Matrix4D(Vector4d vec1, Vector4d vec2, Vector4d vec3, Vector4d vec4)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2], this->data[0][3] = vec1[3];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2], this->data[1][3] = vec2[3];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2], this->data[2][3] = vec3[3];
	this->data[3][0] = vec4[0], this->data[3][1] = vec4[1], this->data[3][2] = vec4[2], this->data[3][3] = vec4[3];
}

Matrix4D& Matrix4D::operator=(const Matrix4D & other)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
	return *this;
}



Matrix4D Mat4::InitIdentityMat4D()
{
	return Matrix4D(Vector4d(1, 0, 0, 0), Vector4d(0, 1, 0, 0), Vector4d(0, 0, 1, 0), Vector4d(0, 0, 0, 1));
}

Matrix4D Mat4::InitRotationMat4XD(float angle)
{
	return Matrix4D(Vector4d(1, 0, 0, 0), Vector4d(0, cos(angle), -sin(angle), 0), Vector4d(0, sin(angle), cos(angle), 0), Vector4d(0, 0, 0, 1));
}

Matrix4D Mat4::InitRotationMat4YD(float angle)
{
	return Matrix4D(Vector4d(cos(angle), 0, sin(angle), 0), Vector4d(0, 1, 0, 0), Vector4d(-sin(angle), 0, cos(angle), 0), Vector4d(0, 0, 0, 1));
}
Matrix4D Mat4::InitRotationMat4ZD(float angle)
{
	return Matrix4D(Vector4d(cos(angle), -sin(angle), 0, 0), Vector4d(sin(angle), cos(angle), 0, 0), Vector4d(0, 0, 1, 0),Vector4d(0,0,0,1));
}

Matrix4D Mat4::InitRotationArbM4D(Vector3f vec, float angle)
{
	double t = 1 - cos(angle);
	double S = sin(angle);
	double C = cos(angle);

	return Matrix4D(Vector4d(C+(t*vec[0]*vec[0]), (t*(vec[0] * vec[1])) - (vec[2] * S), ((vec[0] * vec[2])*t) + (S*vec[1]), 0),

					Vector4d(t*(vec[0]*vec[1])+(S*vec[2]),(t*vec[1]*vec[1])+C,(t*(vec[1]*vec[2]))-(S*vec[0]),0),

					Vector4d(t*(vec[0]*vec[2])-(S*vec[1]),t*(vec[1]*vec[2])+(S*vec[0]),t*(vec[2]*vec[2])+C,0),
	
					Vector4d(0, 0, 0, 1));
}

Matrix4D Mat4::InitTranslationMat4D(const Vector3f& vec)
{
	return Matrix4D(Vector4d(1, 0, 0, vec[0]), Vector4d(0, 1, 0, vec[1]), Vector4d(0, 0, 1, vec[2]), Vector4d(0, 0, 0, 1));
}

Matrix4D Mat4::InitScalingMat4D(const Vector3f& vec)
{
	return Matrix4D(Vector4d(vec[0], 0, 0, 0), Vector4d(0, vec[1], 0, 0), Vector4d(0, 0, vec[2], 0), Vector4d(0, 0, 0, 1));
}
Matrix4D Mat4::InitFrustrumMat4D(float left, float right, float bottom, float top, float near, float far)
{
	if (right == left || top == bottom || near == far )
	{
		std::cout << "Error with the arguments for Frustrum Matrix";
		return Matrix4D();
	}
	if (near < 0.0 || far < near)
	{
		std::cout << "Error with the arguments for Frustrum Matrix";
		std::cout << "Near value must be higher than zero and far must be bigger than near";
		return Matrix4D();
	}

	return Matrix4D(Vector4d((2 * near) / (right - left),
		0, (-1)*((right + left) / (right - left)), 0),
		Vector4d(0, (2 * near) / (top - bottom), 
		(top + bottom) / (top - bottom), 0),
		Vector4d(0, 0, (-1)*((far + near) / (far - near)),
		(-1)*(2 * (far*near) / (far - near))),
		Vector4d(0, 0, 1, 0));
}


Matrix4D Mat4::InitPerspectiveMat4D(float fov, float aspect, float n, float f)
{
	float q = 1.0f / tan(SMUtility::DegreesToRadians(0.5f * fov));
	float A = q / aspect;
	float B = (n + f) / (n - f);
	float C = (2.0f * n * f) / (n - f);
	return Matrix4D(Vector4d(A, 0.0f, 0.0f, 0.0f),
					Vector4d(0.0f, q, 0.0f, 0.0f), 
					Vector4d(0.0f, 0.0f, B, C),
					Vector4d(0.0f, 0.0f, -1, 0.0f));
}

Matrix4D Mat4::InitLookAtMat4D(const Vector3f& vec_eye, const Vector3f& center, const Vector3f& up)
{
	Vector3f f = (center - vec_eye).getnormalize();

	Vector3f r = f.crossProduct(up);
	r.normalize();

	Vector3f u = r.crossProduct(f);
	u.normalize();

	return Matrix4D(Vector4f(r[0], r[1], r[2], 0), Vector4f(u[0], u[1], u[2], 0), Vector4f(-f[0], -f[1], -f[2], 0), Vector4f(0, 0, 0, 1)) * InitTranslationMat4D(Vector3f(-vec_eye[0], -vec_eye[1], -vec_eye[2]));

}

Matrix4D Mat4::InitOrthoPerspective4D(float left, float right, float bottom, float top, float near, float far)
{
	return Matrix4D(Vector4d((2 / (right - left)), 0, 0, ((left + right) / (left - right))),

					Vector4d(0, 2 / (top - bottom), 0, ((bottom + top) / (bottom - top))),

					Vector4d(0, 0, 2 / (near - far), ((near + far) / (far - near))),

					Vector4d(0, 0, 0, 1));
}

Matrix4D operator+(const Matrix4D & matrix, const Matrix4D &_matrix)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] + _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] + _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] + _matrix.data[0][2];
	newMatrix.data[0][3] = matrix.data[0][3] + _matrix.data[0][3];
	newMatrix.data[1][0] = matrix.data[1][0] + _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] + _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] + _matrix.data[1][2];
	newMatrix.data[1][3] = matrix.data[1][3] + _matrix.data[1][3];
	newMatrix.data[2][0] = matrix.data[2][0] + _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] + _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] + _matrix.data[2][2];
	newMatrix.data[2][3] = matrix.data[2][3] + _matrix.data[2][3];
	newMatrix.data[3][0] = matrix.data[3][0] + _matrix.data[3][0];
	newMatrix.data[3][1] = matrix.data[3][1] + _matrix.data[3][1];
	newMatrix.data[3][2] = matrix.data[3][2] + _matrix.data[3][2];
	newMatrix.data[3][3] = matrix.data[3][3] + _matrix.data[3][3];
	return newMatrix;
}

Matrix4D operator-(const Matrix4D & matrix, const Matrix4D & _matrix)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] - _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] - _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] - _matrix.data[0][2];
	newMatrix.data[0][3] = matrix.data[0][3] - _matrix.data[0][3];
	newMatrix.data[1][0] = matrix.data[1][0] - _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] - _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] - _matrix.data[1][2];
	newMatrix.data[1][3] = matrix.data[1][3] - _matrix.data[1][3];
	newMatrix.data[2][0] = matrix.data[2][0] - _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] - _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] - _matrix.data[2][2];
	newMatrix.data[2][3] = matrix.data[2][3] - _matrix.data[2][3];
	newMatrix.data[3][0] = matrix.data[3][0] - _matrix.data[3][0];
	newMatrix.data[3][1] = matrix.data[3][1] - _matrix.data[3][1];
	newMatrix.data[3][2] = matrix.data[3][2] - _matrix.data[3][2];
	newMatrix.data[3][3] = matrix.data[3][3] - _matrix.data[3][3];
	return newMatrix;
}

Matrix4D operator*(const float &scalar, const Matrix4D & matrix)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4D operator*(const double &scalar, const Matrix4D & matrix)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4D operator*(const int &scalar, const Matrix4D & matrix)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4D operator*(const Matrix4D & matrix, const float &scalar)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4D operator*(const Matrix4D & matrix, const double &scalar)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4D operator*(const Matrix4D & matrix, const int &scalar)
{
	Matrix4D newMatrix = Matrix4D();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}

double* Matrix4D::operator[] (int numb)
{
	return this->data[numb];
}

Matrix4D::operator float *()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_data[i][j] = data[i][j];
		}
	}
	return &_data[0][0];
}

Matrix4D::operator const float *() const
{
	//ÄNDRING!
	return (float*)&data[0][0];
}

Vector4f operator*(const Vector4f & vector, Matrix4D matrix)
{
	return Vector4f(
		vector[0] * matrix[0][0] + vector[1] * matrix[1][0] + vector[2] * matrix[2][0] + vector[3] * matrix[3][0],
		vector[0] * matrix[0][1] + vector[1] * matrix[1][1] + vector[2] * matrix[2][1] + vector[3] * matrix[3][1],
		vector[0] * matrix[0][2] + vector[1] * matrix[1][2] + vector[2] * matrix[2][2] + vector[3] * matrix[3][2],
		vector[0] * matrix[0][3] + vector[1] * matrix[1][3] + vector[2] * matrix[2][3] + vector[3] * matrix[3][3]
		);
}

Vector4f operator*(Matrix4D matrix, const Vector4f & vector)
{
	Matrix4D mt = matrix.GetTranspose();
	return Vector4f(
		mt[0][0] * vector[0] + mt[0][1] * vector[1] + mt[0][2] * vector[2] + mt[0][3] * vector[3],
		mt[1][0] * vector[0] + mt[1][1] * vector[1] + mt[1][2] * vector[2] + mt[1][3] * vector[3],
		mt[2][0] * vector[0] + mt[2][1] * vector[1] + mt[2][2] * vector[2] + mt[2][3] * vector[3],
		mt[3][0] * vector[0] + mt[3][1] * vector[1] + mt[3][2] * vector[2] + mt[3][3] * vector[3]
		);
}

Matrix4D operator*(const Matrix4D & matrix, const Matrix4D & _matrix)
{
	Matrix4D m3 = Matrix4D();
	m3.data[0][0] = (matrix.data[0][0] * _matrix.data[0][0]) + (matrix.data[0][1] * _matrix.data[1][0]) + (matrix.data[0][2] * _matrix.data[2][0]) + (matrix.data[0][3] * _matrix.data[3][0]);
	m3.data[0][1] = (matrix.data[0][0] * _matrix.data[0][1]) + (matrix.data[0][1] * _matrix.data[1][1]) + (matrix.data[0][2] * _matrix.data[2][1]) + (matrix.data[0][3] * _matrix.data[3][1]);
	m3.data[0][2] = (matrix.data[0][0] * _matrix.data[0][2]) + (matrix.data[0][1] * _matrix.data[1][2]) + (matrix.data[0][2] * _matrix.data[2][2]) + (matrix.data[0][3] * _matrix.data[3][2]);
	m3.data[0][3] = (matrix.data[0][0] * _matrix.data[0][3]) + (matrix.data[0][1] * _matrix.data[1][3]) + (matrix.data[0][2] * _matrix.data[2][3]) + (matrix.data[0][3] * _matrix.data[3][3]);

	m3.data[1][0] = matrix.data[1][0] * _matrix.data[0][0] + matrix.data[1][1] * _matrix.data[1][0] + matrix.data[1][2] * _matrix.data[2][0] + matrix.data[1][3] * _matrix.data[3][0];
	m3.data[1][1] = matrix.data[1][0] * _matrix.data[0][1] + matrix.data[1][1] * _matrix.data[1][1] + matrix.data[1][2] * _matrix.data[2][1] + matrix.data[1][3] * _matrix.data[3][1];
	m3.data[1][2] = matrix.data[1][0] * _matrix.data[0][2] + matrix.data[1][1] * _matrix.data[1][2] + matrix.data[1][2] * _matrix.data[2][2] + matrix.data[1][3] * _matrix.data[3][2];
	m3.data[1][3] = matrix.data[1][0] * _matrix.data[0][3] + matrix.data[1][1] * _matrix.data[1][3] + matrix.data[1][2] * _matrix.data[2][3] + matrix.data[1][3] * _matrix.data[3][3];

	m3.data[2][0] = matrix.data[2][0] * _matrix.data[0][0] + matrix.data[2][1] * _matrix.data[1][0] + matrix.data[2][2] * _matrix.data[2][0] + matrix.data[2][3] * _matrix.data[3][0];
	m3.data[2][1] = matrix.data[2][0] * _matrix.data[0][1] + matrix.data[2][1] * _matrix.data[1][1] + matrix.data[2][2] * _matrix.data[2][1] + matrix.data[2][3] * _matrix.data[3][1];
	m3.data[2][2] = matrix.data[2][0] * _matrix.data[0][2] + matrix.data[2][1] * _matrix.data[1][2] + matrix.data[2][2] * _matrix.data[2][2] + matrix.data[2][3] * _matrix.data[3][2];
	m3.data[2][3] = matrix.data[2][0] * _matrix.data[0][3] + matrix.data[2][1] * _matrix.data[1][3] + matrix.data[2][2] * _matrix.data[2][3] + matrix.data[2][3] * _matrix.data[3][3];

	m3.data[3][0] = matrix.data[3][0] * _matrix.data[0][0] + matrix.data[3][1] * _matrix.data[1][0] + matrix.data[3][2] * _matrix.data[2][0] + matrix.data[3][3] * _matrix.data[3][0];
	m3.data[3][1] = matrix.data[3][0] * _matrix.data[0][1] + matrix.data[3][1] * _matrix.data[1][1] + matrix.data[3][2] * _matrix.data[2][1] + matrix.data[3][3] * _matrix.data[3][1];
	m3.data[3][2] = matrix.data[3][0] * _matrix.data[0][2] + matrix.data[3][1] * _matrix.data[1][2] + matrix.data[3][2] * _matrix.data[2][2] + matrix.data[3][3] * _matrix.data[3][2];
	m3.data[3][3] = matrix.data[3][0] * _matrix.data[0][3] + matrix.data[3][1] * _matrix.data[1][3] + matrix.data[3][2] * _matrix.data[2][3] + matrix.data[3][3] * _matrix.data[3][3];

	return m3;
}

void Matrix4D::Transpose()
{
	Matrix4D t = Matrix4D(Vector4d(this->data[0][0], this->data[1][0], this->data[2][0],this->data[3][0]), Vector4d(this->data[0][1], this->data[1][1], this->data[2][1],this->data[3][1]), Vector4d(this->data[0][2], this->data[1][2], this->data[2][2],this->data[3][2]),Vector4d(this->data[0][3],this->data[1][3],this->data[2][3],this->data[3][3]));
	this->data[0][0] = t.data[0][0];
	this->data[0][1] = t.data[0][1];
	this->data[0][2] = t.data[0][2];
	this->data[0][3] = t.data[0][3];
	this->data[1][0] = t.data[1][0];
	this->data[1][1] = t.data[1][1];
	this->data[1][2] = t.data[1][2];
	this->data[1][3] = t.data[1][3];
	this->data[2][0] = t.data[2][0];
	this->data[2][1] = t.data[2][1];
	this->data[2][2] = t.data[2][2];
	this->data[2][3] = t.data[2][3];
	this->data[3][0] = t.data[3][0];
	this->data[3][1] = t.data[3][1];
	this->data[3][2] = t.data[3][2];
	this->data[3][3] = t.data[3][3];
}
Matrix4D Matrix4D::GetTranspose()
{
	Matrix4D t = Matrix4D(Vector4d(this->data[0][0], this->data[1][0], this->data[2][0], this->data[3][0]), Vector4d(this->data[0][1], this->data[1][1], this->data[2][1], this->data[3][1]), Vector4d(this->data[0][2], this->data[1][2], this->data[2][2], this->data[3][2]), Vector4d(this->data[0][3], this->data[1][3], this->data[2][3], this->data[3][3]));
	return t;
}


void Matrix4D::Invert()
{
	double det = +data[0][0] * data[1][1] * data[2][2] * data[3][3]
		+ data[0][0] * data[1][2] * data[2][3] * data[3][1]
		+ data[0][0] * data[1][3] * data[2][1] * data[3][2]

		+ data[0][1] * data[1][0] * data[2][3] * data[3][2]
		+ data[0][1] * data[1][2] * data[2][0] * data[3][3]
		+ data[0][1] * data[1][3] * data[2][2] * data[3][0]

		+ data[0][2] * data[1][0] * data[2][1] * data[3][3]
		+ data[0][2] * data[1][1] * data[2][3] * data[3][0]
		+ data[0][2] * data[1][3] * data[2][0] * data[3][1]


		+ data[0][3] * data[1][0] * data[2][2] * data[3][1]
		+ data[0][3] * data[1][1] * data[2][0] * data[3][2]
		+ data[0][3] * data[1][2] * data[2][1] * data[3][0]


		- data[0][0] * data[1][1] * data[2][3] * data[3][2]
		- data[0][0] * data[1][2] * data[2][1] * data[3][3]
		- data[0][0] * data[1][3] * data[2][2] * data[3][1]

		- data[0][1] * data[1][0] * data[2][2] * data[3][3]
		- data[0][1] * data[1][2] * data[2][3] * data[3][0]
		- data[0][1] * data[1][3] * data[2][0] * data[3][2]

		- data[0][2] * data[1][0] * data[2][3] * data[3][1]
		- data[0][2] * data[1][1] * data[2][0] * data[3][3]
		- data[0][2] * data[1][3] * data[2][1] * data[3][0]

		- data[0][3] * data[1][0] * data[2][1] * data[3][2]
		- data[0][3] * data[1][1] * data[2][2] * data[3][0]
		- data[0][3] * data[1][2] * data[2][0] * data[3][1];

	if (det != 0)
	{
		Matrix4D inverse;

		inverse[0][0] = (data[1][1] * data[2][2] * data[3][3]
			+ data[1][2] * data[2][3] * data[3][1]
			+ data[1][3] * data[2][1] * data[3][2]
			- data[1][1] * data[2][3] * data[3][2]
			- data[1][2] * data[2][1] * data[3][3]
			- data[1][3] * data[2][2] * data[3][1]);

		inverse[0][1] = (data[0][1] * data[2][3] * data[3][2]
			+ data[0][2] * data[2][1] * data[3][3]
			+ data[0][3] * data[2][2] * data[3][1]
			- data[0][1] * data[2][2] * data[3][3]
			- data[0][2] * data[2][3] * data[3][1]
			- data[0][3] * data[2][1] * data[3][2]);

		inverse[0][2] = (data[0][1] * data[1][2] * data[3][3]
			+ data[0][2] * data[1][3] * data[3][1]
			+ data[0][3] * data[1][1] * data[3][2]
			- data[0][1] * data[1][3] * data[3][2]
			- data[0][2] * data[1][1] * data[3][3]
			- data[0][3] * data[1][2] * data[3][1]);

		inverse[0][3] = (data[0][1] * data[1][3] * data[2][2]
			+ data[0][2] * data[1][1] * data[2][3]
			+ data[0][3] * data[1][2] * data[2][1]
			- data[0][1] * data[1][2] * data[2][3]
			- data[0][2] * data[1][3] * data[2][1]
			- data[0][3] * data[1][1] * data[2][2]);

		inverse[1][0] = (data[1][0] * data[2][3] * data[3][2]
			+ data[1][2] * data[2][0] * data[3][3]
			+ data[1][3] * data[2][2] * data[3][0]
			- data[1][0] * data[2][2] * data[3][3]
			- data[1][2] * data[2][3] * data[3][0]
			- data[1][3] * data[2][0] * data[3][2]);

		inverse[1][1] = (data[0][0] * data[2][2] * data[3][3]
			+ data[0][2] * data[2][3] * data[3][0]
			+ data[0][3] * data[2][0] * data[3][2]
			- data[0][0] * data[2][3] * data[3][2]
			- data[0][2] * data[2][0] * data[3][3]
			- data[0][3] * data[2][2] * data[3][0]);

		inverse[1][2] = (data[0][0] * data[1][3] * data[3][2]
			+ data[0][2] * data[1][0] * data[3][3]
			+ data[0][3] * data[1][2] * data[3][0]
			- data[0][0] * data[1][2] * data[3][3]
			- data[0][2] * data[1][3] * data[3][0]
			- data[0][3] * data[1][0] * data[3][2]);

		inverse[1][3] = (data[0][0] * data[1][2] * data[2][3]
			+ data[0][2] * data[1][3] * data[2][0]
			+ data[0][3] * data[1][0] * data[2][2]
			- data[0][0] * data[1][3] * data[2][2]
			- data[0][2] * data[1][0] * data[2][3]
			- data[0][3] * data[1][2] * data[2][0]);

		inverse[2][0] = (data[1][0] * data[2][1] * data[3][3]
			+ data[1][1] * data[2][3] * data[3][0]
			+ data[1][3] * data[2][0] * data[3][1]
			- data[1][0] * data[2][3] * data[3][1]
			- data[1][1] * data[2][0] * data[3][3]
			- data[1][3] * data[2][1] * data[3][0]);

		inverse[2][1] = (data[0][0] * data[2][3] * data[3][1]
			+ data[0][1] * data[2][0] * data[3][3]
			+ data[0][3] * data[2][1] * data[3][0]
			- data[0][0] * data[2][1] * data[3][3]
			- data[0][1] * data[2][3] * data[3][0]
			- data[0][3] * data[2][0] * data[3][1]);

		inverse[2][2] = (data[0][0] * data[1][1] * data[3][3]
			+ data[0][1] * data[1][3] * data[3][0]
			+ data[0][3] * data[1][0] * data[3][1]
			- data[0][0] * data[1][3] * data[3][1]
			- data[0][1] * data[1][0] * data[3][3]
			- data[0][3] * data[1][1] * data[3][0]);

		inverse[2][3] = (data[0][0] * data[1][3] * data[2][1]
			+ data[0][1] * data[1][0] * data[2][3]
			+ data[0][3] * data[1][1] * data[2][0]
			- data[0][0] * data[1][1] * data[2][3]
			- data[0][1] * data[1][3] * data[2][0]
			- data[0][3] * data[1][0] * data[2][1]);

		inverse[3][0] = (data[1][0] * data[2][2] * data[3][1]
			+ data[1][1] * data[2][0] * data[3][2]
			+ data[1][2] * data[2][1] * data[3][0]
			- data[1][0] * data[2][1] * data[3][2]
			- data[1][1] * data[2][2] * data[3][0]
			- data[1][2] * data[2][0] * data[3][1]);

		inverse[3][1] = (data[0][0] * data[2][1] * data[3][2]
			+ data[0][1] * data[2][2] * data[3][0]
			+ data[0][2] * data[2][0] * data[3][1]
			- data[0][0] * data[2][2] * data[3][1]
			- data[0][1] * data[2][0] * data[3][2]
			- data[0][2] * data[2][1] * data[3][0]);

		inverse[3][2] = (data[0][0] * data[1][2] * data[3][1]
			+ data[0][1] * data[1][0] * data[3][2]
			+ data[0][2] * data[1][1] * data[3][0]
			- data[0][0] * data[1][1] * data[3][2]
			- data[0][1] * data[1][2] * data[3][0]
			- data[0][2] * data[1][0] * data[3][1]);

		inverse[3][3] = (data[0][0] * data[1][1] * data[2][2]
			+ data[0][1] * data[1][2] * data[2][0]
			+ data[0][2] * data[1][0] * data[2][1]
			- data[0][0] * data[1][2] * data[2][1]
			- data[0][1] * data[1][0] * data[2][2]
			- data[0][2] * data[1][1] * data[2][0]);

		this->data[0][0] = inverse[0][0] / det;
		this->data[0][1] = inverse[0][1] / det;
		this->data[0][2] = inverse[0][2] / det;
		this->data[0][3] = inverse[0][3] / det;

		this->data[1][0] = inverse[1][0] / det;
		this->data[1][1] = inverse[1][1] / det;
		this->data[1][2] = inverse[1][2] / det;
		this->data[1][3] = inverse[1][3] / det;

		this->data[2][0] = inverse[2][0] / det;
		this->data[2][1] = inverse[2][1] / det;
		this->data[2][2] = inverse[2][2] / det;
		this->data[2][3] = inverse[2][3] / det;

		this->data[3][0] = inverse[3][0] / det;
		this->data[3][1] = inverse[3][1] / det;
		this->data[3][2] = inverse[3][2] / det;
		this->data[3][3] = inverse[3][3] / det;

	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		 throw std::runtime_error("Matrix Cant be Inversed!");
	}
}

Matrix4D Matrix4D::GetInverse()
{
	double det = +data[0][0] * data[1][1] * data[2][2] * data[3][3]
		+ data[0][0] * data[1][2] * data[2][3] * data[3][1]
		+ data[0][0] * data[1][3] * data[2][1] * data[3][2]

		+ data[0][1] * data[1][0] * data[2][3] * data[3][2]
		+ data[0][1] * data[1][2] * data[2][0] * data[3][3]
		+ data[0][1] * data[1][3] * data[2][2] * data[3][0]

		+ data[0][2] * data[1][0] * data[2][1] * data[3][3]
		+ data[0][2] * data[1][1] * data[2][3] * data[3][0]
		+ data[0][2] * data[1][3] * data[2][0] * data[3][1]


		+ data[0][3] * data[1][0] * data[2][2] * data[3][1]
		+ data[0][3] * data[1][1] * data[2][0] * data[3][2]
		+ data[0][3] * data[1][2] * data[2][1] * data[3][0]


		- data[0][0] * data[1][1] * data[2][3] * data[3][2]
		- data[0][0] * data[1][2] * data[2][1] * data[3][3]
		- data[0][0] * data[1][3] * data[2][2] * data[3][1]

		- data[0][1] * data[1][0] * data[2][2] * data[3][3]
		- data[0][1] * data[1][2] * data[2][3] * data[3][0]
		- data[0][1] * data[1][3] * data[2][0] * data[3][2]

		- data[0][2] * data[1][0] * data[2][3] * data[3][1]
		- data[0][2] * data[1][1] * data[2][0] * data[3][3]
		- data[0][2] * data[1][3] * data[2][1] * data[3][0]

		- data[0][3] * data[1][0] * data[2][1] * data[3][2]
		- data[0][3] * data[1][1] * data[2][2] * data[3][0]
		- data[0][3] * data[1][2] * data[2][0] * data[3][1];

	if (det != 0)
	{
		Matrix4D inverse;

		inverse[0][0] = (data[1][1] * data[2][2] * data[3][3]
			+ data[1][2] * data[2][3] * data[3][1]
			+ data[1][3] * data[2][1] * data[3][2]
			- data[1][1] * data[2][3] * data[3][2]
			- data[1][2] * data[2][1] * data[3][3]
			- data[1][3] * data[2][2] * data[3][1]);

		inverse[0][1] = (data[0][1] * data[2][3] * data[3][2]
			+ data[0][2] * data[2][1] * data[3][3]
			+ data[0][3] * data[2][2] * data[3][1]
			- data[0][1] * data[2][2] * data[3][3]
			- data[0][2] * data[2][3] * data[3][1]
			- data[0][3] * data[2][1] * data[3][2]);

		inverse[0][2] = (data[0][1] * data[1][2] * data[3][3]
			+ data[0][2] * data[1][3] * data[3][1]
			+ data[0][3] * data[1][1] * data[3][2]
			- data[0][1] * data[1][3] * data[3][2]
			- data[0][2] * data[1][1] * data[3][3]
			- data[0][3] * data[1][2] * data[3][1]);

		inverse[0][3] = (data[0][1] * data[1][3] * data[2][2]
			+ data[0][2] * data[1][1] * data[2][3]
			+ data[0][3] * data[1][2] * data[2][1]
			- data[0][1] * data[1][2] * data[2][3]
			- data[0][2] * data[1][3] * data[2][1]
			- data[0][3] * data[1][1] * data[2][2]);

		inverse[1][0] = (data[1][0] * data[2][3] * data[3][2]
			+ data[1][2] * data[2][0] * data[3][3]
			+ data[1][3] * data[2][2] * data[3][0]
			- data[1][0] * data[2][2] * data[3][3]
			- data[1][2] * data[2][3] * data[3][0]
			- data[1][3] * data[2][0] * data[3][2]);

		inverse[1][1] = (data[0][0] * data[2][2] * data[3][3]
			+ data[0][2] * data[2][3] * data[3][0]
			+ data[0][3] * data[2][0] * data[3][2]
			- data[0][0] * data[2][3] * data[3][2]
			- data[0][2] * data[2][0] * data[3][3]
			- data[0][3] * data[2][2] * data[3][0]);

		inverse[1][2] = (data[0][0] * data[1][3] * data[3][2]
			+ data[0][2] * data[1][0] * data[3][3]
			+ data[0][3] * data[1][2] * data[3][0]
			- data[0][0] * data[1][2] * data[3][3]
			- data[0][2] * data[1][3] * data[3][0]
			- data[0][3] * data[1][0] * data[3][2]);

		inverse[1][3] = (data[0][0] * data[1][2] * data[2][3]
			+ data[0][2] * data[1][3] * data[2][0]
			+ data[0][3] * data[1][0] * data[2][2]
			- data[0][0] * data[1][3] * data[2][2]
			- data[0][2] * data[1][0] * data[2][3]
			- data[0][3] * data[1][2] * data[2][0]);

		inverse[2][0] = (data[1][0] * data[2][1] * data[3][3]
			+ data[1][1] * data[2][3] * data[3][0]
			+ data[1][3] * data[2][0] * data[3][1]
			- data[1][0] * data[2][3] * data[3][1]
			- data[1][1] * data[2][0] * data[3][3]
			- data[1][3] * data[2][1] * data[3][0]);

		inverse[2][1] = (data[0][0] * data[2][3] * data[3][1]
			+ data[0][1] * data[2][0] * data[3][3]
			+ data[0][3] * data[2][1] * data[3][0]
			- data[0][0] * data[2][1] * data[3][3]
			- data[0][1] * data[2][3] * data[3][0]
			- data[0][3] * data[2][0] * data[3][1]);

		inverse[2][2] = (data[0][0] * data[1][1] * data[3][3]
			+ data[0][1] * data[1][3] * data[3][0]
			+ data[0][3] * data[1][0] * data[3][1]
			- data[0][0] * data[1][3] * data[3][1]
			- data[0][1] * data[1][0] * data[3][3]
			- data[0][3] * data[1][1] * data[3][0]);

		inverse[2][3] = (data[0][0] * data[1][3] * data[2][1]
			+ data[0][1] * data[1][0] * data[2][3]
			+ data[0][3] * data[1][1] * data[2][0]
			- data[0][0] * data[1][1] * data[2][3]
			- data[0][1] * data[1][3] * data[2][0]
			- data[0][3] * data[1][0] * data[2][1]);

		inverse[3][0] = (data[1][0] * data[2][2] * data[3][1]
			+ data[1][1] * data[2][0] * data[3][2]
			+ data[1][2] * data[2][1] * data[3][0]
			- data[1][0] * data[2][1] * data[3][2]
			- data[1][1] * data[2][2] * data[3][0]
			- data[1][2] * data[2][0] * data[3][1]);

		inverse[3][1] = (data[0][0] * data[2][1] * data[3][2]
			+ data[0][1] * data[2][2] * data[3][0]
			+ data[0][2] * data[2][0] * data[3][1]
			- data[0][0] * data[2][2] * data[3][1]
			- data[0][1] * data[2][0] * data[3][2]
			- data[0][2] * data[2][1] * data[3][0]);

		inverse[3][2] = (data[0][0] * data[1][2] * data[3][1]
			+ data[0][1] * data[1][0] * data[3][2]
			+ data[0][2] * data[1][1] * data[3][0]
			- data[0][0] * data[1][1] * data[3][2]
			- data[0][1] * data[1][2] * data[3][0]
			- data[0][2] * data[1][0] * data[3][1]);

		inverse[3][3] = (data[0][0] * data[1][1] * data[2][2]
			+ data[0][1] * data[1][2] * data[2][0]
			+ data[0][2] * data[1][0] * data[2][1]
			- data[0][0] * data[1][2] * data[2][1]
			- data[0][1] * data[1][0] * data[2][2]
			- data[0][2] * data[1][1] * data[2][0]);

		//Matrix4F inverse = Matrix4F(Vector4d(M11 / det, M12 / det, M13 / det, M14 / det), Vector4d(M21 / det, M22 / det, M23 / det, M24 / det), Vector4d(M31 / det, M32 / det, M33 / det, M34 / det), Vector4d(M41 / det, M42 / det, M43 / det, M44 / det));
		inverse = (1 / det) * inverse;
		//this->data[0][0] = M11 / det;
		//this->data[0][1] = M12 / det;
		//this->data[0][2] = M13 / det;
		//this->data[0][3] = M14 / det;

		//this->data[1][0] = M21 / det;
		//this->data[1][1] = M22 / det;
		//this->data[1][2] = M23 / det;
		//this->data[1][3] = M24 / det;

		//this->data[2][0] = M31 / det;
		//this->data[2][1] = M32 / det;
		//this->data[2][2] = M33 / det;
		//this->data[2][3] = M34 / det;

		//this->data[3][0] = M41 / det;
		//this->data[3][1] = M42 / det;
		//this->data[3][2] = M43 / det;
		//this->data[3][3] = M44 / det;

		return inverse;
	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		throw std::runtime_error("matrix cant be Inversed!");
	}
}

//FREE FUNCTIONS

void Mat4::M4Prod(const Matrix4D & matrix, const Matrix4D & _matrix, Matrix4D & resmatrix)
{
	resmatrix.data[0][0] = (matrix.data[0][0] * _matrix.data[0][0]) + (matrix.data[0][1] * _matrix.data[1][0]) + (matrix.data[0][2] * _matrix.data[2][0]) + (matrix.data[0][3] * _matrix.data[3][0]);
	resmatrix.data[0][1] = (matrix.data[0][0] * _matrix.data[0][1]) + (matrix.data[0][1] * _matrix.data[1][1]) + (matrix.data[0][2] * _matrix.data[2][1]) + (matrix.data[0][3] * _matrix.data[3][1]);
	resmatrix.data[0][2] = (matrix.data[0][0] * _matrix.data[0][2]) + (matrix.data[0][1] * _matrix.data[1][2]) + (matrix.data[0][2] * _matrix.data[2][2]) + (matrix.data[0][3] * _matrix.data[3][2]);
	resmatrix.data[0][3] = (matrix.data[0][0] * _matrix.data[0][3]) + (matrix.data[0][1] * _matrix.data[1][3]) + (matrix.data[0][2] * _matrix.data[2][3]) + (matrix.data[0][3] * _matrix.data[3][3]);

	resmatrix.data[1][0] = matrix.data[1][0] * _matrix.data[0][0] + matrix.data[1][1] * _matrix.data[1][0] + matrix.data[1][2] * _matrix.data[2][0] + matrix.data[1][3] * _matrix.data[3][0];
	resmatrix.data[1][1] = matrix.data[1][0] * _matrix.data[0][1] + matrix.data[1][1] * _matrix.data[1][1] + matrix.data[1][2] * _matrix.data[2][1] + matrix.data[1][3] * _matrix.data[3][1];
	resmatrix.data[1][2] = matrix.data[1][0] * _matrix.data[0][2] + matrix.data[1][1] * _matrix.data[1][2] + matrix.data[1][2] * _matrix.data[2][2] + matrix.data[1][3] * _matrix.data[3][2];
	resmatrix.data[1][3] = matrix.data[1][0] * _matrix.data[0][3] + matrix.data[1][1] * _matrix.data[1][3] + matrix.data[1][2] * _matrix.data[2][3] + matrix.data[1][3] * _matrix.data[3][3];

	resmatrix.data[2][0] = matrix.data[2][0] * _matrix.data[0][0] + matrix.data[2][1] * _matrix.data[1][0] + matrix.data[2][2] * _matrix.data[2][0] + matrix.data[2][3] * _matrix.data[3][0];
	resmatrix.data[2][1] = matrix.data[2][0] * _matrix.data[0][1] + matrix.data[2][1] * _matrix.data[1][1] + matrix.data[2][2] * _matrix.data[2][1] + matrix.data[2][3] * _matrix.data[3][1];
	resmatrix.data[2][2] = matrix.data[2][0] * _matrix.data[0][2] + matrix.data[2][1] * _matrix.data[1][2] + matrix.data[2][2] * _matrix.data[2][2] + matrix.data[2][3] * _matrix.data[3][2];
	resmatrix.data[2][3] = matrix.data[2][0] * _matrix.data[0][3] + matrix.data[2][1] * _matrix.data[1][3] + matrix.data[2][2] * _matrix.data[2][3] + matrix.data[2][3] * _matrix.data[3][3];

	resmatrix.data[3][0] = matrix.data[3][0] * _matrix.data[0][0] + matrix.data[3][1] * _matrix.data[1][0] + matrix.data[3][2] * _matrix.data[2][0] + matrix.data[3][3] * _matrix.data[3][0];
	resmatrix.data[3][1] = matrix.data[3][0] * _matrix.data[0][1] + matrix.data[3][1] * _matrix.data[1][1] + matrix.data[3][2] * _matrix.data[2][1] + matrix.data[3][3] * _matrix.data[3][1];
	resmatrix.data[3][2] = matrix.data[3][0] * _matrix.data[0][2] + matrix.data[3][1] * _matrix.data[1][2] + matrix.data[3][2] * _matrix.data[2][2] + matrix.data[3][3] * _matrix.data[3][2];
	resmatrix.data[3][3] = matrix.data[3][0] * _matrix.data[0][3] + matrix.data[3][1] * _matrix.data[1][3] + matrix.data[3][2] * _matrix.data[2][3] + matrix.data[3][3] * _matrix.data[3][3];
}

//MATRIX4 FLOAT

///// MATRIX 4 DOUBLE

Matrix4F::Matrix4F(const Matrix4F &other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
}




Matrix4F::Matrix4F()
{
	this->data[0][0] = 0, this->data[0][1] = 0, this->data[0][2] = 0, this->data[0][3] = 0;
	this->data[1][0] = 0, this->data[1][1] = 0, this->data[1][2] = 0, this->data[1][3] = 0;
	this->data[2][0] = 0, this->data[2][1] = 0, this->data[2][2] = 0; this->data[2][3] = 0;
	this->data[3][0] = 0; this->data[3][1] = 0, this->data[3][2] = 0; this->data[3][3] = 0;
}

Matrix4F::Matrix4F(Vector4f vec1, Vector4f vec2, Vector4f vec3, Vector4f vec4)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2], this->data[0][3] = vec1[3];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2], this->data[1][3] = vec2[3];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2], this->data[2][3] = vec3[3];
	this->data[3][0] = vec4[0], this->data[3][1] = vec4[1], this->data[3][2] = vec4[2], this->data[3][3] = vec4[3];
}

Matrix4F::Matrix4F(Vector4d vec1, Vector4d vec2, Vector4d vec3, Vector4d vec4)
{
	this->data[0][0] = vec1[0], this->data[0][1] = vec1[1], this->data[0][2] = vec1[2], this->data[0][3] = vec1[3];
	this->data[1][0] = vec2[0], this->data[1][1] = vec2[1], this->data[1][2] = vec2[2], this->data[1][3] = vec2[3];
	this->data[2][0] = vec3[0], this->data[2][1] = vec3[1], this->data[2][2] = vec3[2], this->data[2][3] = vec3[3];
	this->data[3][0] = vec4[0], this->data[3][1] = vec4[1], this->data[3][2] = vec4[2], this->data[3][3] = vec4[3];
}

Matrix4F& Matrix4F::operator=(const Matrix4F & other)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
	return *this;
}



Matrix4F Mat4::InitIdentityMat4F()
{
	return Matrix4F(Vector4d(1, 0, 0, 0), Vector4d(0, 1, 0, 0), Vector4d(0, 0, 1, 0), Vector4d(0, 0, 0, 1));
}

Matrix4F Mat4::InitRotationMat4XF(float angle)
{
	return Matrix4F(Vector4d(1, 0, 0, 0), Vector4d(0, cos(angle), -sin(angle), 0), Vector4d(0, sin(angle), cos(angle), 0), Vector4d(0, 0, 0, 1));
}

Matrix4F Mat4::InitRotationMat4YF(float angle)
{
	return Matrix4F(Vector4d(cos(angle), 0, sin(angle), 0), Vector4d(0, 1, 0, 0), Vector4d(-sin(angle), 0, cos(angle), 0), Vector4d(0, 0, 0, 1));
}
Matrix4F Mat4::InitRotationMat4ZF(float angle)
{
	return Matrix4F(Vector4d(cos(angle), -sin(angle), 0, 0), Vector4d(sin(angle), cos(angle), 0, 0), Vector4d(0, 0, 1, 0), Vector4d(0, 0, 0, 1));
}

Matrix4F Mat4::InitRotationArbM4F(Vector3f vec, float angle)
{
	double t = 1 - cos(angle);
	double S = sin(angle);
	double C = cos(angle);

	return Matrix4F(Vector4d(C + (t*vec[0] * vec[0]), (t*(vec[0] * vec[1])) - (vec[2] * S), ((vec[0] * vec[2])*t) + (S*vec[1]), 0),

		Vector4d(t*(vec[0] * vec[1]) + (S*vec[2]), (t*vec[1] * vec[1]) + C, (t*(vec[1] * vec[2])) - (S*vec[0]), 0),

		Vector4d(t*(vec[0] * vec[2]) - (S*vec[1]), t*(vec[1] * vec[2]) + (S*vec[0]), t*(vec[2] * vec[2]) + C, 0),

		Vector4d(0, 0, 0, 1));
}

Matrix4F Mat4::InitTranslationMat4F(const Vector3f& vec)
{
	return Matrix4F(Vector4d(1, 0, 0, vec[0]), Vector4d(0, 1, 0, vec[1]), Vector4d(0, 0, 1, vec[2]), Vector4d(0, 0, 0, 1));
}

Matrix4F Mat4::InitScalingMat4F(const Vector3f& vec)
{
	return Matrix4F(Vector4d(vec[0], 0, 0, 0), Vector4d(0, vec[1], 0, 0), Vector4d(0, 0, vec[2], 0), Vector4d(0, 0, 0, 1));
}
Matrix4F Mat4::InitFrustrumMat4F(float left, float right, float bottom, float top, float near, float far)
{
	if (right == left || top == bottom || near == far)
	{
		std::cout << "Error with the arguments for Frustrum Matrix";
		return Matrix4F();
	}
	if (near < 0.0 || far < near)
	{
		std::cout << "Error with the arguments for Frustrum Matrix";
		std::cout << "Near value must be higher than zero and far must be bigger than near";
		return Matrix4F();
	}

	return Matrix4F(Vector4d((2 * near) / (right - left), 0, (-1)*((right + left) / (right - left)), 0), Vector4d(0, (2 * near) / (top - bottom), (top + bottom) / (top - bottom), 0), Vector4d(0, 0, (-1)*((far + near) / (far - near)), (-1)*(2 * (far*near) / (far - near))), Vector4d(0, 0, 1, 0));
}


Matrix4F Mat4::InitPerspectiveMat4F(float fov, float aspect, float n, float f)
{
	float q = 1.0f / tan(SMUtility::DegreesToRadians(0.5f * fov));
	float A = q / aspect;
	float B = (n + f) / (n - f);
	float C = (2.0f * n * f) / (n - f);
	return Matrix4F(Vector4d(A, 0.0f, 0.0f, 0.0f),
		Vector4d(0.0f, q, 0.0f, 0.0f),
		Vector4d(0.0f, 0.0f, B, C),
		Vector4d(0.0f, 0.0f, -1, 0.0f));
}

Matrix4F Mat4::InitLookAtMat4F(const Vector3f& vec_eye, const Vector3f& center, const Vector3f& up)
{
	Vector3f f = (center - vec_eye).getnormalize();

	Vector3f r = f.crossProduct(up);
	r.normalize();

	Vector3f u = r.crossProduct(f);
	u.normalize();

	return Matrix4F(Vector4f(r[0], r[1], r[2], 0), 
		Vector4f(u[0], u[1], u[2], 0), 
		Vector4f(-f[0], -f[1], -f[2], 0),
		Vector4f(0, 0, 0, 1)) * InitTranslationMat4F(Vector3f(-vec_eye[0], -vec_eye[1], -vec_eye[2]));

}

Matrix4F Mat4::InitOrthoPerspective4F(float left, float right, float bottom, float top, float near, float far)
{
	return Matrix4F(Vector4d((2 / (right - left)), 0, 0, ((left + right) / (left - right))),

		Vector4d(0, 2 / (top - bottom), 0, ((bottom + top) / (bottom - top))),

		Vector4d(0, 0, 2 / (near - far), ((near + far) / (far - near))),

		Vector4d(0, 0, 0, 1));
}

Matrix4F operator+(const Matrix4F & matrix, const Matrix4F &_matrix)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] + _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] + _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] + _matrix.data[0][2];
	newMatrix.data[0][3] = matrix.data[0][3] + _matrix.data[0][3];
	newMatrix.data[1][0] = matrix.data[1][0] + _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] + _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] + _matrix.data[1][2];
	newMatrix.data[1][3] = matrix.data[1][3] + _matrix.data[1][3];
	newMatrix.data[2][0] = matrix.data[2][0] + _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] + _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] + _matrix.data[2][2];
	newMatrix.data[2][3] = matrix.data[2][3] + _matrix.data[2][3];
	newMatrix.data[3][0] = matrix.data[3][0] + _matrix.data[3][0];
	newMatrix.data[3][1] = matrix.data[3][1] + _matrix.data[3][1];
	newMatrix.data[3][2] = matrix.data[3][2] + _matrix.data[3][2];
	newMatrix.data[3][3] = matrix.data[3][3] + _matrix.data[3][3];
	return newMatrix;
}

Matrix4F operator-(const Matrix4F & matrix, const Matrix4F & _matrix)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] - _matrix.data[0][0];
	newMatrix.data[0][1] = matrix.data[0][1] - _matrix.data[0][1];
	newMatrix.data[0][2] = matrix.data[0][2] - _matrix.data[0][2];
	newMatrix.data[0][3] = matrix.data[0][3] - _matrix.data[0][3];
	newMatrix.data[1][0] = matrix.data[1][0] - _matrix.data[1][0];
	newMatrix.data[1][1] = matrix.data[1][1] - _matrix.data[1][1];
	newMatrix.data[1][2] = matrix.data[1][2] - _matrix.data[1][2];
	newMatrix.data[1][3] = matrix.data[1][3] - _matrix.data[1][3];
	newMatrix.data[2][0] = matrix.data[2][0] - _matrix.data[2][0];
	newMatrix.data[2][1] = matrix.data[2][1] - _matrix.data[2][1];
	newMatrix.data[2][2] = matrix.data[2][2] - _matrix.data[2][2];
	newMatrix.data[2][3] = matrix.data[2][3] - _matrix.data[2][3];
	newMatrix.data[3][0] = matrix.data[3][0] - _matrix.data[3][0];
	newMatrix.data[3][1] = matrix.data[3][1] - _matrix.data[3][1];
	newMatrix.data[3][2] = matrix.data[3][2] - _matrix.data[3][2];
	newMatrix.data[3][3] = matrix.data[3][3] - _matrix.data[3][3];
	return newMatrix;
}

Matrix4F operator*(const float &scalar, const Matrix4F & matrix)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4F operator*(const double &scalar, const Matrix4F & matrix)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4F operator*(const int &scalar, const Matrix4F & matrix)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4F operator*(const Matrix4F & matrix, const float &scalar)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4F operator*(const Matrix4F & matrix, const double &scalar)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}
Matrix4F operator*(const Matrix4F & matrix, const int &scalar)
{
	Matrix4F newMatrix = Matrix4F();
	newMatrix.data[0][0] = matrix.data[0][0] * scalar;
	newMatrix.data[0][1] = matrix.data[0][1] * scalar;
	newMatrix.data[0][2] = matrix.data[0][2] * scalar;
	newMatrix.data[0][3] = matrix.data[0][3] * scalar;
	newMatrix.data[1][0] = matrix.data[1][0] * scalar;
	newMatrix.data[1][1] = matrix.data[1][1] * scalar;
	newMatrix.data[1][2] = matrix.data[1][2] * scalar;
	newMatrix.data[1][3] = matrix.data[1][3] * scalar;
	newMatrix.data[2][0] = matrix.data[2][0] * scalar;
	newMatrix.data[2][1] = matrix.data[2][1] * scalar;
	newMatrix.data[2][2] = matrix.data[2][2] * scalar;
	newMatrix.data[2][3] = matrix.data[2][3] * scalar;
	newMatrix.data[3][0] = matrix.data[3][0] * scalar;
	newMatrix.data[3][1] = matrix.data[3][1] * scalar;
	newMatrix.data[3][2] = matrix.data[3][2] * scalar;
	newMatrix.data[3][3] = matrix.data[3][3] * scalar;
	return newMatrix;
}

float* Matrix4F::operator[] (int numb)
{
	return this->data[numb];
}

Matrix4F::operator float *()
{
	return &data[0][0];
}

Matrix4F::operator const float *() const
{
	//ÄNDRING!
	return &data[0][0];
}

Vector4f operator*(const Vector4f & vector, Matrix4F matrix)
{
	return Vector4f(
		vector[0] * matrix[0][0] + vector[1] * matrix[1][0] + vector[2] * matrix[2][0] + vector[3] * matrix[3][0],
		vector[0] * matrix[0][1] + vector[1] * matrix[1][1] + vector[2] * matrix[2][1] + vector[3] * matrix[3][1],
		vector[0] * matrix[0][2] + vector[1] * matrix[1][2] + vector[2] * matrix[2][2] + vector[3] * matrix[3][2],
		vector[0] * matrix[0][3] + vector[1] * matrix[1][3] + vector[2] * matrix[2][3] + vector[3] * matrix[3][3]
		);
}

Vector4f operator*(Matrix4F matrix, const Vector4f & vector)
{
	Matrix4F mt = matrix.GetTranspose();
	return Vector4f(
		mt[0][0] * vector[0] + mt[0][1] * vector[1] + mt[0][2] * vector[2] + mt[0][3] * vector[3],
		mt[1][0] * vector[0] + mt[1][1] * vector[1] + mt[1][2] * vector[2] + mt[1][3] * vector[3],
		mt[2][0] * vector[0] + mt[2][1] * vector[1] + mt[2][2] * vector[2] + mt[2][3] * vector[3],
		mt[3][0] * vector[0] + mt[3][1] * vector[1] + mt[3][2] * vector[2] + mt[3][3] * vector[3]
		);
}

Matrix4F operator*(const Matrix4F & matrix, const Matrix4F & _matrix)
{
	Matrix4F m3 = Matrix4F();
	m3.data[0][0] = (matrix.data[0][0] * _matrix.data[0][0]) + (matrix.data[0][1] * _matrix.data[1][0]) + (matrix.data[0][2] * _matrix.data[2][0]) + (matrix.data[0][3] * _matrix.data[3][0]);
	m3.data[0][1] = (matrix.data[0][0] * _matrix.data[0][1]) + (matrix.data[0][1] * _matrix.data[1][1]) + (matrix.data[0][2] * _matrix.data[2][1]) + (matrix.data[0][3] * _matrix.data[3][1]);
	m3.data[0][2] = (matrix.data[0][0] * _matrix.data[0][2]) + (matrix.data[0][1] * _matrix.data[1][2]) + (matrix.data[0][2] * _matrix.data[2][2]) + (matrix.data[0][3] * _matrix.data[3][2]);
	m3.data[0][3] = (matrix.data[0][0] * _matrix.data[0][3]) + (matrix.data[0][1] * _matrix.data[1][3]) + (matrix.data[0][2] * _matrix.data[2][3]) + (matrix.data[0][3] * _matrix.data[3][3]);

	m3.data[1][0] = matrix.data[1][0] * _matrix.data[0][0] + matrix.data[1][1] * _matrix.data[1][0] + matrix.data[1][2] * _matrix.data[2][0] + matrix.data[1][3] * _matrix.data[3][0];
	m3.data[1][1] = matrix.data[1][0] * _matrix.data[0][1] + matrix.data[1][1] * _matrix.data[1][1] + matrix.data[1][2] * _matrix.data[2][1] + matrix.data[1][3] * _matrix.data[3][1];
	m3.data[1][2] = matrix.data[1][0] * _matrix.data[0][2] + matrix.data[1][1] * _matrix.data[1][2] + matrix.data[1][2] * _matrix.data[2][2] + matrix.data[1][3] * _matrix.data[3][2];
	m3.data[1][3] = matrix.data[1][0] * _matrix.data[0][3] + matrix.data[1][1] * _matrix.data[1][3] + matrix.data[1][2] * _matrix.data[2][3] + matrix.data[1][3] * _matrix.data[3][3];

	m3.data[2][0] = matrix.data[2][0] * _matrix.data[0][0] + matrix.data[2][1] * _matrix.data[1][0] + matrix.data[2][2] * _matrix.data[2][0] + matrix.data[2][3] * _matrix.data[3][0];
	m3.data[2][1] = matrix.data[2][0] * _matrix.data[0][1] + matrix.data[2][1] * _matrix.data[1][1] + matrix.data[2][2] * _matrix.data[2][1] + matrix.data[2][3] * _matrix.data[3][1];
	m3.data[2][2] = matrix.data[2][0] * _matrix.data[0][2] + matrix.data[2][1] * _matrix.data[1][2] + matrix.data[2][2] * _matrix.data[2][2] + matrix.data[2][3] * _matrix.data[3][2];
	m3.data[2][3] = matrix.data[2][0] * _matrix.data[0][3] + matrix.data[2][1] * _matrix.data[1][3] + matrix.data[2][2] * _matrix.data[2][3] + matrix.data[2][3] * _matrix.data[3][3];

	m3.data[3][0] = matrix.data[3][0] * _matrix.data[0][0] + matrix.data[3][1] * _matrix.data[1][0] + matrix.data[3][2] * _matrix.data[2][0] + matrix.data[3][3] * _matrix.data[3][0];
	m3.data[3][1] = matrix.data[3][0] * _matrix.data[0][1] + matrix.data[3][1] * _matrix.data[1][1] + matrix.data[3][2] * _matrix.data[2][1] + matrix.data[3][3] * _matrix.data[3][1];
	m3.data[3][2] = matrix.data[3][0] * _matrix.data[0][2] + matrix.data[3][1] * _matrix.data[1][2] + matrix.data[3][2] * _matrix.data[2][2] + matrix.data[3][3] * _matrix.data[3][2];
	m3.data[3][3] = matrix.data[3][0] * _matrix.data[0][3] + matrix.data[3][1] * _matrix.data[1][3] + matrix.data[3][2] * _matrix.data[2][3] + matrix.data[3][3] * _matrix.data[3][3];

	return m3;
}

void Matrix4F::Transpose()
{
	Matrix4F t = Matrix4F(Vector4d(this->data[0][0], this->data[1][0], this->data[2][0], this->data[3][0]), Vector4d(this->data[0][1], this->data[1][1], this->data[2][1], this->data[3][1]), Vector4d(this->data[0][2], this->data[1][2], this->data[2][2], this->data[3][2]), Vector4d(this->data[0][3], this->data[1][3], this->data[2][3], this->data[3][3]));
	this->data[0][0] = t.data[0][0];
	this->data[0][1] = t.data[0][1];
	this->data[0][2] = t.data[0][2];
	this->data[0][3] = t.data[0][3];
	this->data[1][0] = t.data[1][0];
	this->data[1][1] = t.data[1][1];
	this->data[1][2] = t.data[1][2];
	this->data[1][3] = t.data[1][3];
	this->data[2][0] = t.data[2][0];
	this->data[2][1] = t.data[2][1];
	this->data[2][2] = t.data[2][2];
	this->data[2][3] = t.data[2][3];
	this->data[3][0] = t.data[3][0];
	this->data[3][1] = t.data[3][1];
	this->data[3][2] = t.data[3][2];
	this->data[3][3] = t.data[3][3];
}
Matrix4F Matrix4F::GetTranspose()
{
	Matrix4F t = Matrix4F(Vector4d(this->data[0][0], this->data[1][0], this->data[2][0], this->data[3][0]), Vector4d(this->data[0][1], this->data[1][1], this->data[2][1], this->data[3][1]), Vector4d(this->data[0][2], this->data[1][2], this->data[2][2], this->data[3][2]), Vector4d(this->data[0][3], this->data[1][3], this->data[2][3], this->data[3][3]));
	return t;
}


void Matrix4F::Invert()
{
	float det = +data[0][0] * data[1][1] * data[2][2] * data[3][3]
		+ data[0][0] * data[1][2] * data[2][3] * data[3][1]
		+ data[0][0] * data[1][3] * data[2][1] * data[3][2]

		+ data[0][1] * data[1][0] * data[2][3] * data[3][2]
		+ data[0][1] * data[1][2] * data[2][0] * data[3][3]
		+ data[0][1] * data[1][3] * data[2][2] * data[3][0]

		+ data[0][2] * data[1][0] * data[2][1] * data[3][3]
		+ data[0][2] * data[1][1] * data[2][3] * data[3][0]
		+ data[0][2] * data[1][3] * data[2][0] * data[3][1]


		+ data[0][3] * data[1][0] * data[2][2] * data[3][1]
		+ data[0][3] * data[1][1] * data[2][0] * data[3][2]
		+ data[0][3] * data[1][2] * data[2][1] * data[3][0]


		- data[0][0] * data[1][1] * data[2][3] * data[3][2]
		- data[0][0] * data[1][2] * data[2][1] * data[3][3]
		- data[0][0] * data[1][3] * data[2][2] * data[3][1]

		- data[0][1] * data[1][0] * data[2][2] * data[3][3]
		- data[0][1] * data[1][2] * data[2][3] * data[3][0]
		- data[0][1] * data[1][3] * data[2][0] * data[3][2]

		- data[0][2] * data[1][0] * data[2][3] * data[3][1]
		- data[0][2] * data[1][1] * data[2][0] * data[3][3]
		- data[0][2] * data[1][3] * data[2][1] * data[3][0]

		- data[0][3] * data[1][0] * data[2][1] * data[3][2]
		- data[0][3] * data[1][1] * data[2][2] * data[3][0]
		- data[0][3] * data[1][2] * data[2][0] * data[3][1];

	if (det != 0)
	{
		Matrix4F inverse;

		inverse[0][0] = (data[1][1] * data[2][2] * data[3][3]
			+ data[1][2] * data[2][3] * data[3][1]
			+ data[1][3] * data[2][1] * data[3][2]
			- data[1][1] * data[2][3] * data[3][2]
			- data[1][2] * data[2][1] * data[3][3]
			- data[1][3] * data[2][2] * data[3][1]);

		inverse[0][1] = (data[0][1] * data[2][3] * data[3][2]
			+ data[0][2] * data[2][1] * data[3][3]
			+ data[0][3] * data[2][2] * data[3][1]
			- data[0][1] * data[2][2] * data[3][3]
			- data[0][2] * data[2][3] * data[3][1]
			- data[0][3] * data[2][1] * data[3][2]);

		inverse[0][2] = (data[0][1] * data[1][2] * data[3][3]
			+ data[0][2] * data[1][3] * data[3][1]
			+ data[0][3] * data[1][1] * data[3][2]
			- data[0][1] * data[1][3] * data[3][2]
			- data[0][2] * data[1][1] * data[3][3]
			- data[0][3] * data[1][2] * data[3][1]);

		inverse[0][3] = (data[0][1] * data[1][3] * data[2][2]
			+ data[0][2] * data[1][1] * data[2][3]
			+ data[0][3] * data[1][2] * data[2][1]
			- data[0][1] * data[1][2] * data[2][3]
			- data[0][2] * data[1][3] * data[2][1]
			- data[0][3] * data[1][1] * data[2][2]);

		inverse[1][0] = (data[1][0] * data[2][3] * data[3][2]
			+ data[1][2] * data[2][0] * data[3][3]
			+ data[1][3] * data[2][2] * data[3][0]
			- data[1][0] * data[2][2] * data[3][3]
			- data[1][2] * data[2][3] * data[3][0]
			- data[1][3] * data[2][0] * data[3][2]);

		inverse[1][1] = (data[0][0] * data[2][2] * data[3][3]
			+ data[0][2] * data[2][3] * data[3][0]
			+ data[0][3] * data[2][0] * data[3][2]
			- data[0][0] * data[2][3] * data[3][2]
			- data[0][2] * data[2][0] * data[3][3]
			- data[0][3] * data[2][2] * data[3][0]);

		inverse[1][2] = (data[0][0] * data[1][3] * data[3][2]
			+ data[0][2] * data[1][0] * data[3][3]
			+ data[0][3] * data[1][2] * data[3][0]
			- data[0][0] * data[1][2] * data[3][3]
			- data[0][2] * data[1][3] * data[3][0]
			- data[0][3] * data[1][0] * data[3][2]);

		inverse[1][3] = (data[0][0] * data[1][2] * data[2][3]
			+ data[0][2] * data[1][3] * data[2][0]
			+ data[0][3] * data[1][0] * data[2][2]
			- data[0][0] * data[1][3] * data[2][2]
			- data[0][2] * data[1][0] * data[2][3]
			- data[0][3] * data[1][2] * data[2][0]);

		inverse[2][0] = (data[1][0] * data[2][1] * data[3][3]
			+ data[1][1] * data[2][3] * data[3][0]
			+ data[1][3] * data[2][0] * data[3][1]
			- data[1][0] * data[2][3] * data[3][1]
			- data[1][1] * data[2][0] * data[3][3]
			- data[1][3] * data[2][1] * data[3][0]);

		inverse[2][1] = (data[0][0] * data[2][3] * data[3][1]
			+ data[0][1] * data[2][0] * data[3][3]
			+ data[0][3] * data[2][1] * data[3][0]
			- data[0][0] * data[2][1] * data[3][3]
			- data[0][1] * data[2][3] * data[3][0]
			- data[0][3] * data[2][0] * data[3][1]);

		inverse[2][2] = (data[0][0] * data[1][1] * data[3][3]
			+ data[0][1] * data[1][3] * data[3][0]
			+ data[0][3] * data[1][0] * data[3][1]
			- data[0][0] * data[1][3] * data[3][1]
			- data[0][1] * data[1][0] * data[3][3]
			- data[0][3] * data[1][1] * data[3][0]);

		inverse[2][3] = (data[0][0] * data[1][3] * data[2][1]
			+ data[0][1] * data[1][0] * data[2][3]
			+ data[0][3] * data[1][1] * data[2][0]
			- data[0][0] * data[1][1] * data[2][3]
			- data[0][1] * data[1][3] * data[2][0]
			- data[0][3] * data[1][0] * data[2][1]);

		inverse[3][0] = (data[1][0] * data[2][2] * data[3][1]
			+ data[1][1] * data[2][0] * data[3][2]
			+ data[1][2] * data[2][1] * data[3][0]
			- data[1][0] * data[2][1] * data[3][2]
			- data[1][1] * data[2][2] * data[3][0]
			- data[1][2] * data[2][0] * data[3][1]);

		inverse[3][1] = (data[0][0] * data[2][1] * data[3][2]
			+ data[0][1] * data[2][2] * data[3][0]
			+ data[0][2] * data[2][0] * data[3][1]
			- data[0][0] * data[2][2] * data[3][1]
			- data[0][1] * data[2][0] * data[3][2]
			- data[0][2] * data[2][1] * data[3][0]);

		inverse[3][2] = (data[0][0] * data[1][2] * data[3][1]
			+ data[0][1] * data[1][0] * data[3][2]
			+ data[0][2] * data[1][1] * data[3][0]
			- data[0][0] * data[1][1] * data[3][2]
			- data[0][1] * data[1][2] * data[3][0]
			- data[0][2] * data[1][0] * data[3][1]);

		inverse[3][3] = (data[0][0] * data[1][1] * data[2][2]
			+ data[0][1] * data[1][2] * data[2][0]
			+ data[0][2] * data[1][0] * data[2][1]
			- data[0][0] * data[1][2] * data[2][1]
			- data[0][1] * data[1][0] * data[2][2]
			- data[0][2] * data[1][1] * data[2][0]);

		this->data[0][0] = inverse[0][0] / det;
		this->data[0][1] = inverse[0][1] / det;
		this->data[0][2] = inverse[0][2] / det;
		this->data[0][3] = inverse[0][3] / det;

		this->data[1][0] = inverse[1][0] / det;
		this->data[1][1] = inverse[1][1] / det;
		this->data[1][2] = inverse[1][2] / det;
		this->data[1][3] = inverse[1][3] / det;

		this->data[2][0] = inverse[2][0] / det;
		this->data[2][1] = inverse[2][1] / det;
		this->data[2][2] = inverse[2][2] / det;
		this->data[2][3] = inverse[2][3] / det;

		this->data[3][0] = inverse[3][0] / det;
		this->data[3][1] = inverse[3][1] / det;
		this->data[3][2] = inverse[3][2] / det;
		this->data[3][3] = inverse[3][3] / det;

	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		throw std::runtime_error("Matrix Cant be Inversed!");
	}
}

Matrix4F Matrix4F::GetInverse()
{
	float det = +data[0][0] * data[1][1] * data[2][2] * data[3][3]
		+ data[0][0] * data[1][2] * data[2][3] * data[3][1]
		+ data[0][0] * data[1][3] * data[2][1] * data[3][2]

		+ data[0][1] * data[1][0] * data[2][3] * data[3][2]
		+ data[0][1] * data[1][2] * data[2][0] * data[3][3]
		+ data[0][1] * data[1][3] * data[2][2] * data[3][0]

		+ data[0][2] * data[1][0] * data[2][1] * data[3][3]
		+ data[0][2] * data[1][1] * data[2][3] * data[3][0]
		+ data[0][2] * data[1][3] * data[2][0] * data[3][1]


		+ data[0][3] * data[1][0] * data[2][2] * data[3][1]
		+ data[0][3] * data[1][1] * data[2][0] * data[3][2]
		+ data[0][3] * data[1][2] * data[2][1] * data[3][0]


		- data[0][0] * data[1][1] * data[2][3] * data[3][2]
		- data[0][0] * data[1][2] * data[2][1] * data[3][3]
		- data[0][0] * data[1][3] * data[2][2] * data[3][1]

		- data[0][1] * data[1][0] * data[2][2] * data[3][3]
		- data[0][1] * data[1][2] * data[2][3] * data[3][0]
		- data[0][1] * data[1][3] * data[2][0] * data[3][2]

		- data[0][2] * data[1][0] * data[2][3] * data[3][1]
		- data[0][2] * data[1][1] * data[2][0] * data[3][3]
		- data[0][2] * data[1][3] * data[2][1] * data[3][0]

		- data[0][3] * data[1][0] * data[2][1] * data[3][2]
		- data[0][3] * data[1][1] * data[2][2] * data[3][0]
		- data[0][3] * data[1][2] * data[2][0] * data[3][1];

	if (det != 0)
	{
		Matrix4F inverse;

		inverse[0][0] = (data[1][1] * data[2][2] * data[3][3]
			+ data[1][2] * data[2][3] * data[3][1]
			+ data[1][3] * data[2][1] * data[3][2]
			- data[1][1] * data[2][3] * data[3][2]
			- data[1][2] * data[2][1] * data[3][3]
			- data[1][3] * data[2][2] * data[3][1]);

		inverse[0][1] = (data[0][1] * data[2][3] * data[3][2]
			+ data[0][2] * data[2][1] * data[3][3]
			+ data[0][3] * data[2][2] * data[3][1]
			- data[0][1] * data[2][2] * data[3][3]
			- data[0][2] * data[2][3] * data[3][1]
			- data[0][3] * data[2][1] * data[3][2]);

		inverse[0][2] = (data[0][1] * data[1][2] * data[3][3]
			+ data[0][2] * data[1][3] * data[3][1]
			+ data[0][3] * data[1][1] * data[3][2]
			- data[0][1] * data[1][3] * data[3][2]
			- data[0][2] * data[1][1] * data[3][3]
			- data[0][3] * data[1][2] * data[3][1]);

		inverse[0][3] = (data[0][1] * data[1][3] * data[2][2]
			+ data[0][2] * data[1][1] * data[2][3]
			+ data[0][3] * data[1][2] * data[2][1]
			- data[0][1] * data[1][2] * data[2][3]
			- data[0][2] * data[1][3] * data[2][1]
			- data[0][3] * data[1][1] * data[2][2]);

		inverse[1][0] = (data[1][0] * data[2][3] * data[3][2]
			+ data[1][2] * data[2][0] * data[3][3]
			+ data[1][3] * data[2][2] * data[3][0]
			- data[1][0] * data[2][2] * data[3][3]
			- data[1][2] * data[2][3] * data[3][0]
			- data[1][3] * data[2][0] * data[3][2]);

		inverse[1][1] = (data[0][0] * data[2][2] * data[3][3]
			+ data[0][2] * data[2][3] * data[3][0]
			+ data[0][3] * data[2][0] * data[3][2]
			- data[0][0] * data[2][3] * data[3][2]
			- data[0][2] * data[2][0] * data[3][3]
			- data[0][3] * data[2][2] * data[3][0]);

		inverse[1][2] = (data[0][0] * data[1][3] * data[3][2]
			+ data[0][2] * data[1][0] * data[3][3]
			+ data[0][3] * data[1][2] * data[3][0]
			- data[0][0] * data[1][2] * data[3][3]
			- data[0][2] * data[1][3] * data[3][0]
			- data[0][3] * data[1][0] * data[3][2]);

		inverse[1][3] = (data[0][0] * data[1][2] * data[2][3]
			+ data[0][2] * data[1][3] * data[2][0]
			+ data[0][3] * data[1][0] * data[2][2]
			- data[0][0] * data[1][3] * data[2][2]
			- data[0][2] * data[1][0] * data[2][3]
			- data[0][3] * data[1][2] * data[2][0]);

		inverse[2][0] = (data[1][0] * data[2][1] * data[3][3]
			+ data[1][1] * data[2][3] * data[3][0]
			+ data[1][3] * data[2][0] * data[3][1]
			- data[1][0] * data[2][3] * data[3][1]
			- data[1][1] * data[2][0] * data[3][3]
			- data[1][3] * data[2][1] * data[3][0]);

		inverse[2][1] = (data[0][0] * data[2][3] * data[3][1]
			+ data[0][1] * data[2][0] * data[3][3]
			+ data[0][3] * data[2][1] * data[3][0]
			- data[0][0] * data[2][1] * data[3][3]
			- data[0][1] * data[2][3] * data[3][0]
			- data[0][3] * data[2][0] * data[3][1]);

		inverse[2][2] = (data[0][0] * data[1][1] * data[3][3]
			+ data[0][1] * data[1][3] * data[3][0]
			+ data[0][3] * data[1][0] * data[3][1]
			- data[0][0] * data[1][3] * data[3][1]
			- data[0][1] * data[1][0] * data[3][3]
			- data[0][3] * data[1][1] * data[3][0]);

		inverse[2][3] = (data[0][0] * data[1][3] * data[2][1]
			+ data[0][1] * data[1][0] * data[2][3]
			+ data[0][3] * data[1][1] * data[2][0]
			- data[0][0] * data[1][1] * data[2][3]
			- data[0][1] * data[1][3] * data[2][0]
			- data[0][3] * data[1][0] * data[2][1]);

		inverse[3][0] = (data[1][0] * data[2][2] * data[3][1]
			+ data[1][1] * data[2][0] * data[3][2]
			+ data[1][2] * data[2][1] * data[3][0]
			- data[1][0] * data[2][1] * data[3][2]
			- data[1][1] * data[2][2] * data[3][0]
			- data[1][2] * data[2][0] * data[3][1]);

		inverse[3][1] = (data[0][0] * data[2][1] * data[3][2]
			+ data[0][1] * data[2][2] * data[3][0]
			+ data[0][2] * data[2][0] * data[3][1]
			- data[0][0] * data[2][2] * data[3][1]
			- data[0][1] * data[2][0] * data[3][2]
			- data[0][2] * data[2][1] * data[3][0]);

		inverse[3][2] = (data[0][0] * data[1][2] * data[3][1]
			+ data[0][1] * data[1][0] * data[3][2]
			+ data[0][2] * data[1][1] * data[3][0]
			- data[0][0] * data[1][1] * data[3][2]
			- data[0][1] * data[1][2] * data[3][0]
			- data[0][2] * data[1][0] * data[3][1]);

		inverse[3][3] = (data[0][0] * data[1][1] * data[2][2]
			+ data[0][1] * data[1][2] * data[2][0]
			+ data[0][2] * data[1][0] * data[2][1]
			- data[0][0] * data[1][2] * data[2][1]
			- data[0][1] * data[1][0] * data[2][2]
			- data[0][2] * data[1][1] * data[2][0]);

		//Matrix4F inverse = Matrix4F(Vector4d(M11 / det, M12 / det, M13 / det, M14 / det), Vector4d(M21 / det, M22 / det, M23 / det, M24 / det), Vector4d(M31 / det, M32 / det, M33 / det, M34 / det), Vector4d(M41 / det, M42 / det, M43 / det, M44 / det));
		inverse = (1 / det) * inverse;
		//this->data[0][0] = M11 / det;
		//this->data[0][1] = M12 / det;
		//this->data[0][2] = M13 / det;
		//this->data[0][3] = M14 / det;

		//this->data[1][0] = M21 / det;
		//this->data[1][1] = M22 / det;
		//this->data[1][2] = M23 / det;
		//this->data[1][3] = M24 / det;

		//this->data[2][0] = M31 / det;
		//this->data[2][1] = M32 / det;
		//this->data[2][2] = M33 / det;
		//this->data[2][3] = M34 / det;

		//this->data[3][0] = M41 / det;
		//this->data[3][1] = M42 / det;
		//this->data[3][2] = M43 / det;
		//this->data[3][3] = M44 / det;

		return inverse;
	}
	else
	{
		//throw std::exception("Matrix Cant be Inversed!");
		throw std::runtime_error("matrix cant be Inversed!");
	}
}

Matrix3F Matrix4F::GetMatrix3F()
{
	return Matrix3F(Vector3f(this->data[0][0], this->data[0][1], this->data[0][2]), Vector3f(this->data[1][0], this->data[1][1], this->data[1][2]), Vector3f(this->data[2][0], this->data[2][1], this->data[2][2]));
}

float SMUtility::DegreesToRadians(float angle)
{
	return angle * (M_PI / 180.0);
}

float SMUtility::RadiansToDegrees(float angle)
{
	return angle * (180 / M_PI);
}

