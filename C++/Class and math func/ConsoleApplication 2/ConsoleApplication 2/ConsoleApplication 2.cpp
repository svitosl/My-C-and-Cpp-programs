// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include <math.h>
#include <iostream>

using namespace std;

class X
{
	friend void Run(X *p1);
	friend void print(X *p1);

	double x, y, z, b;
public:
	X(double X, double Y, double Z);
	~X();
};

X::X(double X, double Y, double Z)
{
	x = X; y = Y; z = Z;
	cout << "Конструктор вызван" << endl;
}

X::~X()
{
	cout << "Деструктор вызван" << endl;
}

void Run(X *p1)
{
	double rez;

	p1->b = pow(p1->y, cbrt(abs(p1->x)));
	rez = cos(pow(p1->y, 3)) * abs(p1->x - p1->y) * (1 + (sin(pow(p1->z, 2)) / sqrt(p1->x + p1->y)));
	rez /= exp(abs(p1->x - p1->y)) + p1->x / 2;
	p1->b += rez;
}

void print(X *p1)
{
	cout.precision(4);
	cout << p1->b << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");

	X *p1 = new X (6.251, 0.827, 25.001);
	Run(p1);
	print(p1);
	delete p1;
}