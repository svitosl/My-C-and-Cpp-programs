#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
int main()
{
	int *a;
	int i, j, n, m, x = 0, i1, num, c = 0, c1 = 0;
	char q;
	printf("Введите количество строк массива: ");
	scanf("%d", &n);
	printf("Введите количество столбцов массива: ");
	scanf("%d", &m);
	printf("Хотите вводить данные массива вручную? y/n: ");
	getchar(); // Освобождение ввода от символа переноса строки.
	q = getchar();
	a = (int*)malloc(n*m * sizeof(int));
	srand(time(NULL));// Использование текущей даты для генерации случайного значения.
	if(q == 'y')// Задание значений массива вручную, либо случайно от -10 до 10.
		for(i = 0; i<n; i++)
		{
			for(j = 0; j<m; j++)
			{
				printf("a[%d][%d] = ", i, j);
				scanf("%d", (a + i*m + j));
			}
		}
	else
		for(i = 0; i<n; i++)
		{
			for(j = 0; j<m; j++)
			{
				*(a + i*m + j) = (rand() % 21) - 10;
			}
		}
	printf("Единственные наименьшие элементы в своей строке и в своем столбце:\n");
	for(i = 0; i<n; i++)
	{
		num = *(a + i*m);
		for(j = 1; j<m; j++)// Поиск наименьшего значения в строке.
			if(*(a + i*m + j)<num)
			{
				x = j;
				num = *(a + i*m + j);
			}
		for(i1 = 0; i1<n; i1++)// Поиск меньших либо равных значений в столбце, который соответствует наименьшему значению в строке.
			if((i1!=i) && (*(a + i1*m + x)<=num))
				c++;
		for(j = x+1; j<m; j++)// Проверка существования второго или еще нескольких наименьших значений в данной строке. Из-за строгого сравнения в цикле поиска наименьшего значения имеет смысл сравнивать только последующие значения данной строки.
			if(*(a + i*m + j)==num)
				c++;
		if(c==0)// Если в строке или в столбце наименьшего значения присутствуют ему равные либо меньшие, то этот счетчик не равен нолю.
		{
			printf("a[%d][%d]\n", i, x);
			c1++;// Счетчик, который не равен нолю, если найдено хотя-бы одно единственное наименьшее значение в центре перекрестия любых строк и столбцов.
		}
//		printf("c = %d\n", c);// для отладки
		c = 0;
		x = 0;
	}
	if(!c1)
		printf("{нет таких елементов}\n");
	printf("  ");// Вывод значений массива в консоль для отладки
	for(i = -1; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if(!j && i!=-1)
				printf("%2d", i);
			if(i==-1)
				printf("%5d ", j);
			if(i>-1)
				printf("%5d ", *(a + i*m + j));
		}
		printf("\n");
	}
	free(a);
	if(c1)//Возвращение значения об успешности работы главной функции
		return 1;
	else
		return 0;
}
