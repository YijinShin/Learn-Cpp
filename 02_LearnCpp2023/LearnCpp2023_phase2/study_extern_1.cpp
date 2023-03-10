#include "stdafx.h"
using namespace std;

extern int i_global;

int main() {
	i_global+=10;
	cout << i_global << endl;


	{

		static int iii;
	}

	{

		static int iii;
	}
	//iii++;
}
