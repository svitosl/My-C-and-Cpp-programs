#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
	using namespace std;

struct top	// Вершины
{
	int top_index = 0;
	string label;
	bool visited;
} obj_top;

struct arc	// Дуги
{
	int arc_index = 0;
	int out, in;
} obj_arc;

vector <top> mas_top;
vector <arc> mas_arc;
int visited_count;

void mod_dfs(int top_index)
{
	if (!mas_top[top_index].visited)
	{
		mas_top[top_index].visited = true;
		visited_count++;
		for (int i = 0; i < mas_arc.size(); i++)
		{
			if (mas_arc[i].out == top_index+1 && mas_top[mas_arc[i].in-1].visited == false)
				mod_dfs(mas_arc[i].in-1);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	char number;
	string tmp_OUT, tmp_IN;

	do
	{
		system("cls");
		cout << "Выберите действие:" << endl;
		cout << "1. Построить граф (добавить дугу)" << endl;
		cout << "2. Вывести список вершин и дуг" << endl;
		cout << "3. Найти корень" << endl;
		cout << "4. Удалить построенный граф" << endl;
		cout << "0. Выйти\n\n";
		cout << "Номер команды > ";
		cin >> number;
		switch (number)
		{
		case '1':
			cout << "Введите метку вершины, из которой исходит дуга\n(при отсутствии вершины c указанной меткой она будет добавлена,\nв противном случае будет выбрана вершина с указанной меткой):" << endl;
			cin >> tmp_OUT;
			cout << "Введите метку вершины, в которую входит дуга\n(при отсутствии вершины c указанной меткой она будет добавлена,\nв противном случае будет выбрана вершина с указанной меткой):" << endl;
			cin >> tmp_IN;

			mas_arc.push_back(obj_arc);
			mas_arc[(mas_arc.size()-1)].arc_index = mas_arc.size();
			if (!mas_top.empty())
			{
				bool flag_O = 0;
				bool flag_I = 0;
				for (int i = 0; i < mas_top.size(); i++)
				{
					if (mas_top[i].label == tmp_OUT)
					{
						mas_arc[(mas_arc.size()-1)].out = mas_top[i].top_index;
						flag_O = 1;
					}

					if (mas_top[i].label == tmp_IN)
					{
						mas_arc[(mas_arc.size()-1)].in = mas_top[i].top_index;
						flag_I = 1;
					}
				}

				if (!flag_O)
				{
					mas_top.push_back(obj_top);
					mas_top[(mas_top.size()-1)].label = tmp_OUT;
					mas_top[(mas_top.size()-1)].top_index = mas_top.size();
					mas_arc[(mas_arc.size()-1)].out = mas_top.size();
				}

				if (!flag_I)
				{
					mas_top.push_back(obj_top);
					mas_top[(mas_top.size()-1)].label = tmp_IN;
					mas_top[(mas_top.size()-1)].top_index = mas_top.size();
					mas_arc[(mas_arc.size()-1)].in = mas_top.size();
				}
			}
			else
			{
				mas_top.push_back(obj_top);
				mas_top[(mas_top.size()-1)].label = tmp_OUT;
				mas_top[(mas_top.size()-1)].top_index = mas_top.size();
				mas_top.push_back(obj_top);
				mas_top[(mas_top.size()-1)].label = tmp_IN;
				mas_top[(mas_top.size()-1)].top_index = mas_top.size();
				mas_arc[(mas_arc.size()-1)].out = 1;
				mas_arc[(mas_arc.size()-1)].in = 2;
			}
			break;
			//-----------------------------------------------
		case '2':
			if (!mas_top.empty())
			{
				cout << "Список вершин: (top: | index | label | visited |)" << endl;
				for (int i = 0; i < mas_top.size(); i++)
				{
					cout << "| " << mas_top[i].top_index << " | " << mas_top[i].label << " | " << mas_top[i].visited << " |\n";
				}
				cout << "\nСписок дуг: (arc: | index | out | in |)" << endl;
				for (int i = 0; i < mas_arc.size(); i++)
				{
					cout << "| " << mas_arc[i].arc_index << " | " << mas_arc[i].out << " | " << mas_arc[i].in << " |\n";
				}
			}
			else cout << "Граф не введен." << endl;
			break;
			//-----------------------------------------------
		case '3':
			if (!mas_top.empty())
			{
				bool exit = false;
				for (int i = 1; i <= mas_top.size(); i++)
				{
					visited_count = 0;
					for (int j = 0; j < mas_top.size(); j++)
					{
						mas_top[j].visited = false;
					}
					mod_dfs(i - 1);

					if (visited_count == mas_top.size())
					{
						cout << "Корень орграфа - вершина " << mas_top[i-1].label << " (index: " << mas_top[i-1].top_index << ")." << endl;
						exit = true;
						break;
					}
				}
				if(exit) break;
				cout << "Корень орграфа не найден." << endl;
			}
			else cout << "Граф не введен." << endl;
			break;
			//-----------------------------------------------
		case '4':
			mas_top.clear();
			mas_arc.clear();
			cout << "Граф очищен." << endl;
			break;
			//-----------------------------------------------
		case '0': break;
			//-----------------------------------------------
		default:
			cout << endl << "Команда не определена\n";
			break;
			//-----------------------------------------------
		}
		system("pause");
	} while (number != '0');

}