#include "DataStruc.h"
#include "Data.h"
#include <string>

int main() {
	//Data<double, std::string> obj(1.2, "hello");

	//Data<int, std::string>(12, "this a string").printData();

	
	//DataStruc().dataStrucAlgo(R"({'Hello this might be a string too': 10000000000000000000000000000000000000000000000.12})", 100);
	// Assuming Data is already defined as a template class

	// Declare an object of Data class with appropriate types
	// The data is immutable after its declaration. So it cannot be changes during run time
	Data<std::string, std::string>* dataElement = new Data<std::string, std::string>("HELLO", "WORLD");
	Data<int, int>* dataElement1 = new Data<int, int>(3, 4);
	Data<int, int>* dataElement2 = new Data<int, int>(5, 6);
	dataElement->printData();

	// Declare an object of DataStruc class with appropriate types
	// The datastructure can be changed in its structure but not in its values.
//	DataStruc<int,int>* myDataStruc = new DataStruc<int, int>();
//	myDataStruc->addDataToList(dataElement);
//	myDataStruc->addDataToList(dataElement1);
//	myDataStruc->addDataToList(dataElement2);
//	myDataStruc->printAll();
	// Next, the datastructure will take in a string, and iterate through it. 
	// While doing that, the algorithm will create new and appropriate elements for 
	// datastruc.


	return 0;
}
