#pragma once

template <typename T>
void Safe_Delete(T& temp) {
	if (temp) {
		delete temp;
		temp = nullptr;
	}
}

template <typename T>
void Safe_Array_Delete(T& temp) {
	if (temp) {
		delete[] temp;
		temp = nullptr;
	}
}


inline float DegreeToRadian(float fDegree) {
	return (PI / 180.f) * fDegree;
}

inline float RadianToDegree(float fRadian) {
	return (180.f / PI) * fRadian;
}