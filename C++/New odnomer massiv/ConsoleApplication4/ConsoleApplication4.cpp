// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include "iostream"
#include <locale.h>

	using namespace std;

 int Mass(int *a, int m) 
 {
	int zn;
	zn = *(a + m);

	return zn;
 }

int main()
{
	setlocale(LC_ALL, "Russian");

	int i, j, k=0, l, m=0, n, t, u=0, num, col=0;
	
	int *a = new int[10]; // Выделение памяти под массивы a и b.
	int **b = NULL;
	b = new int*[2];

	cout << "Исходный одномерный массив данных A: \n"; // Заполнение и вывод на печать исходного массива.
	for (i = 0; i < 10; i++)
	{
		k++;
		*(a + i) = k;
		cout << *(a + i) << "  ";
	}
	cout << "\n";

	cout << "Введите значение t: ";
	cin >> t;

	for (i = 0; i < 10; i++) // Подсчет колличества величин в массиве > t
	{
	l = Mass(a, i);
		if (l > t)
			col++;
	}
	n = (col / 2 + 1); // Колличество столбцов динамического массива в 2 раза меньше колличества колличества значений > t  

	for (i = 0; i < 2; i++) // Выделение памяти под n указателей
	{
		b[i] = new int[n];
	}

	cout << "Сформированный динамический массив B (0=NULL): \n";
	t++;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (u < col) // Если значение проходов больше col, то в массив записывается NULL
			{
				num = Mass(a, m);
				if (num > t)
				{
					*(*(b + i) + j) = num;
					m++;
				}
				else
				{
					while (num < t) // В начало массива записывается значение > t
					{
						m++;
						num = Mass(a, m);
					}

					*(*(b + i) + j) = num;
					m++;
				}
			u++;
			}
			else
			{
				*(*(b + i) + j) = NULL;
				m++;
			}
		cout << *(*(b + i) + j) << "  ";
		}
	cout << "\n";
	}
	cout << "Размерность массива А[" << i << ";" << j << "]\n";

	delete[] a; // Очистка памяти от массивов a, b
	for (i = 0; i < 2; i++)
	{
		delete[] b[i];
	}
	delete[] b;

	return 0;
}

