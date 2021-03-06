/* main.cpp */

#include "stdafx.h"
#include <locale.h>
#include "class.h"
#include <iostream>

	using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Прямой вызов:" << endl;
	cls Obj;
	Obj.set(6.251, 0.827, 25.001);
	Obj.Run();
	Obj.print();

	cout << "Косвенный вызов:" << endl;
	cls *p1 = &Obj;
	p1->set(6.251, 0.827, 25.001);
	p1->Run();
	p1->print();

	cout << "Динамическое выделение памяти:" << endl;
	cls *p2 = new cls;
	p2->set(6.251, 0.827, 25.001);
	p2->Run();
	p2->print();

	delete p2;	// Удаление динамически выделенного объекта
}