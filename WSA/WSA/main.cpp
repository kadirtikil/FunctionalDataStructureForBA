#include "Data.h"

int main() {
	Data<double, std::string> obj(1.2, "hello");

	std::cout << typeid(obj.getKey()).name() << std::endl; 

	return 0;
}