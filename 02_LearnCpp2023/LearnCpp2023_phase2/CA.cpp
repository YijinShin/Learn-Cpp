#include "stdafx.h"
#include "CA.h"
#include "CB.h"

using namespace std;

void CA::Init()
{
	m_cb = new CB;
}

void CA::Display()
{
	cout << "CA" << endl;
}
