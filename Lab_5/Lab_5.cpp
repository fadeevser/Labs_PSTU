#include <iostream> //done
using namespace std;
int n, k, nm, kol;
double sr, sum, m;
int a[20][20];
int main()
{
    setlocale(LC_ALL, "rus");
    kol = 0;
    sum = 0;
    cout << "Введите кол-во строк M и кол-во столбцов N: ";
    cout << endl;
    cin >> m;
    cout << endl;
    cin >> n;
    cout << endl;
    cout << endl;
    cout << "Введите массив: ";
    cout << endl;
    cout << endl;
    for (int i = 0; i < m; i++) //задача строк
    {
        for (int j = 0; j < n; j++) //задача столбцов
        {
            cin >> a[i][j]; //ввод массива
            cout << endl;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum = sum + a[j][i];
        }
        sr = sum / m;
        cout << sr << " ";
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (sr < a[j][i])
                {
                    kol++;
                }
            }
        }
        sr = 0;
        sum = 0;
    }
    cout << "Кол-во элементов, превыщающих среднее значение предыдущнго столбца равно: ";
    cout << kol;
    return 0;
}