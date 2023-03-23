#pragma once
#include <cmath>

struct Vector2;

struct Matrix3x3
{
public:
	Matrix3x3()
	{
		_11 = 0.f; _12 = 0.f; _13 = 1.f;
		_21 = 0.f; _22 = 0.f; _23 = 1.f;
		_31 = 1.f; _32 = 1.f; _33 = 1.f;
	}

	Matrix3x3(const Matrix3x3& _rhs);

public:
	Matrix3x3 operator*(const Matrix3x3& _inMatrix);
	Matrix3x3 operator+(const Matrix3x3& _inMatrix);
	Matrix3x3 operator-(const Matrix3x3& _inMatrix);
	Matrix3x3& operator*=(const Matrix3x3& _inMatrix);
	Matrix3x3& operator=(const Matrix3x3& _inMatrix);

	Vector2 operator*(const Vector2& _inVector);

public:
	static Matrix3x3 Identity();
	static Matrix3x3 Translation(float _x, float _y);
	static Matrix3x3 Translation(const Vector2& _inVector);
	static Matrix3x3 Rotation(const Vector2& _inVector);
	static Matrix3x3 Rotation(float _cos, float _sin);
	static Matrix3x3 Transpose(const Matrix3x3& _inMatrix);

public:
	union {
		struct {
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
		};
		float f2[3][3];
		float f1[9];
	};
};