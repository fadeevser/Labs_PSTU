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
    cout << "������� ���-�� ����� M � ���-�� �������� N: ";
    cout << endl;
    cin >> m;
    cout << endl;
    cin >> n;
    cout << endl;
    cout << endl;
    cout << "������� ������: ";
    cout << endl;
    cout << endl;
    for (int i = 0; i < m; i++) //������ �����
    {
        for (int j = 0; j < n; j++) //������ ��������
        {
            cin >> a[i][j]; //���� �������
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
    cout << "���-�� ���������, ����������� ������� �������� ����������� ������� �����: ";
    cout << kol;
    return 0;
}