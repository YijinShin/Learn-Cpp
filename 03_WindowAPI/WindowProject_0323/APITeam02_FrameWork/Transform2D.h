#pragma once

#include "Vector2.h"
#include "Functions.h"

struct Transform2D
{
public:
	Transform2D()
		: position(Vector2::Zero), direction_up(-Vector2::UnitY), direction_right(Vector2::UnitX) {}

public:
	// ���� ��ġ���� inVector��ŭ �̵�
	void Translate(const Vector2& _inVector)
	{
		Translate(_inVector.x, _inVector.y);
	}

	// ���� ��ġ���� inVector��ŭ �̵�
	void Translate(float _x, float _y)
	{
		position.x += _x;
		position.y += _y;
	}

	// ���� ��ġ���� degree��ŭ ȸ��
	void Rotate(float _degree)
	{
		float _cos = cos(DegreeToRadian(_degree));
		float _sin = sin(DegreeToRadian(_degree));

		//���⺤�� ȸ��
		direction_up = Vector2(direction_up.x * _cos - direction_up.y * _sin, direction_up.x * _sin + direction_up.y * _cos);
		direction_right = Vector2(direction_right.x * _cos - direction_right.y * _sin, direction_right.x * _sin + direction_right.y * _cos);


		// matrix._11 = matrix._11 * _cos - matrix._12 * _sin;
		// matrix._12 = matrix._11 * _sin + matrix._12 * _cos;

		//rotation = Vector2(position.x * c - position.y * s, position.x * s + position.y * c);
	}

	// degree�� ȸ��
	void SetRotation(float _degree)
	{
		float _cos = cos(DegreeToRadian(_degree));
		float _sin = sin(DegreeToRadian(_degree));

		direction_up = Vector2(_cos, _sin);
		direction_right = Vector2(-_sin, _cos);
	}

	// �ش� ������ �Ĵٺ�
	void LookAt(const Vector2& _inVector)
	{
		Vector2 pos(position.x, position.y);
		Vector2 normalize = (_inVector - pos).GetNormalize();

		direction_up = normalize;
		direction_right = Vector2(-normalize.y, normalize.x);
	}
	
public:
	// ��ġ ����
	constexpr void SetPosition(const Vector2& _inVector)
	{
		SetPosition(_inVector.x, _inVector.y);
	}

	// ��ġ ����
	constexpr void SetPosition(float _x, float _y)
	{
		position.x = _x;
		position.y = _y;
	}

	// ��ġ ��ȯ
	constexpr Vector2 GetPosition() const
	{
		return position;
	}

public:
	
	// x���� ��ȯ (���۷���)
	constexpr float& X() { return position.x; }
	// y���� ��ȯ (���۷���)
	constexpr float& Y() { return position.y; }

	// up���� ��ȯ (���۷���)
	constexpr Vector2& Up() { return direction_up; }
	// right���� ��ȯ (���۷���)
	constexpr Vector2& Right() { return direction_right; }


private:
	Vector2	position;
	Vector2	direction_up;
	Vector2	direction_right;
};