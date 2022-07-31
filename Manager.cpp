#include <fstream>
#include "Manager.h"
using namespace std;

Manager::Manager() {
	item = new Item[1];
}


void Manager::setLogin() {
	cin >> login;
}

Login Manager::getLogin() {
	return login;
}

void Manager::setItem(Item* item, int length) {
	delete[] this->item;
	this->item = nullptr;
	Item* temp = new Item[length];
	for (int i = 0; i < length; i++) {
		temp[i] = item[i];
	}
	delete[] item;
	item = nullptr;
	this->item = temp;
}

void Manager::addItem(NewItem& newItem, int length) {
	Item* temp = new Item[length + 1];
	for (int i = 0; i < length; i++) {
		temp[i] = item[i];
	}
	delete[] this->item;
	this->item = nullptr;

	temp[length].setName(newItem.getName());
	temp[length].setPrice(newItem.getPrice());
	temp[length].setQuantity(newItem.getQuantity());
	temp[length].setType(newItem.getType());
	temp[length].setCategory(newItem.getCategory());

	this->item = temp;
}

void Manager::removeItem(int length, int itemNumber) {
	Item* temp = new Item[length - 1];
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (i == itemNumber) {
			continue;
		}
		temp[count++] = item[i];
	}
	delete[] this->item;
	this->item = nullptr;
	this->item = temp;
}

Item* Manager::getItem() {
	return item;
}

void Manager::viewSalesReport() {
	ifstream in("sales.txt");
	double revenue;
	in >> revenue;

	cout << "\t| Total revenue genereted after selling shop items : " << revenue << "\n";
	in.ignore();
	in >> revenue;

	cout << "\t| Total revenue generated after selling shop items to teachers : " << revenue << "\n";
	in.ignore();
	in >> revenue;
	cout << "\t| Total revenue generated after selling shop items to students : " << revenue << "\n";
	in.close();
}

void Manager::resetSalesReport() {
	ofstream out("sales.txt");
	out << "0,0,0";
	out.close();
}