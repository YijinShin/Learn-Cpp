#pragma once

#include <cmath>
#include <cassert>
#include "Define.h"

struct Vector2
{
public:
	Vector2(float _x = 0.f, float _y = 0.f) : x(_x), y(_y) {}
	Vector2(const Vector2& _inVector) = default;

public:
	Vector2& operator=(const Vector2& _inVector) = default;
	Vector2 operator*(float _inScalar) const
	{
		return Vector2(x * _inScalar, y * _inScalar);
	}
	Vector2 operator/(float _inScalar) const
	{
		assert(_inScalar != 0.f); // divide by zero
		return Vector2(x / _inScalar, y / _inScalar);
	}
	Vector2 operator+(const Vector2& _inVector) const
	{
		return Vector2(x + _inVector.x, y + _inVector.y);
	}
	Vector2& operator+=(const Vector2& _inVector)
	{
		x += _inVector.x;
		y += _inVector.y;

		return *this;
	}
	Vector2& operator/=(float _inScalar)
	{
		assert(_inScalar != 0.f); // divide by zero
		x /= _inScalar;
		y /= _inScalar;

		return *this;
	}
	Vector2 GetNormalize() const
	{
		float length = Size();

		return operator/(length);
	}
	Vector2 Normalize()
	{
		float length = Size();

		x /= length;
		y /= length;
		return *this;
	}
	float Size() const
	{
		return sqrt(x * x + y * y);
	}

	void Rotate(float _inDegree)
	{
		x = cos(_inDegree * DEG2RAD);
		y = sin(_inDegree * DEG2RAD);
	}

public:
	float x;
	float y;
};