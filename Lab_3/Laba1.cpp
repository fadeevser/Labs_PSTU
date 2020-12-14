#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int n, m, j, x;
    srand(time(0));
    cout << "Введите кол-во элементов: " << endl;
    cin >> n;
    int a[1000];
    cout << "Рандомный массив: " << endl;;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 50; //Рандом числа для массива
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; //выводится изначальный массив
    }
    cout << endl << endl;

    //Удаление
    cout << "Удаление четных чисел из массива" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            a[i] = a[i + 1];
            n--;
        cout << a[i] << ' ';
    }
    cout << '\n';


    //добавление
    cout << "__Добавление в массив N элементов, начиная с заданного номера K__" << endl;
    int k, N;
    cout << "Введите номер элемента K: ";
    cin >> k;
    cout << "Введите количество элементов M:";
    cin >> m;
    for (int i = k; i <= n + m; i++)
    {
        a[i + n] = a[i];
    }
    for (int i = k; i < n + k; i++)
    {
        a[i] = rand() % 100 - 50;
    }
    cout << "Массив, полученный после добавления заданных элементов: " << endl;
    x = m + n;
    for (int i = 0; i < x; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl << endl;
    
    //Перестановка
    int M, tmp;
    cout << "Введите сдвиг:" << endl;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        for (j = x - 1; j >= 0; j--)
            if (j == x - 1)
                tmp = a[x - 1];
            else
                a[j + 1] = a[j];
        a[0] = tmp;
    }
    cout << "Новый массив:" << endl;
    for (int i = 0; i < x; i++)
        cout << a[i] << ' ';

    //Поиск 1
    cout << "Поиск элемента с заданным ключом(значением) " << endl;
    int kk = 0, s = 0;
    cout << "Элемент: ";
    cin >> k;
    for (int i = 0; i < x; i++)
    {
        kk++;
        if (a[i] == k)
        {
            s = i;
            break;
        }
    }
    if (s == 0) cout << "не найдено элементов с заданным значением k";
    else
    {
        cout << "Элемент найден" << endl;
        cout << "Количество сравнений, проведенных в ходе поиска: " << kk;
    }
    cout << endl << endl;


    //Сортировка
    for (int i = 0; i < x - 1; ++i)
    {
        int temp;
        int min = i;
        for (int j = i + 1; j < x; ++j)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    // Теперь, когда весь массив отсортирован - выводим его на экран
    for (int i = 0; i < x; ++i)
        cout << a[i] << ' ';


    //Поиск 2 в сортированном массиве
    cout << "Поиск элемента с заданным ключом(значением) " << endl;
    kk = 0, s = 0;
    cout << "Элемент: ";
    cin >> k;
    for (int i = 0; i < x; i++)
    {
        kk++;
        if (a[i] == k)
        {
            s = i;
            break;
        }
    }
    if (s == 0) cout << "не найдено элементов с заданным значением k";
    else
    {
        cout << "Элемент найден" << endl;
        cout << "Количество сравнений, проведенных в ходе поиска: " << kk;
    }
    cout << endl << endl;
}