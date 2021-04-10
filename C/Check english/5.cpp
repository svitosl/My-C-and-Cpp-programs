#include <stdio.h>
#include <locale.h>

	int eng(char c) /*функция, возвращающая 1, если это гласная буква*/
	{
	int i;
	char z[10]={'A','E','I','O','U','a','e','i','o','u',};
	
		for(i=0; i<10; i++)
		{
		if(c==z[i])
		return 1;
		}
		
	return 0;
	}

	
	int main() /*основная функция*/
	{
	setlocale(LC_ALL, "Russian");
	char t;
	
	puts("Введите один символ:");
	scanf ("%c", &t);
	
		if (eng(t)==1) /*вызов функции проверки гласной буквы*/
		puts("Данный символ - гласная буква английского алфавита");
	
		else
		puts("Данный символ не является гласной буквой английского алфавита");
	
	return 0;
	}
