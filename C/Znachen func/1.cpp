#include <stdio.h>
#include <locale.h>

int main()
{
setlocale(LC_ALL, "Russian");
float y=0, x;

puts("Таблица значений функции у=-2,4х^2+5х-3 с шагом x=0,5:\n");
puts("|  X  |   Y  |");	
	for(x=-2; x<=2; x+=0.5)
	{
	y =-2.4*x*x+5*x-3;
	printf("|%4.1f | %5.1f|\n", x, y);
	}
return 0;
}
