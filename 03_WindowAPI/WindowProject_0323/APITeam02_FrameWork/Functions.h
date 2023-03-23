#pragma once

#include <cmath>

struct Vector2;

// 값의 범위를 한정시킵니다. (_min <= _value <= _max)
extern float Clamp(float _min, float _max, float _value);

// Degree 각도를 Radian으로 반환합니다.
extern float DegreeToRadian(float _degree);

// Radian 각도를 Degree로 반환합니다.
extern float RadianToDegree(float _radian);

// 두 실수의 선형보간 값을 반환합니다.
extern float Lerp(float _inFloat1, float _inFloat2, float _rate);

// inSrc에서 inDest를 향하는 정규화된 방향 벡터를 반환합니다.
extern Vector2 LookAt(const Vector2& _inSrc, const Vector2& _inDest);