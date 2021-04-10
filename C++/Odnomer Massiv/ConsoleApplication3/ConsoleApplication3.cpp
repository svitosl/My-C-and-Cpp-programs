// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include <locale.h>

	using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int i, c=0, k, num1=1, num2=1;
	int *a = new int[5];
	int *b = new int[4];

	for (i = 0; i < 5; i++) 
	{
		k = c + 2;
		*(a + i) = k;
		num1 = k * num1;
		c = k;
	}

	k = 0;
	c = 0;

	for (i = 0; i < 4; i++) 
	{
		k = c + 3;
		*(b + i) = k;
		num2 = k * num2;
		c = k;
	}
	
	if (num1 < num2)
	{
		cout << "Наименьшее произведение элементов в массиве А:" << endl;
		for (i = 0; i < 5; i++)
		{
			cout << "A[" << i << "]=" << *(a + i) << endl;
		}
		cout << "Произведение всех элементов массива A: " << num1 << endl;

		cout << "" << endl;

		cout << "Наибольшее произведение элементов в массиве B:" << endl;
		for (i = 0; i < 4; i++)
		{
			cout << "B[" << i << "]=" << *(b + i) << endl;
		}
		cout << "Произведение всех элементов массива B: " << num2 << endl;
	}
	else
	{
		cout << "Наименьшее произведение элементов в массиве В:" << endl;
		for (i = 0; i < 4; i++)
		{
			cout << "B[" << i << "]=" << *(b + i) << endl;
		}
		cout << "Произведение всех элементов массива B: " << num2 << endl;

		cout << "" << endl;
		
		cout << "Наибольшее произведение элементов в массиве А:" << endl;
		for (i = 0; i < 5; i++)
		{
			cout << "A[" << i << "]=" << *(a + i) << endl;
		}
		cout << "Произведение всех элементов массива A: " << num1 << endl;

	}

	delete[] a;
	delete[] b;
    
	return 0;
}

