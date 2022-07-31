#include <iostream>
#include "Help.h"
using namespace std;

class Item : public Help {			// this class read all the items (with complete detail) present in the
									// the database Items.txt
	char* name, * type, * category;
	double price;
	int quantity;
	bool isTeacher;
public:
	Item();// Defaul constructor

	// Parametrized constructor
	Item(char*, char*, char*, double, int);
	// copy constructor
	Item(const Item&);

	// Setters for all attributes
	void setName(const char*);
	void setType(const char*);
	void setCategory(const char*);
	void setPrice(double);
	void setQuantity(int);
	void setIsTeahcer(bool);

	// Getters for all attributes
	char* getName() const;
	char* getType() const;
	char* getCategory() const;
	double getPrice() const;
	int getQuantity() const;
	bool getIsTeacher() const;

	void operator = (Item* other);

	friend istream& operator >> (istream&, Item&);
	friend ostream& operator << (ostream&, Item&);
};