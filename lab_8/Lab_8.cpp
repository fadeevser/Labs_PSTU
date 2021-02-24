#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
23. Структура "Стадион":
- название
- год постройки
- количество площадок
- виды спорта
Удалить все элементы, у которых год постройки меньше
заданного, добавить 2 элемента перед элементом
с указанным номером.
*/

struct stadions //создаем структуру 
{
    string name, sports; //название, виды спорта
    int year, number; //год постройки, количество


	void Fill()
	{
		cout << "\nВведите название стадиона: ";
		getline(cin, name);
		while (name == "" || name[0] == ' ')
		{
			cout << "Строка не может быть пустой и не может начинаться с пробела.\n";
			cout << "Введите название стадиона: ";
			getline(cin, name);
		}
		cout << "Введите виды спорта: ";
		getline(cin, sports);
		while (sports == "" || sports[0] == ' ')
		{
			cout << "Строка не может быть пустой и не может начинаться с пробела.\n";
			cout << "Введите виды спорта: ";
			getline(cin, sports);
		}
		cout << "Введите год постройки: "; cin >> year;
		while (year > 2021 || year < 1895)
		{
			if (year < 1895)
			{
				cout << "Первый стадион был построен только в 1912 году.\n";
				cout << "Введите год: "; cin >> year;
			}
			else
			{
				cout << "Можно добавлять только уже построенные стадионы.\n";
				cout << "Введите год: "; cin >> year;
			}
		}
		cout << "Введите количество площадок: "; cin >> number;
		while (number <= 0)
		{
			cout << "Количество введено некорректно.\n";
			cout << "Введите количество площадок: "; cin >> number;
		}
		cin.get();
	}

	void Print()
	{
		cout << "\n";
		cout << "Название:\t" << name << "\n";
		cout << "Виды спорта:\t" << sports << "\n";
		cout << "Год постройки:\t" << year << "\n";
		cout << "Количество площадок:\t" << number << "\n";
	}
};

void AddToFile(ofstream& file, stadions* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		file << "Название:\t" << arr[i].name << endl;
		file << "Виды спорта:\t" << arr[i].sports << endl;
		file << "Год постройки:\t" << arr[i].year << endl;
		file << "Количество площадок:\t" << arr[i].number << endl << endl;
	}
}

void RemoveExcess(stadions*& arr, int& size, int year)
{
	int new_size = size;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].year > year) new_size--;
	}
	if (new_size == 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
	else
	{
		stadions* new_arr = new stadions[new_size];
		new_size = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].year <= year)
			{
				new_arr[new_size] = arr[i];
				new_size++;
			}
		}
		delete[] arr;
		arr = new_arr;
		size = new_size;
		new_arr = nullptr;
	}
}

void AppendToList(stadions*& arr, int& size)
{
	size++;
	stadions* new_arr = new stadions[size];
	new_arr[0].Fill();
	if (size > 1)
	{
		for (int i = 1; i < size; i++)
		{
			new_arr[i] = arr[i - 1];
		}
		delete[] arr;
		arr = new_arr;
		new_arr = nullptr;
	}
	else
	{
		arr = new_arr;
		new_arr = nullptr;
	}
}

void PrintList(stadions* arr, int size)
{
	if (size == 0) cout << "Список пуст\n";
	else
	{
		for (int i = 0; i < size; i++)
		{
			arr[i].Print();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");

	int num;
	int year_del;
	string filename = "stadions.txt";

	cout << "Введите количество стадионов: "; cin >> num;
	while (num <= 0)
	{
		cout << "Неверно введено количество стадионов.\n";
		cout << "Введите количество стадионов: "; cin >> num;
	}
	cin.get();
	stadions* stadions_arr = new stadions[num];
	for (int i = 0; i < num; i++)
	{
		stadions_arr[i].Fill();
	}
	cout << "\nИсходные стадионы:\n";
	PrintList(stadions_arr, num);

	cout << "\nВведите предельный год постройки: ";
	cin >> year_del;
	while (year_del <= 0)
	{
		cout << "Введен некорректный год.\n";
		cout << "\nВведите предельный год постройки: ";
		cin >> year_del;
	}
	cin.get();
	cout << "\nВсе стадионы, у которых год постройки меньше " << year_del << " будут удалены.";
	RemoveExcess(stadions_arr, num, year_del);

	cout << "\nНовый список стадионов: \n";
	PrintList(stadions_arr, num);

	cout << "\nДобавление 2 стадионов в начало списка.\n";
	AppendToList(stadions_arr, num);
	AppendToList(stadions_arr, num);

	cout << "\nНовый список стадионов:\n";
	PrintList(stadions_arr, num);

	ofstream output(filename);
	AddToFile(output, stadions_arr, num);

	output.close();
	delete[] stadions_arr;
	return 0;
}