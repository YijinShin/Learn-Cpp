#pragma once

template <typename T>
void	Safe_Delete(T& temp) {
	if (temp) {
		delete temp;
		temp = nullptr;
	}
}

template <typename T>
void	Safe_Array_Delete(T& temp) {
	if (temp) {
		delete[] temp;
		temp = nullptr;
	}
}

// TODO : 프로그램에 필요한 코드를 추가하세요