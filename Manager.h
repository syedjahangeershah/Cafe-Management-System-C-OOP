#pragma once
#include <iostream>
#include "Login.h"
#include "NewItem.h"

class Manager
{
	Item* item;
	Login login;
public:
	Manager();
	void setItem(Item*, int);
	Item* getItem();

	void setLogin();
	Login getLogin();

	void addItem(NewItem&, int);
	void removeItem(int, int);
	

	void viewSalesReport();
	void resetSalesReport();
};


