#include <iostream>
#include<string>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;
struct info
{
	struct Date
	{
		int Day, Month, Year;
	};
	string fio;
	Date date;
	string number;
	void Show()
	{
		cout << "\nФИО: " << fio
			<< "\nДата рождения: " << date.Day << "." << date.Month << "." << date.Year
			<< "\nТелефон: " << number << endl;
	}
	void Random()
	{
		string names[] = { "Aleksadr", "Sergey", "Konstantin", "Oleg", "Pasha", "Stepan","Vladimir","Ivan", "Vladislav", "Petr","Igor", "VEgor" };
		string secnames[] = { "Ivanov","Olegov", "Petrov", "Sokolov", "Mironov", "Vesnin", "Egorov", "Smirnov" };
		string thirdnames[] = { "Aleksandrovich","Andreevich","Petrovich","Evgenievich", "Urievisch", "Pavlovich" };
		fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		date.Day = 1 + rand() % 31;
		date.Month = 1 + rand() % 12;
		date.Year = 1000 + rand() % 1000;
		string phone;
		for (int i = 0; i < 10; i++) {
			phone.push_back(rand() % 10 + 48);
		}
		number = phone;
	}
};

void del(info* st, info* st2, int ind, int n)
{
	for (int i = 0; i < ind; i++) {
		st2[i] = st[i];

	}
	for (int i = ind; i < n - 1; i++) {
		st2[i] = st[i + 1];
	}
}

