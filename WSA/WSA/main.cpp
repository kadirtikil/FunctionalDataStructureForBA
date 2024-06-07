#include "Data.h"
#include "DataStruc.h"

int main() {
	//Data<double, std::string> obj(1.2, "hello");

	DataStruc().dataStrucAlgo(R"({'Hello this might be a string too': 10000000000000000000000000000000000000000000000.12})", 100);


	return 0;
}