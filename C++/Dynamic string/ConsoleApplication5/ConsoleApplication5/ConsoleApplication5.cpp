// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class String
{
	bool flag;
	char *S1, *S2;
	int arr_size, i, j = 0;

	public:
	String() {}
	String(int size);
	String(String &Mass_1);
	~String();
	void Set();
	void SetS2_1(String &Mass_2);
	void SetS2_0(String &Mass_1);
	void Run(String &Mass_1);
	bool Get_Flag();
	String& operator=(String &Mass);
	void Print(String &Mass, String &Mass_2);

};
/*--------------------------------------------*/
String::String(int size)
{
	arr_size = size;
	S1 = new char[arr_size];
}

String::String(String &Mass_1)
{
	arr_size = strlen(Mass_1.S1) / 2 + 1;
	S1 = new char[arr_size];
}

String::~String()
{
	cout << "< Вызван деструктор >" << endl;
}

void String::Set()
{
	cout << "Введите строку (0-255) и нажмите <Enter>:" << endl;
	cin.getline(S1, 255);

	if (strlen(S1) % 2 == 0)
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
}

void String::SetS2_1(String &Mass_2)
{
	S2 = new char[Mass_2.arr_size];
}

void String::SetS2_0(String &Mass_1)
{
	S2 = new char[strlen(Mass_1.S1)];
}

void String::Run(String &Mass_1)
{
	for (i = 0; i < arr_size; i++)
	{
		S1[i] = Mass_1.S1[j];
		j += 2;
	}
	S1[i + 1] = '\0';
}

bool String::Get_Flag()
{
	return flag;
}

String& String::operator=(String &Mass)
{
	cout << "< Вызвана перегрузка = >" << endl;
	strcpy(S2, Mass.S1);
	return *this;
}

void String::Print(String &Mass, String &Mass_2)
{
	ofstream fout("prg_out.txt");
	if (Mass.Get_Flag() == true)
	{
		fout << "Строка является четной" << endl;
	}
	else
	{
		fout << "Строка нечетная" << endl;
	}
	fout << "\nДлинна исходной строки L: " << strlen(Mass.S1) << "\nИсходная строка S1: " << Mass.S1 << "\nПреобразованная строка S2: " << Mass_2.S2 << endl;
	fout.close();
	cout << "Результаты работы программы выведены в файл prg_out.txt\n";
	delete[] Mass.S1;
}
/*--------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "rus");

	/*------------Прямой вызов------------*/
	String Mass_1(256);
	Mass_1.Set();

	if (Mass_1.Get_Flag() == true)
	{
		String Mass_2(Mass_1);
		Mass_2.Run(Mass_1);
		String Mass_3;
		Mass_3.SetS2_1(Mass_2);
		Mass_3 = Mass_2;
		Mass_3.Print(Mass_1, Mass_3);
	}
	else
	{
		String Mass_3;
		Mass_3.SetS2_0(Mass_1);
		Mass_3 = Mass_1;
		Mass_3.Print(Mass_1, Mass_3);
	}

	/*------------Косвенный вызов------------*/
	String *p1 = new String(256);
	p1->Set();

	if (p1->Get_Flag() == true)
	{
		String *p2 = new String(*p1);
		p2->Run(*p1);
		String *p3 = new String;
		p3->SetS2_1(*p2);
		*p3 = *p2;
		p3->Print(*p1, *p3);
		delete p1;
		delete p2;
		delete p3;
	}
	else
	{
		String *p3 = new String;
		p3->SetS2_0(*p1);
		*p3 = *p1;
		p3->Print(*p1, *p3);
		delete p1;
		delete p3;
	}

    return 0;
}

