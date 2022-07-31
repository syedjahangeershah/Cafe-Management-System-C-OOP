#include <iostream>
#include "Item.h"
using namespace std;


Item::Item() {			// Defaul constructor
	name = new char[50];
	type = new char[50];
	category = new char[50];
	price = 0;
	quantity = 0;
	isTeacher = true;
}

Item::Item(char* name, char* type, char* category, double price, int quantity) {
	deepCopy(this->name, name);
	deepCopy(this->type, type);
	deepCopy(this->category, category);
	this->price = price;
	this->quantity = quantity;
	isTeacher = true;
}

Item::Item(const Item& other) {
	deepCopy(name, other.name);
	deepCopy(type, other.type);
	deepCopy(category, other.category);
	price = other.price;
	quantity = other.quantity;
	isTeacher = other.isTeacher;
}

// Setters for all attributes
void Item::setName(const char* name) {
	deepCopy(this->name, name);
}

void Item::setType(const char* type) {
	deepCopy(this->type, type);
}

void Item::setCategory(const char* category) {
	deepCopy(this->category, category);
}

void Item::setPrice(double price) {
	this->price = price;
}

void Item::setQuantity(int quantity) {
	this->quantity = quantity;
}

void Item::setIsTeahcer(bool flag)
{
	isTeacher = flag;
}

// Getters for all attributes
char* Item::getName() const {
	return name;
}
char* Item::getType() const {
	return type;
}
char* Item::getCategory() const {
	return category;
}
double Item::getPrice() const {
	return price;
}
int Item::getQuantity() const {
	return quantity;
}
bool Item::getIsTeacher() const
{
	return isTeacher;
}
void Item::operator=(Item* other)
{
		deepCopy(name, other->getName());
		price = other->getPrice();
		quantity = other->getQuantity();
		deepCopy(type, other->getType());
		deepCopy(category, other->getCategory());
}
istream& operator >> (istream& in, Item& item) {
	char* name = new char[50];
	double price;
	int quantity;
	in.getline(name, 50, ',');	// input Name of item
	item.setName(name);
	in >> price;					// input Price of item
	item.setPrice(price);
	in.ignore();
	in >> quantity;					// input Quantity of item
	item.setQuantity(quantity);

	in.ignore();
	in.getline(name, 50, ',');	// input Type of item
	item.setType(name);
	in.getline(name, 50);	// input Category of item
	item.setCategory(name);

	return in;
}

ostream& operator << (ostream& out, Item& item) {
	cout << "\t|-----------------------------\n"
		<< "\t| Name : " << item.getName() << "\n"
		<< "\t| Price : " << item.getPrice() << "\n"
		<< "\t| Quantity : " << item.getQuantity() << "\n";
	if (item.isTeacher)
		cout << "\t| Item Type : " << item.getType() << "\n";
	cout << "\t| Item Category : " << item.getCategory() << "\n\t";
	cout << "|=============================\n";
	return out;
}