void savetofile(info* st, int n)
{
	ofstream f("F2.txt", ios_base::app);
	if (!f.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	f << "Измененный массив структур: " << "\n";
	for (int i = 0; i < n; i++)
	{
		f << "ФИО: ";
		f << st[i].fio << "\n";
		f << "Дата рождения: " << st[i].date.Day;
		f << "." << st[i].date.Month;
		f << "." << st[i].date.Year << endl;
		f << "Номер телефона: ";
		f << st[i].number << "\n";
	}
	f.close();
}

void add(info* st, info* st2, int ind, int n)
{
	for (int i = 0; i < ind; i++)
	{
		st2[i] = st[i];
	}
	st2[ind].Random();
	for (int i = ind; i < n; i++)
	{
		st2[i + 1] = st[i];
	}
}

void linear(string key, int n, info* st)
{
	int ind;
	bool p = 0;
	for (int i = 0; i < n; i++)
	{
		if (st[i].number == key)
		{
			ind = i;
			p = 1;
		}
	}
	if (p) {
		cout << "\n\nЧто бы Вы хотели выполнить: " << endl
			<< "0 - Добавление элемента;" << endl
			<< "1 - Удаление элемента; " << endl;
		bool m;
		cin >> m;
		if (m)
		{
			info* st2 = new info[n - 1];
			del(st, st2, ind, n);
			delete[]st;
			n--;
			cout << "Изменённый масссив структур: " << endl;
			for (int i = 0; i < n; i++) {
				st2[i].Show();
			}
			cout << "\nХотите ли Вы записать изменённые данные в файл (0-нет/1-да)? ";
			bool save;
			cin >> save;
			if (save)
			{
				savetofile(st2, n);
				cout << "Список сохранён в файл F2.txt" << endl;
			}
			delete[]st2;
		}
		else
		{
			info* st2 = new info[n + 1];
			add(st, st2, ind, n);
			delete[]st;
			n++;
			cout << "Изменённый масссив структур: " << endl;
			for (int i = 0; i < n; i++) {
				st2[i].Show();
			}
			cout << "\nХотите ли Вы записать изменённые данные в файл (0-нет/1-да)? ";
			bool save;
			cin >> save;
			if (save)
			{
				savetofile(st2, n);
				cout << "Список сохранён в файл F2.txt" << endl;
			}
			delete[]st2;
		}
	}
	else
		cout << "Такого элемента не найдено" << endl;
}
bool search(string str, string obr) {
	bool res = 0;
	int ds = str.size();
	int dk = obr.size();
	if (dk > ds || dk < ds)
		return 0;
	if (ds == 0)
		cout << "Неверно задана строка\n";
	else if (dk == 0)
		cout << "Неверно задана подстрока\n";
	else
		for (int i = 0; i < ds - dk + 1; i++)
			for (int j = 0; j < dk; j++)
				if (obr[j] != str[i + j])
					break;
				else if (j == dk - 1)
				{
					res = 1;
				}
	return res;
}
void ShellSort(info* a, int* A, int n)
{
	int h = n / 2;
	while (h > 0)
	{
		for (int i = 0; i < n - h; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (A[j] > A[j + h])
				{
					info d = a[j];
					a[j] = a[j + h];
					a[j + h] = d;
					int z = A[j];
					A[j] = A[j + h];
					A[j + h] = z;
					j -= h;
				}
				else
					j = -1;
			}
		}
		h /= 2;
	}
}
int get_value(string str) {
	int value = 0;
	int j = 1;
	for (auto i : str) {
		value += i * j;
		j++;
	}
	return value;
}
int InterpolSearch(int* A, int n, unsigned int key)
{
	int mid, left = 0, right = n - 1;
	while (A[left] <= key && A[right] >= key)
	{
		mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
		if (A[mid] < key) left = mid + 1;
		else if (A[mid] > key) right = mid - 1;
		else return mid;
	}
	if (A[left] == key) return left;
	else return -1;
}
void search1(info* st, string key, int n)
{
	bool p = 0;
	int ind;
	for (int i = 0; i < n && p == 0; i++)
	{
		bool l = search(st[i].number, key);
		if (l == 1)
		{
			p = 1;
			ind = i;
		}
	}
	if (p) {
		cout << "\n\nЧто бы Вы хотели выполнить: " << endl
			<< "0 - Добавление элемента;" << endl
			<< "1 - Удаление элемента; " << endl;
		bool m;
		cin >> m;
		if (m)
		{
			info* st2 = new info[n - 1];
			del(st, st2, ind, n);
			delete[]st;
			n--;
			cout << "Изменённый масссив структур: " << endl;
			for (int i = 0; i < n; i++) {
				st2[i].Show();
			}
			cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
			bool save;
			cin >> save;
			if (save)
			{
				savetofile(st2, n);
				cout << "Список сохранён в файл F2.txt" << endl;
			}
		}
		else
		{
			info* st2 = new info[n + 1];
			add(st, st2, ind, n);
			delete[]st;
			n++;
			cout << "Изменённый масссив структур: " << endl;
			for (int i = 0; i < n; i++) {
				st2[i].Show();
			}
			cout << "\nХотите ли Вы записать изменённые данные в файл (0-нет/1-да)? ";
			bool save;
			cin >> save;
			if (save)
			{
				savetofile(st2, n);
				cout << "Список сохранён в файл F2.txt" << endl;
			}
		}
	}
	else
		cout << "Такого элемента не найдено" << endl;
}
void search2(info* st, string key, int n)
{
	int ind = -1;
	int* A = new int[n];
	int key1 = get_value(key);
	for (int i = 0; i < n; i++)
	{
		A[i] = get_value(st[i].number);
	}
	ShellSort(st, A, n);
	ind = InterpolSearch(A, n, key1);
	if (ind != -1) {
		cout << "\n\nЧто бы Вы хотели выполнить: " << endl
			<< "0 - Добавление элемента;" << endl
			<< "1 - Удаление элемента; " << endl;
		bool m;
		cin >> m;
		if (m)
		{
			info* st2 = new info[n - 1];
			del(st, st2, ind, n);
			delete[]st;
			n--;
			cout << "Изменённый масссив структур: " << endl;
			for (int i = 0; i < n; i++) {
				st2[i].Show();
			}
			cout << "\nХотите ли Вы записать изменённые данные в файл (0-нет/1-да)? ";
			bool save;
			cin >> save;
			if (save)
			{
				savetofile(st2, n);
				cout << "Список сохранён в файл F2.txt" << endl;
			}
		}
		else
		{
			info* st2 = new info[n + 1];
			add(st, st2, ind, n);
			delete[]st;
			n++;
			cout << "Изменённый масссив структур: " << endl;
			for (int i = 0; i < n; i++) {
				st2[i].Show();
			}
			cout << "\nХотите ли Вы записать изменённые данные в файл (0-нет/1-да)? ";
			bool save;
			cin >> save;
			if (save)
			{
				savetofile(st2, n);
				cout << "Список сохранён в файл F2.txt" << endl;
			}
		}
	}
	else
		cout << "Такого элемента не найдено" << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int n;
	string key;
	cout << "Кол-во элементов: ";
	cin >> n;
	info* st = new info[n];
	for (int i = 0; i < n; i++)
	{
		st[i].Random();
		st[i].Show();
	}
	cout << "\nХотите ли Вы записать изменённые данные в файл (0-нет/1-да)? ";
	bool save;
	cin >> save;
	if (save)
	{
		ofstream f("F2.txt");
		if (!f.is_open())
		{
			cout << "Файл не открыт!" << endl;
			return 0;
		}
		f << "Начальный массив структур: " << "\n";
		for (int i = 0; i < n; i++)
		{
			f << "ФИО: ";
			f << st[i].fio << "\n";
			f << "Дата рождения: " << st[i].date.Day;
			f << "." << st[i].date.Month;
			f << "." << st[i].date.Year << endl;
			f << "Номер телефона: ";
			f << st[i].number << "\n";
		}
		cout << "Список сохранён в файл F2.txt" << endl;
		f.close();
	}
	cout << "Введие ключ для поиска, только цифры: ";
	cin >> key;
	bool l;
	bool p = 0;
	int a;
	cout << endl << "Методы сортировки:" << endl;
	cout << "1 - прямой поиск подстроки в строке" << endl;
	cout << "2 - линейный поиск" << endl;
	cout << "3 - интерполяционный поиск" << endl;
	cout << "Введите операцию: ";
	cin >> a;
	switch (a)
	{
	case 1: search1(st, key, n); break;
	case 2: linear(key, n, st); break;
	case 3: search2(st, key, n); break;
	default: cout << "Неизвестная операция. Сортировка не выполнена." << endl;
	}
}
