#pragma once
#include <iostream>
#include "Help.h"
using namespace std;

class Login : public Help {
	char* userName, * password;

public:
	Login();
	Login(char*, char*);
	void setUserName(char*);
	void setPassword(char*);
	char* getUserName();
	char* getPassword();
	bool checkCredentials();

	friend istream& operator >> (istream& in, Login& login);
};
