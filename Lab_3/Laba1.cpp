#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int n, m, j, x;
    srand(time(0));
    cout << "������� ���-�� ���������: " << endl;
    cin >> n;
    int a[1000];
    cout << "��������� ������: " << endl;;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 50; //������ ����� ��� �������
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; //��������� ����������� ������
    }
    cout << endl << endl;

    //��������
    cout << "�������� ������ ����� �� �������" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            a[i] = a[i + 1];
            n--;
        cout << a[i] << ' ';
    }
    cout << '\n';


    //����������
    cout << "__���������� � ������ N ���������, ������� � ��������� ������ K__" << endl;
    int k, N;
    cout << "������� ����� �������� K: ";
    cin >> k;
    cout << "������� ���������� ��������� M:";
    cin >> m;
    for (int i = k; i <= n + m; i++)
    {
        a[i + n] = a[i];
    }
    for (int i = k; i < n + k; i++)
    {
        a[i] = rand() % 100 - 50;
    }
    cout << "������, ���������� ����� ���������� �������� ���������: " << endl;
    x = m + n;
    for (int i = 0; i < x; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl << endl;
    
    //������������
    int M, tmp;
    cout << "������� �����:" << endl;
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
    cout << "����� ������:" << endl;
    for (int i = 0; i < x; i++)
        cout << a[i] << ' ';

    //����� 1
    cout << "����� �������� � �������� ������(���������) " << endl;
    int kk = 0, s = 0;
    cout << "�������: ";
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
    if (s == 0) cout << "�� ������� ��������� � �������� ��������� k";
    else
    {
        cout << "������� ������" << endl;
        cout << "���������� ���������, ����������� � ���� ������: " << kk;
    }
    cout << endl << endl;


    //����������
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

    // ������, ����� ���� ������ ������������ - ������� ��� �� �����
    for (int i = 0; i < x; ++i)
        cout << a[i] << ' ';


    //����� 2 � ������������� �������
    cout << "����� �������� � �������� ������(���������) " << endl;
    kk = 0, s = 0;
    cout << "�������: ";
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
    if (s == 0) cout << "�� ������� ��������� � �������� ��������� k";
    else
    {
        cout << "������� ������" << endl;
        cout << "���������� ���������, ����������� � ���� ������: " << kk;
    }
    cout << endl << endl;
}