#include "Functions.h"
#include "Vector2.h"
#include "define.h"

const float DEG2RAD = 1.f / 180.f * 3.141592f;
const float RAD2DEG = 1.f / 3.141592f * 180.f;

float Clamp(float _min, float _max, float _value)
{
	if (_value > _max)
		return _max;

	else if (_value < _min)
		return _min;

	return _value;
}

float DegreeToRadian(float _degree)
{
	return _degree * DEG2RAD;
}

float RadianToDegree(float _radian)
{
	return _radian * RAD2DEG;
}

float Lerp(float _inFloat1, float _inFloat2, float _rate)
{
	if (_rate <= 0.f)
		return 0.f;

	return _inFloat1 * (1 - _rate) + _inFloat2 * _rate;
}

Vector2 LookAt(const Vector2& _inSrc, const Vector2& _inDest)
{
	Vector2 newVector(_inDest - _inSrc);

	return newVector.GetNormalize();
}
