#include "Matrix3x3.h"
#include "Vector2.h"
#include <cassert>

Matrix3x3::Matrix3x3(const Matrix3x3& _rhs)
{
	for (int i = 0; i < 9; ++i)
		f1[i] = _rhs.f1[i];
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& _inMatrix)
{
	Matrix3x3 output;
	for (int i = 0; i < 3; ++i)
	{
		output.f2[i][0] =
			f2[i][0] * _inMatrix.f2[0][0] +
			f2[i][1] * _inMatrix.f2[1][0] +
			f2[i][2] * _inMatrix.f2[2][0];

		output.f2[i][1] =
			f2[i][0] * _inMatrix.f2[0][1] +
			f2[i][1] * _inMatrix.f2[1][1] +
			f2[i][2] * _inMatrix.f2[2][1];

		output.f2[i][2] =
			f2[i][0] * _inMatrix.f2[0][2] +
			f2[i][1] * _inMatrix.f2[1][2] +
			f2[i][2] * _inMatrix.f2[2][2];
	}

	return output;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& _inMatrix)
{
	Matrix3x3 output;
	for (int i = 0; i < 9; ++i)
		output.f1[i] = f1[i] + _inMatrix.f1[i];

	return output;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& _inMatrix)
{
	Matrix3x3 output;
	for (int i = 0; i < 9; ++i)
		output.f1[i] = f1[i] - _inMatrix.f1[i];

	return output;
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& _inMatrix)
{
	*this = *this * _inMatrix;

	return *this;
}

Matrix3x3& Matrix3x3::operator=(const Matrix3x3& _inMatrix)
{
	for (int i = 0; i < 9; ++i)
		f1[i] = _inMatrix.f1[i];

	return *this;
}

Vector2 Matrix3x3::operator*(const Vector2& _inVector)
{
	Vector2 output;
	output.x = _11 * _inVector.x + _12 * _inVector.y;
	output.y = _21 * _inVector.x + _22 * _inVector.y;

	return output;
}

Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 identity;
	identity._11 = 1.f; identity._12 = 0.f;	identity._13 = 0.f;
	identity._21 = 0.f;	identity._22 = 1.f;	identity._23 = 0.f;
	identity._31 = 0.f;	identity._32 = 0.f;	identity._33 = 1.f;

	return identity;
}

Matrix3x3 Matrix3x3::Translation(float _x, float _y)
{
	Matrix3x3 matrix;
	matrix._11 = 1.f;	matrix._12 = 0.f;	matrix._13 = 0.f;
	matrix._21 = 0.f;	matrix._22 = 1.f;	matrix._23 = 0.f;
	matrix._31 = _x;	matrix._32 = _y;	matrix._33 = 1.f;

	return matrix;
}

 Matrix3x3 Matrix3x3::Translation(const Vector2& _inVector)
{
	return Translation(_inVector.x, _inVector.y);
}

 Matrix3x3 Matrix3x3::Rotation(const Vector2& _inVector)
 {
	 return Rotation(_inVector.x, _inVector.y);
 }

 Matrix3x3 Matrix3x3::Rotation(float _cos, float _sin)
 {
	 Matrix3x3 matrix;

	 matrix._11 = _cos; matrix._12 = -_sin;
	 matrix._21 = _sin; matrix._22 = _cos;

	 return matrix;
 }

Matrix3x3 Matrix3x3::Transpose(const Matrix3x3& _inMatrix)
{
	Matrix3x3 transpose;
	transpose._11 = _inMatrix._11;	transpose._12 = _inMatrix._21;	transpose._13 = _inMatrix._31;
	transpose._21 = _inMatrix._12;	transpose._22 = _inMatrix._22;	transpose._23 = _inMatrix._32;
	transpose._31 = _inMatrix._13;	transpose._32 = _inMatrix._23;	transpose._33 = _inMatrix._33;

	return transpose;
}
