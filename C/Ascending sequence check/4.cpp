#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() 
	{
	setlocale(LC_ALL, "Russian");
	
	int i = 0, j = 0, dlin = 0;
	float arr[dlin];
	
	printf("������� ������ �������: ");
	scanf("%d", &dlin);
	
	if(dlin > 1)  /*�������� �� ������ ������� ������� ��� 1*/
	{
		for(i = 0; i < dlin; i++)
		{
		printf("������� ������ ������� [%d]: ", i);
		scanf("%f", &arr[i]);
		}
		

	printf("������: \n");
		
		for(i = 0; i < dlin; i++)
		{
		printf("%f ", arr[i]); /*����� �������*/
		}
		
		for(i = 1; i < dlin; i++) 
		{
			if(arr[i] <= arr[i - 1])  /*��������� (i)-�� � (i-1)-�� �������� �������*/
			{
			printf("\n�� ������������ ������������������");
			return 0;
			}
		}
		
	printf("\n������������ ������������������");
	} 
	else 
	{
	printf("\n������ ������� ������ ���� ������ 1");
	}
	
	return 0;
}
