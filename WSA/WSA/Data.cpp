#include "Data.h"

Data::Data() {}

Data::Data(std::string x, std::string y) { this->keyValString = x; this->actualValString = y; this->constructortype = INT_INT; }

Data::Data(std::string x, int y) { this->keyValString = x;this->actualValInt = y; this->constructortype = STRING_INT; }

Data::Data(int x, std::string y) { this->keyValInt = x; this->actualValString = y; this->constructortype = INT_STRING; }

Data::Data(int x, int y) { this->keyValInt = x; this->actualValInt = y; this->constructortype = STRING_STRING; }

void Data::printValOfInstance() {
	if (this->constructortype == INT_INT) {
		std::cout << this->keyValInt << " + " << this->actualValInt << std::endl;
	}
	else if (this->constructortype == STRING_INT) {
		std::cout << this->keyValString << " + " << this->actualValInt << std::endl;
	}
	else if (this->constructortype == INT_STRING) {
		std::cout << this->keyValInt << " + " << this->actualValString << std::endl;
	}
	else if (this->constructortype == STRING_STRING) {
		std::cout << this->keyValString << " + " << this->actualValString << std::endl;
	}
	else {
		std::cout << "something else has been init" << std::endl;
	}
}
