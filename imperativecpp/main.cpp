#include "DataStruc.h"
#include "Data.h"
#include "ImperativeAlgorithm.h"

#include <string>



int main() {
	
    std::string jsonString = R"({
      "name": "John Doe",
      "age": "302",
      "email": "johndoe@example.com",
      "isMember": "true",
      "balance": "100.50",
      "testtest": "testendet hier"
    })";

    dataStrucAlgo(jsonString, 10);    


    std::cout << "\n";

	return 0;
}
