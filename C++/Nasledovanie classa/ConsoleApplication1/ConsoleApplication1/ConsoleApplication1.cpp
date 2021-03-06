// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "locale.h"
#include <iostream>

	using namespace std;

	class X
	{
	public:
		int x1, x2, y, res;

	X() {}

	X(int X1, int X2)
	{
		x1 = X1; x2 = X2;
	}

	~X()
	{
		cout << "Деструктор вызван" <<endl;
	}

	virtual void GetParams()
	{
		cout << "----------Вызвана функция класса X----------" << endl;
		cout << "x1 = " << x1 << "; x2 = " << x2 << "; y = " << y << endl;
	}

	virtual void Run()
	{
		cout << "----------Вызвана функция класса X----------" << endl;
		res = x1 * x2 + y;
		cout << "Результат x1 * x2 + y: " << res << endl;
	}

	virtual void Set()
	{
		cout << "----------Вызвана функция класса X----------" << endl;
		cout << "Введите x1: " << endl;
		cin >> x1;
		cout << "Введите x2: " << endl;
		cin >> x2;
		cout << "Введите y: " << endl;
		cin >> y;
	}
};

class Y : public X
{
	public:
		Y(int X1, int X2, int Y) : X(X1, X2)
	{
			y = Y;
	}

	void GetParams()
	{
		cout << "----------Вызвана функция класса Y----------" << endl;
		cout << "x1 = " << x1 << "; x2 = " << x2 << "; y = " << y << endl;
	}

	void Run()
	{
		cout << "----------Вызвана функция класса Y----------" << endl;
		res = x1 * x2 + y;
		cout << "Результат x1 * x2 + y: " << res << endl;
	}

	void Set()
	{
		cout << "----------Вызвана функция класса Y----------" << endl;
		cout << "Введите x1: " << endl;
		cin >> x1;
		cout << "Введите x2: " << endl;
		cin >> x2;
		cout << "Введите y: " << endl;
		cin >> y;
	}

};


int main()
{
	setlocale (LC_ALL, "rus");
	int X1, X2, Y1;
	cout << "Введите x1: " << endl;
	cin >> X1;
	cout << "Введите x2: " << endl;
	cin >> X2;
	cout << "Введите y: " << endl;
	cin >> Y1;

	X par_1;
	Y par_2(X1, X2, Y1);
	X *px = &par_2;
	px->GetParams();
	px->Run();
	X *px1 = &par_1;
	px1->Set();
	px1->GetParams();
	px1->Run();
	delete px;
	delete px1;

    return 0;
}

