#include "stdafx.h"
using namespace std;

class String {
private:
	char* m_szData;
public:
	String();
	String(char* _szData);
	
	void Print();

	String&  operator =(String& ch) {
		for (int i = 0; i < strlen(ch.m_szData); i++) m_szData[i] = ch.m_szData[i];
		m_szData[strlen(m_szData)] = '\0';
		return *this;
	}

	String operator +(String& ch) {
		int iLength = strlen(m_szData) + strlen(ch.m_szData);
		String newString;
		newString.m_szData = new char[iLength];
		memcpy(newString.m_szData, m_szData, sizeof(m_szData) - 1);
		memcpy(newString.m_szData+strlen(m_szData), ch.m_szData, sizeof(ch.m_szData));
		newString.m_szData[iLength] = '\0';

		return newString;
	}

	bool operator ==(String& ch) {
		bool isSame(true);
		int iIndex(0);

		while (1) {
			// difference length
			if (strlen(m_szData) != strlen(ch.m_szData)) {
				isSame = false;
				break;
			}
			// diffrent char
			if (ch.m_szData[iIndex] != m_szData[iIndex]) {
				isSame = false;
				break;
			}
			if (ch.m_szData[iIndex] == '\0') break;
			iIndex++;
		}

		return isSame;
	}
};

int main() {
	//strcpy(=)
	{
		char chData[30] = "bye";
		char chSrc[30] = "hello";

		String str1 = { chSrc };
		String str2 = { chData };

		str1 = str2;
		str1.Print();	// bye
		str2.Print();	// bye
		cout << endl;
	}
	//strcat(+)
	{
		char chData[30] = "hello";
		char chSrc[30] = "ddd";
		String str1 = { chData };
		String str2 = { chSrc };
		String str3 = str1 + str2;
		str3.Print();	// bye
		cout << endl;
	}
	//strcmp(==)
	{
		char chData[30] = "hello";
		char chSrc[30] = "aaaaa";
		String str1 = { chData };
		String str2 = { chSrc };

		if (str1 == str2) {
			cout << "Same" << endl;
		}
		else cout << "Different" << endl;
	}
}

String::String()
{
}

String::String(char* _szData)
{
	m_szData = _szData;
}

void String::Print()
{
	cout << m_szData << endl;
}
