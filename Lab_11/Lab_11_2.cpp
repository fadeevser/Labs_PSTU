#include <iostream>
using namespace std;
struct List {
	int data;
	List* next;
	List* prev;
};

List* make(int size) {
	if (size == 0) {
		cout << "Нельзя создать пустой список" << endl;
		return 0;
	}
	List* first, * p;
	first = NULL;
	p = new List;
	cout << "Введите первый элемент:";
	cin >> p->data;
	first = p;
	p->next = NULL;
	p->prev = NULL;
	for (int i = 2; i <= size; i++) {
		List* h = new List;
		List* q = p;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << " элемент:";
		cin >> p->data;
		p->next = NULL;
		p->prev = q;
	}
	return first;
}

void del(List*& first) {
	List* p = first;
	while (p->data % 2 != 0) {
		p = p->next;
	}
	List* q = p;
	List* h = p->prev;
	h->next = p->next;
	p->next->prev = h;
	delete q;
}
void print(List* first) {

	if (first == NULL) {
		cout << "Пустой список" << endl;
	}
	else {
		cout << "|";
		List* p = first;
		while (p != NULL) {
			cout << p->data << "|";
			p = p->next;
		}
		cout << endl;
	}
}

int main() {
	int size;
	cout << "Enter list size:";
	cin >> size;

	List* list = make(size);
	cout << "List:";
	print(list);
	del(list);
	print(list);
	return 0;
}
