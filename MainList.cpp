#pragma once
#include "List.h"
#include <iostream>
using namespace std;

enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };

int main() {
	List lst;
	List lst2;
	int choice, val;

	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-4\n";
	cin >> choice;
	while (choice != EXIT) {
		switch (choice) {
		case INSERT:
			cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case REMOVE:
			cout << "enter a value to remove\n";
			cin >> val;
		//	lst.remove(val);
			break;
		case ASSIGN:
			lst2 = lst;
			cout << "list 2: " << lst2;
			cout << "list 1: ";
		case PRINT:
			cout << lst << endl;
			break;
		default:cout << "ERROR\n";
		}
		cout << "choose 0-4\n";
		cin >> choice;
	}
	return 0;
}

