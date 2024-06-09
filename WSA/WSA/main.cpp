#include "DataStruc.h"
#include "Data.h"


int main() {
	//Data<double, std::string> obj(1.2, "hello");

	//Data<int, std::string>(12, "this a string").printData();

	
	//DataStruc().dataStrucAlgo(R"({'Hello this might be a string too': 10000000000000000000000000000000000000000000000.12})", 100);
	// Assuming Data is already defined as a template class

	// Declare an object of Data class with appropriate types
	Data<int, int>* dataElement = new Data<int, int>(1, 2);
	Data<int, int>* dataElement1 = new Data<int, int>(3, 4);
	Data<int, int>* dataElement2 = new Data<int, int>(5, 6);
	dataElement->printData();

	// Declare an object of DataStruc class with appropriate types
	DataStruc<int,int>* myDataStruc = new DataStruc<int, int>();
	myDataStruc->addDataToList(dataElement);
	myDataStruc->addDataToList(dataElement1);
	myDataStruc->addDataToList(dataElement2);
	myDataStruc->printAll();

	return 0;
}