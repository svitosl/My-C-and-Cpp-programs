#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() 
	{
	setlocale(LC_ALL, "Russian");
	
	int i = 0, j = 0, dlin = 0;
	float arr[dlin];
	
	printf("Введите длинну массива: ");
	scanf("%d", &dlin);
	
	if(dlin > 1)  /*проверка на длинну массива большую чем 1*/
	{
		for(i = 0; i < dlin; i++)
		{
		printf("Введите ячейку массива [%d]: ", i);
		scanf("%f", &arr[i]);
		}
		

	printf("Массив: \n");
		
		for(i = 0; i < dlin; i++)
		{
		printf("%f ", arr[i]); /*вывод массива*/
		}
		
		for(i = 1; i < dlin; i++) 
		{
			if(arr[i] <= arr[i - 1])  /*сравнение (i)-го и (i-1)-го элемента массива*/
			{
			printf("\nНе возрастающая последовательность");
			return 0;
			}
		}
		
	printf("\nВозрастающая последовательность");
	} 
	else 
	{
	printf("\nДлинна массива должна быть больше 1");
	}
	
	return 0;
}
