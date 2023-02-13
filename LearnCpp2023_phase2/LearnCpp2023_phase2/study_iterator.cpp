#include "stdafx.h"
#include <vector>
#include <list>

using namespace std;

int main() {

	vector<int> v1(5);
	for (int i = 0; i < 5; i++) v1[i] = i+4;

	list<int> l1(5);
	for (int i = 0; i < 5; i++) l1.push_back(i + 5);
	
	vector<int>::iterator viter_begin = v1.begin();
	list<int>::iterator liter_begin = l1.begin();

	cout << *(v1.begin()) << endl;
	cout << *(viter_begin) << endl;
}