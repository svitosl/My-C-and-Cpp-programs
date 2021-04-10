#include "pch.h"
#include <string>
#include <conio.h>
#include <iostream>

	using namespace std;

const string a1[21] =
{ "ноль ","один ","два ","три ","четыре ","пять ","шесть ","семь ",
 "восемь ","девять ","десять ","одиннадцать ","двеннадцать ",
 "тринадцать ","четырнадцать ","пятнадцать ","шестнадцать ",
 "семьнадцать ","восемнадцать ","девятнадцать ","двадцать " };

const string a1_1[21] =
{ "ноль ","одна ","две ","три ","четыре ","пять ","шесть ","семь ",
"восемь ","девять ","десять ","одиннадцать ","двеннадцать ",
"тринадцать ","четырнадцать ","пятнадцать ","шестнадцать ",
"семьнадцать ","восемнадцать ","девятнадцать ","двадцать " };

const string a2[10] =
{ "","","двадцать ","тридцать ","сорок ","пятьдесят ","шестдесят ",
 "семьдесят ","восемьдесят ","девяносто " };

const string a3[10] =
{ "","сто ","двести ","триста ","четыреста ","пятьсот ",
"шестьсот ","семьсот ","восемьсот ","девятсот " };

string summa, s, R, K;

string odin(string c, bool f)
{
	unsigned short int b;
	b = stoi(c);
	if (f) 
		return a1_1[b];
	else 
		return a1[b];
}

string dva(string c, bool f)
{
	unsigned short int b, bl;
	string dva2;
	if (c[0] == '0')
		if (f) 
			return odin(string(1, c[1]), true); 
		else 
			return odin(string(1, c[1]), false);
	else
	{
		b = stoi(c);
		if((b>=10) && (b<=20))
			return a1[b]; 
		else
		{
			bl = atoi(string({(char)c[0]}).c_str());
			dva2 = a2[bl];
			if ((b != 30) && (b != 40) && (b != 50) && (b != 60)
				&& (b != 70) && (b != 80) & (b != 90))
				if (f) 
					dva2 = dva2 + odin(string(1, c[1]), true); 
				else
					dva2 = dva2 + odin(string(1, c[1]), false);
			return dva2;
		}
	}

}

string tree(string c, bool f)
{
	unsigned short int b, bl;
	string tree2;
	if (c[0] == '0')
		return dva(string(1, c[1]) + string(1, c[2]), false);
	else
	{
		b = stoi(c);
		bl = atoi(string({ (char)c[0] }).c_str());
		tree2 = a3[bl];
		if ((b != 100) && (b != 200) && (b != 300) && (b != 400) && (b != 500)
			&& (b != 600) && (b != 700) && (b != 800) && (b != 900))
			if (f)
				tree2 = tree2 + dva(string(1, c[1]) + string(1, c[2]), true);
			else
				tree2 = tree2 + dva(string(1, c[1]) + string(1, c[2]), false);
		return tree2;
	}
}

void cut()
{
	bool flag;
	unsigned short int i;

	flag = false;
	for (i = 0; i < s.length(); i++)
	{
		if (flag)
			K = K + s[i];
		if ((s[i] != '.') && (s[i] != ',') && (flag == false))
			R = R + s[i]; 
		else
			flag = true;
	}
}

void calc()
{
	const int rbl[8] = 
	{500,200,100,50,10,5,2,1};

	const int kp[4] = 
	{50,10,5,1};

	unsigned short int b;
	int tmp, i;

	i = 0;
	b = stoi(R);

	if (b != 0)
	{
		while (b / rbl[i] == 0)
			i++;

		while (b / rbl[i] != 0)
		{
			tmp = b / rbl[i];
			cout << rbl[i] << " руб.(x" << tmp << ") ";
			tmp = tmp * rbl[i];
			b = b - tmp;
			i++;

			if (b != 0)
				while (b / rbl[i] == 0)
					i++;
		}
	}
	else
		cout << "0 руб.";
	cout << "\n";

	if (K != "")
	{
		i = 0;
		b = stoi(K);

		if (b != 0)
		{
			while (b / kp[i] == 0)
				i++;

			while (b / kp[i] != 0)
			{
				tmp = b / kp[i];
				cout << kp[i] << " коп.(x" << tmp << ") ";
				tmp = tmp * kp[i];
				b = b - tmp;
				i++;

				if (b != 0)
					while (b / kp[i] == 0)
						i++;
			}
		}
		else
			cout << "0 коп.";
		cout << "\n";
	}
}

void rub()
{
	unsigned short int b, word;
	if (R.length() > 1)
	{
		b = atoi((string({(char)R[R.length()-2]})+string({(char)R[R.length()-1]})).c_str());
		if ((b >= 11) && (b <= 15))
			cout << "рублей ";
		else
		{
			b = atoi(string({(char)R[R.length()-1]}).c_str());
			if (b==1)
				cout << "рубль ";
			if ((b>1) && (b<5))
				cout << "рубля ";
			if (((b>=5) && (b<=9)) || (b==0))
				cout << "рублей ";
		}
	}
	else
	{
		b = atoi(string({(char)R[R.length()-1]}).c_str());
		if (b == 1)
			cout << "рубль ";
		if ((b > 1) && (b < 5))
			cout << "рубля ";
		if (((b >= 5) && (b <= 9)) || (b == 0))
			cout << "рублей ";
	}
}

void kop()
{
	unsigned short int b, word;
	if (K.length() > 1)
	{
		b=atoi((string({(char)K[K.length()-2]})+string({(char)K[K.length()-1]})).c_str());
		if ((b >= 11) && (b <= 15))
			cout << "копеек. ";
		else
		{
			b = atoi(string({(char)K[K.length()-1]}).c_str());
			if (b == 1)
				cout << "копейка. ";
			if ((b > 1) && (b < 5))
				cout << "копейки. ";
			if (((b >= 5) && (b <= 9)) || (b == 0))
				cout << "копеек. ";
		}
	}
	else
	{
		b = atoi(string({(char)K[K.length()-1]}).c_str());
		if (b == 1)
			cout << "копейка. ";
		if ((b > 1) && (b < 5))
			cout << "копейки. ";
		if (((b >= 5) && (b <= 9)) || (b == 0))
			cout << "копеек. ";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	do
	{
		R = "";
		K = "";
		cout << "Анализатор" << endl;
		cout << "Введите число в формате (0-999.,0-99):";
		cin >> s;
		cut();

		if (R.length() > 3)
		{
			cout << "Значение рублей не может быть больше 3-х значного числа" << endl;
			_getch();
			return 0;
		}

		if (K.length() > 2)
		{
			cout << "Значение копеек не может быть больше 2-х значного числа" << endl;
			_getch();
			return 0;
		}

		calc();

		switch (R.length())
		{
			case 1: summa = odin(R, false); break;
			case 2: summa = dva(R, false); break;
			case 3: summa = tree(R, false); break;
		}
		cout << summa;
		rub();
		summa = "";

		if (K != "")
		{
			switch (K.length())
			{
				case 1: summa = odin(K, true); break;
				case 2: summa = dva(K, true); break;
			}
			cout << summa;
			kop();
		}
		cout << "\n";
		cout << "\n";
		cout << "Для выхода нажмите ESC, для продолжения нажмите Enter..." << endl;
	} while (_getch() != 27);
	cout << "* * * Конец! * * *" << endl;
}

