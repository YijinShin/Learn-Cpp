#pragma once

#include <cmath>

struct Vector2;

// ���� ������ ������ŵ�ϴ�. (_min <= _value <= _max)
extern float Clamp(float _min, float _max, float _value);

// Degree ������ Radian���� ��ȯ�մϴ�.
extern float DegreeToRadian(float _degree);

// Radian ������ Degree�� ��ȯ�մϴ�.
extern float RadianToDegree(float _radian);

// �� �Ǽ��� �������� ���� ��ȯ�մϴ�.
extern float Lerp(float _inFloat1, float _inFloat2, float _rate);

// inSrc���� inDest�� ���ϴ� ����ȭ�� ���� ���͸� ��ȯ�մϴ�.
extern Vector2 LookAt(const Vector2& _inSrc, const Vector2& _inDest);