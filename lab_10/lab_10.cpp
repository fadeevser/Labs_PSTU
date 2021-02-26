#include <iostream>
#include <ctime>
using namespace std;

char** make_array(int size)
{
	char** a;
	a = new char* [size];
	for (int i = 0; i < size; i++)
	{
		int len = rand() % 30 + 1;
		a[i] = new char[len + 1];
		for (int j = 0; j < len; j++)
		{
			a[i][j] = rand() % 57 + 65;

		}
		a[i][len] = '\0';
	}
	return a;
}

void print_array(char** a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << '\t';
		int k = 0;
		while (a[i][k])
		{
			cout << a[i][k];
			k++;
		}
		cout << '\n';
	}
}

void find_and_delete(char**& a, int& size)
{
	int i;
	int k;
	cout << "Введите число k: ";
	cin >> k;
	for (int i = 0; i < size-k; i++)
	{
		cout << '\t';
		int k = 0;
		while (a[i][k])
		{
			cout << a[i][k];
			k++;
		}
		cout << '\n';
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int n;
	char** arr;

	cout << "Введите количество строк n: "; cin >> n;
	while (n < 3) {
		cout << "n должно быть больше или равно 3.";
		cout << "\nВведите количество строк n: "; cin >> n;
	}

	cout << "\nГенерация массива из " << n << " случайно сгенерированных строк...";
	arr = make_array(n);
	cout << "\nПолученный массив: \n";
	print_array(arr, n);
	cout << "\n";
	cout << "\nМассив, после удаления одинаковых строк: \n";
	print_array(arr, n);
	cout << "\n";
	cout << "\nУдаление k строк из массива...\n";
	find_and_delete(arr, n);



	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
