#include <fstream>
#include "Login.h"

Login::Login() {
	userName = new char[50];
	password = new char[50];
}

Login::Login(char* userName, char* password) {
	deepCopy(this->userName, userName);
	deepCopy(this->password, password);
}

void Login::setUserName(char* userName) {
	deepCopy(this->userName, userName);
}

void Login::setPassword(char* password) {
	deepCopy(this->password, password);
}

char* Login::getUserName() {
	return userName;
}

char* Login::getPassword() {
	return password;
}

bool Login::checkCredentials() {
	std::ifstream in("login.txt");
	int length;
	char* userName = new char[50], * password = new char[50];
	in >> length;
	in.ignore();
	for (int i = 0; i < length; i++) {
		in.getline(userName, 50, ',');
		in.getline(password, 50);

		if (compare(this->userName, userName) && compare(this->password, password)) {
			return true;
		}
	}
	return false;
}

std::istream& operator >> (std::istream& in, Login& login) {
	std::cout << "\t| Enter user Name : ";
	std::cin >> login.userName;
	std::cin.ignore();
	std::cout << "\t| Enter Password : ";
	std::cin.getline(login.password, 50);
	return in;
}