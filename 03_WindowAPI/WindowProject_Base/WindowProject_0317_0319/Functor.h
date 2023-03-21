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

// TODO : ���α׷��� �ʿ��� �ڵ带 �߰��ϼ���