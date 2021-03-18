#include <iostream>
using namespace std;

double a;

struct Stack
{
	double data;
	Stack* prev;
};

Stack* make(int n)
{
	if (n <= 0)
	{
		cout << "Стек не может быть создан";
		return NULL;
	}
	Stack* top, * p;
	top = NULL;
	p = new Stack;
	cin >> a;
	p->data = a;
	p->prev = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		Stack* h = new Stack;
		cin >> a;
		h->data = a;
		h->prev = top;
		top = h;
	}
	return top;
}

void print(Stack* top)
{
	if (top == NULL) cout << "Стек пуст" << endl;
	else {
		Stack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

void add(Stack* top)
{
	Stack* p = top;
	Stack* q = new Stack;

	while (p != NULL)
	{
		if (p->data < 0) {
			Stack* r = new Stack;
			q = p->prev;
			p->prev = r;
			p = p->prev;
			p->data = 0;
			p->prev = q;
		}
		p = p->prev;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество элементов в стеке: ";
	cin >> n;

	Stack* st = make(n);

	cout << "Ваш стек: ";
	print(st);

	add(st);

	cout << "Стек после добавления: ";
	print(st);

	return 0;
}
