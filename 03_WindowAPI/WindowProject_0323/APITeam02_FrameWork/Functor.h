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

class CDeleteObj
{
public:
	template<typename T>
	void		operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};

class CDeleteMap
{
public:
	template<typename T>
	void		operator()(T& Temp)
	{
		if (Temp.second)
		{
			delete Temp.second;
			Temp.second = nullptr;
		}
	}
};

class CTagFinder
{
public:
	CTagFinder(const TCHAR* pTag)
		: m_pTag(pTag)
	{

	}

public:
	template<typename T>
	bool		operator()(T& Pair)
	{
		if (!lstrcmp(Pair.first, m_pTag))
			return true;

		return false;
	}

private:
	const TCHAR* m_pTag;
};