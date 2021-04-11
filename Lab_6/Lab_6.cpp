#include <iostream> //done
using namespace std;
int a;
int f(int n)
{
    if (n / 10 > 0)
    {
        return n % 10 + f(n / 10);
    }
    else
    {
        return n % 10;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите число для поиска его элементов: ";
    cout << endl;
    cin >> a;
    cout << f(a);
    return 0;
}