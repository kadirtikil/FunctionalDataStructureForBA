#include "Data.h"
#include "DataStruc.h"

int main() {
	Data<double, std::string> obj(1.2, "hello");

	DataStruc().dataStrucAlgo(R"({"A": 10.69})", 10);


	return 0;
}