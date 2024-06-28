#include "FunctionalAlgorithm.h"


void functionalJsonParser(std::string jsonString) {
	// int for index of parser in json
	int parser = 0;

	// switch cases in  here
	switch(jsonString[parser]) 
	{
        case '"':
            std::cout << extractString();
            parser++;
			break;
		case 2:
            parser++;
			break;
		case 3:
            parser++;
			break;
		case 4:
            parser++;
			break;
		case 5:
            parser++;
			break;
	}
}

std::string extractString() {
	return "Extract String function";
}



std::string extractDouble() {
    return "Extract Double Function";
}


std::string extractFloat() {
    return "extract float function";
}


std::string extractInt() {
    return "extract Int function";
}
