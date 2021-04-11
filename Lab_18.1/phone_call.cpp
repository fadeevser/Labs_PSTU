#include <iostream>
#include "phone_call.h"

using namespace std;

void phone_call::init(int f, double s) {
	first = f;
	second = s;
}

void phone_call::read() {
	cout << "Первый элемент? "; cin >> first;
	cout << "Второй элемент? "; cin >> second;
}

void phone_call::show() {
	cout << "Первый = " << first << endl;
	cout << "Второй = " << second << endl;
}

double phone_call::coast() {
	return first * second;
}