#include <stdio.h>
#include <locale.h>

	int main()
	{
	setlocale(LC_ALL, "Russian");
	int c = 0;	/*����, ������������ �������������� ������ � ������������������� ������*/
	char s;
	
	puts("������� �����:");
	s=getchar();	/*������������ �� 1-� �����, ��������� � ����������*/

		if((s=='-')||(s>='0'&&s<='9')||(s>='A'&&s<='F')||(s>='a'&&s<='f'))	/*�������� 1-�� ����� �� ���������� �� ��������*/
		{
			while(((s = getchar())!='\n'))	/*�������� 2-�� � ����������� ����� �� �������� �� ������� 'Enter (\n)'*/
			
				if(!((s>='0'&&s<='9')||(s>='A'&&s<='F')||(s>='a'&&s<='f')))
				c++;
		}
		else
		c++;
			
			if(c>=1)
			puts("������ ����� �� �����������������.");
			
			else
			puts("������ ����� - �����������������.");
return 0;
}