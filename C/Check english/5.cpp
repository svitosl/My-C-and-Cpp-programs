#include <stdio.h>
#include <locale.h>

	int eng(char c) /*�������, ������������ 1, ���� ��� ������� �����*/
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

	
	int main() /*�������� �������*/
	{
	setlocale(LC_ALL, "Russian");
	char t;
	
	puts("������� ���� ������:");
	scanf ("%c", &t);
	
		if (eng(t)==1) /*����� ������� �������� ������� �����*/
		puts("������ ������ - ������� ����� ����������� ��������");
	
		else
		puts("������ ������ �� �������� ������� ������ ����������� ��������");
	
	return 0;
	}
