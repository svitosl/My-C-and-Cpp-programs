#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int in_circle(float ux, float uy)
	{
	int R = 1, rx = 0, ry = 0;
	
		if((pow((ux - rx), 2) + pow((uy - ry), 2)) < pow(R, 2))  // 0 - не попадает в окружность, 1 - попадает в окружность, -1
		{
		return -1;
		} 
		else if((pow((ux - rx), 2) + pow((uy - ry), 2)) < pow(R, 2)) 
		{
		return 1;
		} 
		else
		{
		return 0;
		}
	}

int overline(float ux, float uy, int x0, int y0, int x1, int y1)  // 0 - ниже отрезка, 1 - выше отрезка, -1 - на отрезке
	{
	
		if(((ux - x0) / (x1 - x0)) == ((uy - y0) / (y1 - y0))) 
		{
		return -1;
		} 
		else if(((ux - x0) / (x1 - x0)) < ((uy - y0) / (y1 - y0))) 
		{
		return 1;
		}
		else 
		{
		return 0;
		}
	}

int main(int argc, char *argv[]) {
	float ux, uy;
	printf("Enter x coord: ");
	scanf("%f", &ux);
	printf("Enter y coord: ");
	scanf("%f", &uy);
	
	if((in_circle(ux, uy) == 0 && overline(ux, uy, 0, 2, 2, 0) <= 0 && ux >= 0 && ux <= 2 && uy >= 0 && uy <= 2) ||
	(in_circle(ux, uy) == 0 && (overline(ux, uy, -2, 0, 0, -2) == 1 || overline(ux, uy, -2, 0, 0, -2) == -1) && ux >= -2 && ux <= 0 && uy >= -2 && uy <= 0) ||
	(in_circle(ux, uy) <= 0 && ux >= -1 && ux <= 0 && uy >= 0 && uy <= 1) ||
	(in_circle(ux, uy) <= 0 && ux >= 0 && ux <= 1 && uy >= -1 && uy <= 0)) {
		printf("\nOccurs");
	} else {
		printf("\nNOT occurs");
	}
	
	return 0;
}
