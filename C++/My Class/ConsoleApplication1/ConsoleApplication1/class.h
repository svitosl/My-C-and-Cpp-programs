/* class.h */

#pragma once	// Защита от двойного подключения заголовочного файла
#include "stdafx.h"
#include <iostream>

	using namespace std;

class cls
{
	double x, y, z, rez, b;		// Переменные класса

public:
	// Функции класса
	void set(double X, double Y, double Z);	// Функция инициализации 
	void Run();	 // Функция запуска
	void print();	// Функция вывода результатов 
};