// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <typeinfo>
#include "locale.h"
#include <ctime>
#include <iostream>
	
	using namespace std;

template <typename T>
class Array
{
int i, j=1, n;
T *arr;

public:
	Array(int N);
	~Array();
	void Init();
	void Print();
};
/*-------------------------------------------*/
template <typename T> Array<T>::Array(int N)
{
	i = NULL;
	n = N;
}

template <typename T> Array<T>::~Array()
{
	cout << "<Деструктор вызван>" << endl;
	delete[] arr;
}

template <typename T> void Array<T>::Init()
{
	arr = new T[n];

	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		if (typeid(int) == typeid(T))
		{
			*(arr + i) = rand() % 999;
		}

		if (typeid(float) == typeid(T))
		{
			*(arr + i) = rand() / 33.3;
		}

		if (typeid(unsigned char) == typeid(T))
		{
			*(arr + i) = rand() % 255;
		}
	}
	cout << "\nИсходный массив типа " << typeid(T).name() << ":" << endl;
}

template <typename T> void Array<T>::Print()
{
	for (i = 0; i < n; i++)
	{
		cout << "| ";
		cout << *(arr + i) << " | ";
	}

	if (typeid(T) != typeid(unsigned char))
	{
		cout << "\nМетод просмотра значений массива (a1 + a2), (a2 + a3), (a(N-1) + a(N)):" << endl;
		for (i = 0; i < n - 1; i++)
		{
			cout << "| ";
			cout << *(arr + i) + *(arr + (i + 1)) << " | ";
		}
	}

	if (typeid(unsigned char) == typeid(T))
	{
		cout << "\nМетод просмотра значений массива по индексам a([0]+[1]), a([1]+[2]), a(([N]-[1])+[N]):" << endl;
		for (i = 0; i < n / 2; i++)
		{
			cout << "| ";
			cout << *(arr + j) << " | ";
			j += 2;
		}
	}
	cout << "\n" << endl;
}

int SetN()
{
	int N;
	cout << "Введите длинну массива N:" << endl;
	cin >> N;
	return N;
}
/*-------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "rus");
	int N = SetN();
	Array <int> arr_int(N);
	arr_int.Init();
	arr_int.Print();
	Array <float> arr_float(N);
	arr_float.Init();
	arr_float.Print();
	Array <unsigned char> arr_char(N);
	arr_char.Init();
	arr_char.Print();

    return 0;
}

