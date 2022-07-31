#include <iostream>
#include "NewItem.h"
using namespace std;

NewItem::NewItem(const NewItem& other) {
	setName(other.getName());
	setType(other.getType());
	setCategory(other.getCategory());
	setPrice(other.getPrice());
	setCategory(other.getCategory());
}

istream& operator >> (istream& in, NewItem& other) {
	char* name = new char[50], * category = new char[50];
	double price;
	int quantity;
	cout << "\tEnter name of item : ";
	in.getline(name, 50);
	other.setName(name);

	cout << "\tEnter price of item : ";
	in >> price;
	other.setPrice(price);


	cout << "\tEnter quantity of item : ";
	in >> quantity;
	other.setQuantity(quantity);

	in.ignore();
	cout << "\tEnter category of item : ";
	in.getline(category, 50);
	other.setCategory(category);

	int choice;
	cout << "\tPress [1], if item type if teacher\n\t"
		<< "Press [2], if item type is both[teacher & students]\n\t> ";
	cin >> choice;
	
	char teacher[]{ "teacher" }, both[]{ "both" };

	if (choice == 1) {
		other.setType(teacher);
	}
	else if (choice == 2) {
		other.setType(both);
	}
	else {
		cout << "\tInvalid choice, and the item type is set to both\n";
		other.setType(both);
	}
	delete[] name;
	name = NULL;
	delete[] category;
	category = NULL;
	return in;
}