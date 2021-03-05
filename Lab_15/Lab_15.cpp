#include <iostream>
#include <windows.h>
#include<string>
using namespace std;

struct items
{
	string special;   //�������������
	float number;  //���������� ���������
};

void ShellSort(items* a, int n)
{//���������� �����
	int b = n / 2;
	while (b > 0)
	{
		for (int i = 0; i < n - b; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (a[j].number < a[j + b].number)
				{
					float d = a[j].number;
					a[j].number = a[j + b].number;
					a[j + b].number = d;
					string f = a[j].special;
					a[j].special = a[j + b].special;
					a[j + b].special = f;
					j -= b;
				}
				else
					j = -1;
			}
		}
		b /= 2;
	}
}

void HoaraSort(items* arr, int left, int right)
{//���������� �����
	float d;
	string f;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (arr[i].number > arr[(left + right) / 2].number && i < right)
			i++;
		while (arr[j].number < arr[(left + right) / 2].number && j > left)
			j--;
		if (i <= j)
		{
			d = arr[i].number;
			arr[i].number = arr[j].number;
			arr[j].number = d;
			f = arr[i].special;
			arr[i].special = arr[j].special;
			arr[j].special = f;
			i++;
			j--;
		}
		if (i < right)
		{
			HoaraSort(arr, i, right);
		}
		if (j > left)
		{
			HoaraSort(arr, left, j);
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "������� ���������� �����������: ";
	cin >> n;
	cout << "������� ��� ������������� � ���-�� ���������: " << endl;
	cin.ignore();
	items* st = new items[n];
	for (int i = 0; i < n; i++)
	{
		cout << "�������� �������������: ";
		cout << " ";
		getline(cin, st[i].special);
		cout << " ���������� ���������: ";
		cin >> st[i].number;
		cin.ignore();
	}
	int a;
	cout << endl << "��������:" << endl;
	cout << "1 - ���������� ����� " << endl;
	cout << "2 - ���������� �����" << endl;
	cout << "������� ��������: ";
	cin >> a;
	switch (a)
	{
	case 1: ShellSort(st, n); break;
	case 2: HoaraSort(st, 0, n - 1);; break;
	default: cout << "������!!! ����������� ��������. ���������� �� ���������." << endl;
	}
	cout << endl << "����� ����������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "�������� �������������: " << st[i].special << endl;
		cout << " ���������� ���������: " << st[i].number << endl;
	}
}