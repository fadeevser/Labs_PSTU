#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
23. ��������� "�������":
- ��������
- ��� ���������
- ���������� ��������
- ���� ������
������� ��� ��������, � ������� ��� ��������� ������
���������, �������� 2 �������� ����� ���������
� ��������� �������.
*/

struct stadions //������� ��������� 
{
    string name, sports; //��������, ���� ������
    int year, number; //��� ���������, ����������


	void Fill()
	{
		cout << "\n������� �������� ��������: ";
		getline(cin, name);
		while (name == "" || name[0] == ' ')
		{
			cout << "������ �� ����� ���� ������ � �� ����� ���������� � �������.\n";
			cout << "������� �������� ��������: ";
			getline(cin, name);
		}
		cout << "������� ���� ������: ";
		getline(cin, sports);
		while (sports == "" || sports[0] == ' ')
		{
			cout << "������ �� ����� ���� ������ � �� ����� ���������� � �������.\n";
			cout << "������� ���� ������: ";
			getline(cin, sports);
		}
		cout << "������� ��� ���������: "; cin >> year;
		while (year > 2021 || year < 1895)
		{
			if (year < 1895)
			{
				cout << "������ ������� ��� �������� ������ � 1912 ����.\n";
				cout << "������� ���: "; cin >> year;
			}
			else
			{
				cout << "����� ��������� ������ ��� ����������� ��������.\n";
				cout << "������� ���: "; cin >> year;
			}
		}
		cout << "������� ���������� ��������: "; cin >> number;
		while (number <= 0)
		{
			cout << "���������� ������� �����������.\n";
			cout << "������� ���������� ��������: "; cin >> number;
		}
		cin.get();
	}

	void Print()
	{
		cout << "\n";
		cout << "��������:\t" << name << "\n";
		cout << "���� ������:\t" << sports << "\n";
		cout << "��� ���������:\t" << year << "\n";
		cout << "���������� ��������:\t" << number << "\n";
	}
};

void AddToFile(ofstream& file, stadions* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		file << "��������:\t" << arr[i].name << endl;
		file << "���� ������:\t" << arr[i].sports << endl;
		file << "��� ���������:\t" << arr[i].year << endl;
		file << "���������� ��������:\t" << arr[i].number << endl << endl;
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
	if (size == 0) cout << "������ ����\n";
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

	cout << "������� ���������� ���������: "; cin >> num;
	while (num <= 0)
	{
		cout << "������� ������� ���������� ���������.\n";
		cout << "������� ���������� ���������: "; cin >> num;
	}
	cin.get();
	stadions* stadions_arr = new stadions[num];
	for (int i = 0; i < num; i++)
	{
		stadions_arr[i].Fill();
	}
	cout << "\n�������� ��������:\n";
	PrintList(stadions_arr, num);

	cout << "\n������� ���������� ��� ���������: ";
	cin >> year_del;
	while (year_del <= 0)
	{
		cout << "������ ������������ ���.\n";
		cout << "\n������� ���������� ��� ���������: ";
		cin >> year_del;
	}
	cin.get();
	cout << "\n��� ��������, � ������� ��� ��������� ������ " << year_del << " ����� �������.";
	RemoveExcess(stadions_arr, num, year_del);

	cout << "\n����� ������ ���������: \n";
	PrintList(stadions_arr, num);

	cout << "\n���������� 2 ��������� � ������ ������.\n";
	AppendToList(stadions_arr, num);
	AppendToList(stadions_arr, num);

	cout << "\n����� ������ ���������:\n";
	PrintList(stadions_arr, num);

	ofstream output(filename);
	AddToFile(output, stadions_arr, num);

	output.close();
	delete[] stadions_arr;
	return 0;
}