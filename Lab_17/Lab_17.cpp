#include <iostream>
#include <ctime>
#include <string>


using namespace std;

#define RND_CNT 100

#define FAKE_DATA 14

// ���
string name_fake[FAKE_DATA] = {
    "������ ���� ��������",
    "������ ���� ��������",
    "����������� ��������� �������������",
    "������ ���� ��������",
    "����������� ���� �������������",
    "������ ���� ��������",
    "����������� ���� �������������",
    "������ ��������� ��������",
    "������ ��������� ��������",
    "������ ���� �������������",
    "������ ��������� ��������",
    "����������� ���� �������������",
    "������ ���� �������������",
    "������ ��������� ��������"
};

string birthday_fake[FAKE_DATA] = {
    "10.10.2001",
    "20.02.2002",
    "20.02.2003",
    "20.02.2004",
    "20.02.2005",
    "20.02.2006",
    "20.02.2007",
    "20.02.2008",
    "20.02.2009",
    "20.02.2010",
    "20.02.2011",
    "20.02.2012",
    "20.02.2013",
    "20.02.2014"
};

string pasport_fake[FAKE_DATA] = {
    "403111",
    "401022",
    "401023",
    "401024",
    "401025",
    "401026",
    "401027",
    "401028",
    "401029",
    "401010",
    "401011",
    "401012",
    "401013",
    "401014"
};

struct User {
    string name;            // ���
    string birthday;        // ���� ��������
    string pasport;         // �������
};

struct Node {
    User data;     // ������� ������
    Node* next;     // ��������� �� ��������� �������
};

pair<Node**, int> make_table(User* items, int n, int size);
int hash_func(string key, int size);
void pressKey();
int echoMenu();
void generate(User* people, int n);
void print(User* people, int n);
void search(User* people, int n);

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "������� ���������� ������� ��� ���������" << endl;
    cin >> n;

    User* people = new User[n];
    generate(people, n);

    cout << "������� ������ ��� �������: ";
    int size;
    cin >> size;
    auto table = make_table(people, n, size);
    cout << "���������� ��������: " << table.second << endl;
    pressKey();
    int input = -1;
    while (input != 0) {
        input = echoMenu();
        switch (input) {
        case 1: {
            system("clear");
            print(people, n);
            pressKey();
        }
        case 2: {
            system("clear");
            cout << "������� ����� �������� ��� ������" << endl;
            string key;
            cin.ignore();
            getline(cin, key);
            int hash = hash_func(key, size);
            Node* current = table.first[hash];
            if (current != nullptr) {
                while (current->data.pasport != key && current->next != nullptr) {
                    current = current->next;
                }
                if (current->data.pasport == key) {
                    cout << current->data.name << ' ' << current->data.birthday << ' ' << current->data.pasport << endl;
                }
                else {
                    cout << "����� �� ������" << endl;
                }
            }
            pressKey();
        }
        case 3: {
            system("clear");
            cout << "������� ����� ������" << endl;
            cin >> size;
            auto table = make_table(people, n, size);
            cout << "���������� ��������: " << table.second << endl;
            pressKey();
        }
        default: {}
        }
    }
    system("clear");
    return 0;
}

int get_value(string str) {
    int value = 0;
    int j = 1;
    for (auto i : str) {
        value += i * j;
        j++;
    }
    return value;
}

int hash_func(string key, int size) {
    double f;
    return int(size * modf(get_value(key) * 0.803523421, &f));
}

// H(k)= [M(kAmod1)],0<A<1, mod1

pair<Node**, int> make_table(User* items, int n, int size) {
    Node** table = new Node * [size];
    for (int i = 0; i < size; i++)
        table[i] = nullptr;

    int n_of_collisions = 0;
    for (int i = 0; i < n; i++) {
        int hash = hash_func(items[i].birthday, size);
        if (table[hash] == nullptr) {
            Node* p = new Node;
            p->data = items[i];
            p->next = nullptr;
            table[hash] = p;
        }
        else {
            n_of_collisions++;
            Node* current = table[hash];
            while (current->next != nullptr) {
                current = current->next;
            }
            Node* p = new Node;
            p->data = items[i];
            p->next = nullptr;
            current->next = p;
        };
    }
    return make_pair(table, n_of_collisions);
}

void pressKey()
{
    cout << "Press any key to continue..." << endl;
    string n;
    cin >> n;
}

int echoMenu() {
    int input;

    system("clear");
    cout << "1 - �����" << endl;
    cout << "2 - �����" << endl;
    cout << "3 - ������������� ��� �������" << endl << endl;
    cout << "0 - �����" << endl;
    cin >> input;

    return input;
}

void generate(User* people, int n) {
    for (int i = 0; i < n; i++) {
        User p;

        p.name = name_fake[rand() % FAKE_DATA];
        p.birthday = birthday_fake[rand() % FAKE_DATA];
        p.pasport = pasport_fake[rand() % FAKE_DATA];

        people[i] = p;
    }
}

void print(User* people, int n) {
    for (int i = 0; i < n; i++) {
        cout << people[i].name << ' ' << people[i].pasport << ' ' << people[i].birthday << endl;
    }
}

void search(User* people, int n) {

}