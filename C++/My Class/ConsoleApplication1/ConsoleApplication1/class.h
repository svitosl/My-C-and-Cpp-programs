/* class.h */

#pragma once	// ������ �� �������� ����������� ������������� �����
#include "stdafx.h"
#include <iostream>

	using namespace std;

class cls
{
	double x, y, z, rez, b;		// ���������� ������

public:
	// ������� ������
	void set(double X, double Y, double Z);	// ������� ������������� 
	void Run();	 // ������� �������
	void print();	// ������� ������ ����������� 
};