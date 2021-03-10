#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string str;
int n;
int g;

void loadFile(string filename);
void printFile(string filename);
void getLastLine(string filename, string& str);
int countVowels(string str);
void moveString(string filename_in, string filename_out);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "������� ���-�� �����: ";
    cin >> n;

    // ������ ������ � ����
    loadFile("F1.txt");

    // ��������� ����
    printFile("F1.txt");

    // ����������� ����� �� ������ ����� � ������
    moveString("F1.txt", "F2.txt"); 

    n -= g; // ������������, ������� �� ������ ������� �������
    printFile("F2.txt");

    getLastLine("F2.txt", str); // �������� ��������� ������
    cout << "���-�� ������� � ��������� ������: " << countVowels(str) << endl;
    return 0;
}

void loadFile(string filename) {
    cin.ignore();
    // F1
    ofstream f1(filename);
    if (!f1.is_open())
    {
        // ���� �� �����������
        cout << "���� �� ������" << endl;
        exit(EXIT_FAILURE);
    }

    // ���������� ������
    for (int i = 0; i < n; i++)
    {
        // �������� �������
        getline(cin, str);
        f1 << str << "\n";
    }

    // ��������� ����
    f1.close();
}

void printFile(string filename) {
    ifstream file(filename);
    if (!file.is_open())
    {
        // ���� �� �����������
        cout << "���� �� ������" << endl;
        exit(EXIT_FAILURE);
    }

    // ������� �����������
    cout << "���������� ����� " << filename << endl;
    for (int i = 0; i < n; i++)
    {
        // �� ����� � �������
        getline(file, str);
        cout << str << endl;
    }
    // ������� �� �����
    file.close();
}

// �������� ��������� �������
void getLastLine(string filename, string& str) {
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "����� �� ������" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        getline(file, str);
    }
    file.close();
}

// ���������� �������
int countVowels(string str) {
    int count = 0;
    for (auto c : str)
    {
        switch (c)
        {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y': count++;
        }
    }
    return count;
}

void moveString(string filename_in, string filename_out) {
    // ��������� ����� F1 � F2
    ifstream f(filename_in);
    ofstream f2(filename_out);
    if (!f.is_open() && !f2.is_open())
    {
        // ���������, ����� ����� �� �����������
        cout << "����� �� ������" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        getline(f, str); // �������� ������� �� �����

        string s;
        string arr[50];
        stringstream str_word(str);
        int j = 0;
        while (str_word >> s)
        {
            arr[j] = s;
            j++;
        }
        for (int q = 0; q < j; q++)
            for (int k = q + 1; k < j; k++)
                if (arr[q] == arr[k])
                {
                    f2 << str << "\n";
                    g++;
                }
    }

    // ��������� �����
    f.close();
    f2.close();
}