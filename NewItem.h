#pragma once
#include "Item.h"
using namespace std;

class NewItem : public Item
{
	
public:
	NewItem() : Item() { }
	NewItem(char* name, char* type, char* category, double price, int quantity)
	: Item(name, type, category, price, quantity) {	}

	NewItem(const NewItem&);

	
	friend istream& operator >> (istream& in, NewItem& other);
};