// InDen.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>


const int max_len = 30; 
int base = 10;

struct BigInt
{
	int amount; // порядок числа
	int digits[max_len]; // массив цифр числа с конца

	BigInt();
	int input();
	void output();
	bool operator > (const BigInt &);
	BigInt operator * (const int &);
	void LevelUp();
	BigInt operator - (const BigInt &);
	BigInt operator % (BigInt);


};

using namespace std;

bool Guardian(string str) // проверка на корректный ввод
{
	bool b = false;

	for (int i = 0; i<(int)str.length(); i++)
		if ((int)str[i]<(int)'0' || (int)str[i] > (int)'9')
			return true; // вернуть 1, если ввод некорректный

	return false; // вернуть 0, если ввод корректный
}

BigInt::BigInt() // объявление числа
{
	for (int i = 0; i < max_len; i++) // забивание нулей в массив
		digits[i] = 0;
	amount = 1;
}

int BigInt::input()
{
	string str;
	getline(cin, str); // счтитывание введеного числа
	if (Guardian(str)||str.size()>max_len) // проверка корректного ввода
		return 1;
	int pos = 0;
	for (int i = str.size() - 1; i >= 0; i--) // перевод в целочисленный тип
		digits[pos++] = str[i] - '0';
	amount = str.size();

	pos = amount;
	while (pos >= 0 && !(digits[pos] - 1)) // избавление от лишних нолей
		pos--;
	amount = pos;

	return 0;
}

void BigInt::output() 
{
	for (int i = amount - 1; i >= 0; i--) // вывод
		cout << digits[i];
	cout << endl;
}

bool BigInt::operator > (const BigInt &b) // сравнение длинных чисел
{
	if (this->amount != b.amount)
		return this->amount > b.amount;
	for (int i = this->amount - 1; i >= 0; i--)
	{
		if (this->digits[i] != b.digits[i])
			return this->digits[i]>b.digits[i];
	} // поциферное сравнение двух чисел
	return false;
}

BigInt BigInt::operator * (const int &n)
{
	BigInt res;
	res.amount = amount; // длина результата = длина исходного числа

	int r = 0;
	int i;
	for (i = 0; i<res.amount || r>0; i++) // умножение столбиком
	{
		res.digits[i] = digits[i] * n + r;
		r = res.digits[i] / base; // в res.digits[i] записывается цифра числа
		res.digits[i] = res.digits[i] % base;
	}
	res.amount = i;

	while (res.amount != 0 && !res.digits[res.amount - 1]) {
		--res.amount; // избавление от лишних нулей
	}
	return res; // возвращение результата умножения
}

void BigInt::LevelUp()
{
	for (int i = amount; i >= 1; i--)
		digits[i] = digits[i - 1];
	if (digits[amount])
		amount++;
}

BigInt BigInt::operator - (const BigInt &b)
{
	BigInt res = *this;
	int r = 0;
	for (int i = 0; i<res.amount; i++)
	{
		res.digits[i] -= b.digits[i] + r;
		if (res.digits[i]<0)
		{
			res.digits[i] += base;
			res.digits[i + 1]--;
		}
	}
	int pos = res.amount-1;
	while (pos && !res.digits[pos])
		pos--;
	res.amount = pos + 1;
	return res;
}

BigInt BigInt::operator % (BigInt b)
{
	BigInt resultat;
	BigInt ostatok;
	for (int i = amount - 1; i >= 0; i--)
	{
		ostatok.LevelUp(); // умножить на основание
		ostatok.digits[0] = digits[i]; // подбираем максимальное число x, такое что b * x <= остатка
		int x = 0;
		int l = 0, r = base;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			BigInt cur = b*m;
			if (!(cur > ostatok)) //////////////
			{
				x = m;
				l = m + 1;
			}
			else
				r = m - 1;
		}
		resultat.digits[i] = x;
		ostatok = ostatok - b * x;
	}

	int pos = ostatok.amount;
	while (pos >= 0 && !ostatok.digits[pos])
		pos--;
	ostatok.amount = pos + 1;

	return ostatok;
}

BigInt Evklid(BigInt a, BigInt b)
{
	while (b.amount) // элегантное логическое выражение, выполняется пока длина числа не равна 0
	{
		BigInt qwe = a;
		a = b;
		b = qwe % a;
	}
	return a;
}

int NOD()
{
	cout << "Введите 2 числа\n";
	BigInt alpha, beta;
	int guard1 = alpha.input(), guard2 = beta.input();
	if (guard1 || guard2)
	{
		cout << "Некорректный ввод\n";
		return 0;
	}
	if (!alpha.amount && (!beta.amount))	{
		cout << "НОД двух нолей не определен\n";
		return 0;
	}
	alpha = Evklid(alpha, beta);
	if (alpha.amount == 1 && alpha.digits[0] == 1)
		cout << "Эти числа взаимопростые\n";
	else cout << "Эти числа не взаимопростые\n";
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // русификация ввода-вывода
	string con1;
	// постановка вопроса задачи
	cout << "ЗАДАЧА: Определить, являются ли 2 числа взаимопростыми\n	программа работает с числами до 30-ти знаков\n";
	con1 = "да";
	while (con1 == "да" || con1 == "Да" || con1 == "ДА")
	{
		NOD(); // нахождение НОД
		cout << "Начать с другими данными? Да/Нет \n";
		getline(cin, con1);
		while (con1 != "да" && con1 != "нет" && con1 != "ДА" && con1 != "НЕТ" && con1 != "Да" && con1 != "Нет") // проверка ответа пользователя
		{
			cout << "Некорректный ввод, попробуйте снова\n";
			getline(cin, con1);
		}
	}
	return 0;
}