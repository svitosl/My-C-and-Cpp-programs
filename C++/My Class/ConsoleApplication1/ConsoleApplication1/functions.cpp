/* functions.cpp */

#include "stdafx.h"
#include <math.h>
#include "class.h"
#include <iostream>

	using namespace std;

void cls::set(double X, double Y, double Z)	// ������� ������������� 
{
	x = X; y = Y; z = Z;
}

void cls::Run()	 // ������� �������
{
	b = pow(y, cbrt(abs(x)));
	rez = cos(pow(y, 3)) * abs(x - y) * (1 + (sin(pow(z, 2)) / sqrt(x + y)));
	rez /= exp(abs(x - y)) + x / 2;
	b += rez;
}

void cls::print()	// ������� ������ ����������� 
{
	cout.precision(4);
	cout << b << endl;
}