#include "Help.h"

void Help::deepCopy(char* to, const char* from) {
	int length = getLength(from);
	for (int i = 0; i < length; i++) {
		to[i] = from[i];
	}
	to[length] = '\0';
}

int Help::getLength(const char* variable) {
	int length = 0;
	for (int i = 0; variable[i] != '\0'; i++, length++);
	return length;
}

bool Help::compare(char* var1, char* var2) {
	int length1 = getLength(var1), length2 = getLength(var2);
	if (length1 != length1)
		return false;
	for (int i = 0; i < length1; i++) {
		if (var1[i] != var2[i])
			return false;
	}
	return true;
}