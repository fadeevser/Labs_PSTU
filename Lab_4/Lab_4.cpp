#include <iostream> //done
#include <stack>
using namespace std;
int n, z;
int i = -1;
int a[100];
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "������� ���-�� ��������� ��� �����: "; //������ ���-�� ���������
    cout << endl;
    cout << endl;
    cin >> n;
    cout << endl;
    cout << "������� �������� ��� �����: "; //������ �������� ��� �����
    cout << endl;
    cout << endl;
    for (int j = 0; j < n; j++) //��������� ���� ��� ���������� ���������
    {
        cin >> a[j];
        i++;
    }
    if (i == -1) //��������� ���� �� �������������
    {
        cout << "���� ����";
    }
    cout << endl;
    cout << endl;
    cout << "��������� ������� �����: ";
    cout << endl;
    cout << endl;
    cout << a[i];
    cout << endl;
    cout << endl;
    cout << "���� ������ ������� ������� ����� 0, �������� 1, ��������� ��������� 2";
    cout << endl;
    cout << endl;
    bool repeat = true;
    while (repeat == true)
    {
        cin >> z;
        switch (z)
        {
        case 0:
        {
            i--;
            for (int j = 0; j <= i; j++)
            {
                cout << a[j] << endl;
            }
            break;
        }
        case 1:
        {
            i++;
            cin >> a[i];
            for (int j = 0; j <= i; j++)
            {
                cout << a[j] << endl;
            }
            break;
        }
        case 2:
        {
            repeat = false;
            break;
        }
        }
    }
    return 0;
}