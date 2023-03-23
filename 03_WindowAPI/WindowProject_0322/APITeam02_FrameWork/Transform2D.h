#pragma once

#include "Vector2.h"
#include "Functions.h"

struct Transform2D
{
public:
	Transform2D()
		: position(Vector2::Zero), direction_up(-Vector2::UnitY), direction_right(Vector2::UnitX) {}

public:
	// 현재 위치에서 inVector만큼 이동
	void Translate(const Vector2& _inVector)
	{
		Translate(_inVector.x, _inVector.y);
	}

	// 현재 위치에서 inVector만큼 이동
	void Translate(float _x, float _y)
	{
		position.x += _x;
		position.y += _y;
	}

	// 현재 위치에서 degree만큼 회전
	void Rotate(float _degree)
	{
		float _cos = cos(DegreeToRadian(_degree));
		float _sin = sin(DegreeToRadian(_degree));

		//방향벡터 회전
		direction_up = Vector2(direction_up.x * _cos - direction_up.y * _sin, direction_up.x * _sin + direction_up.y * _cos);
		direction_right = Vector2(direction_right.x * _cos - direction_right.y * _sin, direction_right.x * _sin + direction_right.y * _cos);


		// matrix._11 = matrix._11 * _cos - matrix._12 * _sin;
		// matrix._12 = matrix._11 * _sin + matrix._12 * _cos;

		//rotation = Vector2(position.x * c - position.y * s, position.x * s + position.y * c);
	}

	// degree로 회전
	void SetRotation(float _degree)
	{
		float _cos = cos(DegreeToRadian(_degree));
		float _sin = sin(DegreeToRadian(_degree));

		direction_up = Vector2(_cos, _sin);
		direction_right = Vector2(-_sin, _cos);
	}

	// 해당 방향을 쳐다봄
	void LookAt(const Vector2& _inVector)
	{
		Vector2 pos(position.x, position.y);
		Vector2 normalize = (_inVector - pos).GetNormalize();

		direction_up = normalize;
		direction_right = Vector2(-normalize.y, normalize.x);
	}
	
public:
	// 위치 설정
	constexpr void SetPosition(const Vector2& _inVector)
	{
		SetPosition(_inVector.x, _inVector.y);
	}

	// 위치 설정
	constexpr void SetPosition(float _x, float _y)
	{
		position.x = _x;
		position.y = _y;
	}

	// 위치 반환
	constexpr Vector2 GetPosition() const
	{
		return position;
	}

public:
	
	// x성분 반환 (레퍼런스)
	constexpr float& X() { return position.x; }
	// y성분 반환 (레퍼런스)
	constexpr float& Y() { return position.y; }

	// up벡터 반환 (레퍼런스)
	constexpr Vector2& Up() { return direction_up; }
	// right벡터 반환 (레퍼런스)
	constexpr Vector2& Right() { return direction_right; }


private:
	Vector2	position;
	Vector2	direction_up;
	Vector2	direction_right;
};