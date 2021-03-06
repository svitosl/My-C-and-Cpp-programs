// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "fstream"
#include <locale.h>
#include <string>
#include <iostream>
	
	using namespace std;

class Main
{
public:
	virtual void print() = 0;
};

class String
{
protected:
	string str1, str2, str3, str4, str5, str6, str_tmp;
	int index = 0;
	char number;
};

class Object : public Main, public String
{
public:
friend void Run(Object &);
	Object()
	{
	ifstream Shablon;
	Shablon.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
	Shablon.open("prg_in.txt", ios_base::in);
	Shablon >> str1 >> str2 >> str3 >> str4 >> str5 >> str6;
	Shablon.close();
	cout << "Данные считаны из файла prg_in.txt\n"<< endl;
	}
	catch (const ifstream::failure & ex)
	{
		cout << "Ошибка открытия файла prg_in.txt" << endl;
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		system("pause");
	}
	}

	~Object()
	{
		cout << "Деструктор вызван" << endl;
	}

void print()
	{
	system("cls");
	cout << "Колличество добавленных записей: " << index << endl;
	cout << "Данные поля 1: " << str1 << endl;
	cout << "Данные поля 2: " << str2 << endl;
	cout << "Данные поля 3: " << str3 << endl;
	cout << "Данные поля 4: " << str4 << endl;
	cout << "Данные поля 5: " << str5 << endl;
	cout << "Данные поля 6: " << str6 << "\n" << endl;
	}
};

void Run(Object &str)
{
	ofstream Shablon("prg_out.txt", ios_base::app);
	setlocale(LC_ALL, "ru");
	do
	{
		cout << "1. Добавить строку в файл" << endl;
		cout << "2. Просмотр текущего состояния объектов" << endl;
		cout << "3. Выход \n" << endl;
		cout << "Номер команды > ";
		cin >> str.number;
		switch (str.number)
		{
			//-----------------------------------------------
		case '1':
			str.index++;
			Shablon << "------------New book " << str.index << "------------\n";
			cout << str.str1 << " ";
			getchar();
			getline(cin, str.str_tmp);
			Shablon << str.str1 << " " << str.str_tmp << ",\n";
			cout << str.str2 << " ";
			getline(cin, str.str_tmp);
			Shablon << str.str2 << " " << str.str_tmp << ",\n";
			cout << str.str3 << " ";
			getline(cin, str.str_tmp);
			Shablon << str.str3 << " " << str.str_tmp << ",\n";;
			cout << str.str4 << " ";
			getline(cin, str.str_tmp);
			Shablon << str.str4 << " " << str.str_tmp << ",\n";
			cout << str.str5 << " ";
			getline(cin, str.str_tmp);
			Shablon << str.str5 << " " << str.str_tmp << ",\n";
			cout << str.str6 << " ";
			getline(cin, str.str_tmp);
			Shablon << str.str6 << " " << str.str_tmp << "\n";
			system("cls");
			cout << "Данные записаны в файл prg_in.txt\n\n" << endl;
			break;
			//-----------------------------------------------
		case '2':
			str.print();
			break;
		case '3':
			break;
		}
	} while (str.number != '3');
	Shablon.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	Object *p1 = new Object;
	Run(*p1);
	delete p1;

    return 0;
}

