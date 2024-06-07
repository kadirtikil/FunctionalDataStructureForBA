#include "DataStruc.h"

DataStruc::DataStruc() {}

void DataStruc::dataStrucAlgo(std::string jsonString, int limitOfStrings) {
	bool stringDetector = true;

	// for for now, will try to use pattern matching with hof next.
	for (int i = 0; i < jsonString.length(); i++) {
		// if '{' is found, create a datatstruc.
		if (jsonString[i] == '{') {
			// Create a new datastruc
		}
		else if (jsonString[i] == '"') {
			// this means a string has been detected
			// so i think i should send a runner. a runner is a loop that goes until it finds the other '"'
			// and saves every character while doing so.
			if(stringDetector){
				int runner = i + 1;
				std::string word = "";
				while (true) {
					if (jsonString[runner] == '"') {
						stringDetector = false;
						break;
					}
					else if (runner - i == limitOfStrings) {
						int endOfStringFinder = runner;
						while (true)
						{
							if (jsonString[endOfStringFinder] = '"') {
								runner = endOfStringFinder;
								break;
							}
						}
						word.clear();
						stringDetector = false;
						break;
					}
					else {
						word += jsonString[runner];
					}
					runner += 1;
				}
				if (word == "") {
					std::cout << "The string was to long. skipped to the end." << std::endl;
				}
				else {
					std::cout << "this is the word, that has been found: " << word << std::endl;
				}
				
				word.clear();
				stringDetector = false;
				i = runner;
			}
			else {
				stringDetector = true;
			}
		}
		else if (std::isdigit(jsonString[i])) {
			bool isDouble = false;
			int runner = i;
			std::string num = "";
			
			while (true) {
				if (jsonString[runner] == ':' || jsonString[runner]=='\n' || jsonString[runner]==',' || jsonString[runner] == '}') {
					break;
				}
				else if (jsonString[runner] == '.') {
					isDouble = true;
					num += jsonString[runner];
				}
				else {
					num += jsonString[runner];
				}
				runner += 1;
			}
			if (isDouble) {
				std::cout << "The detected double is: " << std::stod(num) << std::endl;
			}
			else {
				std::cout << "The detected number is: " << std::stoi(num) << std::endl;
			}
			num.clear();
			i = runner;
		}
	}

}