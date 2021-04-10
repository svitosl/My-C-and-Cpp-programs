#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
	using namespace std;

struct elem;
using pt = elem*;

struct elem
{
	short int info;
	pt next;
};

pt getprelastel(pt list)
{
	pt nextel;
	if (list != nullptr)
	{
		nextel = list;
		do
		{
			list = nextel;
			if (list->next != nullptr)
				nextel = list->next;
		} while (nextel->next != nullptr);
		return list;
	}
	else
		return nullptr;
}

pt getlastel(pt list)
{
	if (list != nullptr)
	{
		while (list->next != nullptr)
			list = list->next;
		return list;
	}
	else
		return nullptr;
}

pt searchel(pt list, short int info)
{
	if (list != nullptr)
	{
		while ((list->next != nullptr) && (list->info != info))
			list = list->next;
		if (list->info != info)
			return nullptr;
		else
			return list;
	}
	else
		return nullptr;
}

pt searchpreel(pt list, short int info)
{
	pt nextel;
	if (list != nullptr)
	{
		nextel = list;
		do
		{
			list = nextel;
			if (list->next != nullptr)
				nextel = list->next;
		} while ((nextel->next != nullptr) && (nextel->info != info));
		if ((nextel->info != info) || (nextel == list))
			return nullptr;
		else
			return list;
	}
	else
		return nullptr;
}

short int getelem(string elname)
{
	short int ret;
	cout << "Введите " << elname << " : ";
	cin >> ret;
	return ret;
}

void addtobegin(pt &list, short int info)
{
	pt newelem;
	newelem = new elem;
	newelem->info = info;
	newelem->next = list;
	list = newelem;
}

void addafter(pt listel, short int info)
{
	pt newelem;
	if (listel != nullptr)
	{
		newelem = new elem;
		newelem->info = info;
		newelem->next = listel->next;
		listel->next = newelem;
	}
}

void addtoend(pt &list, short int info)
{
	if (list == nullptr)
		addtobegin(list, info);
	else
		addafter(getlastel(list), info);
}

void addbefore(pt listel, short int info)
{
	pt newelem;
	if (listel != nullptr)
	{
		newelem = new elem;
		newelem->info = listel->info;
		listel->info = info;
		newelem->next = listel->next;
		listel->next = newelem;
	}
}

void delfirstel(pt &list)
{
	pt temp;
	if (list != nullptr)
	{
		temp = list;
		list = list->next;
		delete temp;
	}
}

void dellasttel(pt &list)
{
	pt temp;
	if (list != nullptr)
		if (list->next == nullptr)
			delfirstel(list);
		else
		{
			temp = getprelastel(list);
			delete temp->next;
			temp->next = nullptr;
		}
}

void delel(pt &list, pt el)
{
	pt temp;
	if ((list != nullptr) && (el != nullptr))
	{
		if (el->next == nullptr)
			if (list->next == nullptr)
				delfirstel(list);
			else
				dellasttel(list);
		else
		{
			temp = el->next;
			el->info = temp->info;
			el->next = temp->next;
			delete temp;
		}
	}
}

void delbefore(pt &list, short int info)
{
	pt temp;
	if (list != nullptr)
	{
		temp = searchpreel(list, info);
		delel(list, temp);
	}
}

void delafter(pt &list, short int info)
{
	pt temp;
	if (list != nullptr)
	{
		temp = searchel(list, info);
		temp = temp->next;
		delel(list, temp);
	}
}

void printlist(pt list)
{
	system("cls");
	if (list == nullptr)
		cout << "Список пуст!";
	else
		while (list != nullptr)
		{
			cout << list->info;
			list = list->next;
			if (list != nullptr)
				cout << ",";
			else
				cout << ".";
		}
	_getch();
}

void checkel(pt list, short int info)
{
	if (searchel(list, info) != nullptr)
		cout << "Элемент" << info << " существует." << endl;
	else
		cout << "Элемент" << info << " не существует." << endl;
	_getch();
}

void showmenu()
{
	system("cls");
	cout << "1) Добавить элемент в начало списка" << endl;
	cout << "2) Добавить элемент в конец списка" << endl;
	cout << "3) Распечатать список" << endl;
	cout << "4) Удалить первый элемент из списка" << endl;
	cout << "5) Удалить последний элемент из списка" << endl;
	cout << "6) Найти, существует ли указанный элемент в списке" << endl;
	cout << "7) Удалить указанный элемент из списка" << endl;
	cout << "8) Добавить элемент после указанного" << endl;
	cout << "9) Добавить элемент перед указанным" << endl;
	cout << "10) Удалить после указанного" << endl;
	cout << "11) Удалить перед указанным" << endl;
	cout << "12) Выход из программы" << endl;
	cout << "\n";
	cout << " Ваш выбор : ";
}

pt root;
short int selection;

int main()
{ setlocale(LC_ALL, "rus");
	root = nullptr;	
	do
	{
		showmenu();
		cin >> selection;
		cout << "\n";
		switch (selection)
		{
				case 1: addtobegin(root, getelem("значение элемента")); break;
				case 2: addtoend(root, getelem("значение элемента")); break;
				case 3: printlist(root); break;
				case 4: delfirstel(root); break;
				case 5: dellasttel(root); break;
				case 6: checkel(root, getelem("значение искомого элемента")); break;
				case 7: delel(root, searchel(root, getelem("значение элемента для удаления"))); break;
				case 8: addafter(searchel(root, getelem("значение искомого элемента")), getelem("значение элемента для добавления")); break;
				case 9: addbefore(searchel(root, getelem("значение искомого элемента")), getelem("значение элемента для добавления")); break;
				case 10: delafter(root, getelem("значение искомого элемента")); break;
				case 11: delbefore(root, getelem("значение искомого элемента")); break;
				case 12: system("cls"); break;
		}

	} while (selection != 12);
}