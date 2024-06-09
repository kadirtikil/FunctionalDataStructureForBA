#pragma once
#ifndef DATASTRUC_H
#define DATASTRUC_H

#include "Data.h"

#include <string>
#include <optional>
#include <iostream>
#include <typeinfo>


// this class will contain Data, such that a json can be read in.
// so this is the class, that will iterate the json string, and make an object, that contains data objects, 
// so the functions on that object can be applied,
// such that these can be used for whatever...

// iterating through one json is O(n)..
// but using pattern matching is kind of safer... and more interesting for the challenge...


//{
//	"something": "something"
//}

// not only iteration, but also checking the data, to assign datatype. 
// so iterate, then check for "" to asign string, or num 1-9.1-9 to asign int or double or even float
// then check for [] to asign as array or list. and not even that, it should be possible to make a list of multiple datatypes.

// then there is this case:
//{
//	"something": "something",
//	"somethingX": {
//		"something1": "something1",
//		"something2": "something2",
//		"something3": "something3"
//		}
//}

// Does this mean, that Datastruc, should be able to contain itself? YES it does...

template<typename T1, typename T2>
class DataStruc {
private:
	Data<T1, T2>* head;
	Data<T1, T2>* tail;

public:
	DataStruc() {}
	// Concstructor takes in a Object of Class Data.
	// Then has to make it, such that, the latest added element point its next pointer to the newest.
	// Getter
	Data<T1, T2>* getHead() { return this->head; }
	Data<T1, T2>* getTail() { return this->tail; }

	// Setters
	void setHead(Data<T1, T2>* element) { this->head = element; }
	void setTail(Data<T1, T2>* element) { this->tail = element; }


	// Add Element to list
	void addDataToList(Data<T1,T2>* element) {
		if (head == nullptr) {
			std::cout << "List was empty. Set Head to new element." << std::endl;
			// head should be its own instance in ever DS such that checking
			// is easier and the structure itself can be handled better. 
			// insted of askin if head is nullptr, just ask if head.next is nullptr 
			// and we gucci
			head = element;
			tail = element;

		}
		else {
			std::cout << "List already contains elements. set tail->next to new element" << std::endl;
			tail->next = element;
			element->previous = tail;
			// push tail to new position
			tail = tail->next;
		}
	}

	// Func to print the whole DataStruc
	void printAll() {
		while (head != nullptr) {
			std::cout << "Current Key val: " << head->getKey() <<
				"\nCurrent Actual val: " << head->getValue() << std::endl;
			head = head->next;
		}
	}


	// func to print head element
	void printHead() {
		std::cout << "Head Key is: "<< head->getKey() 
			<< "\nHead Value is: " << head->getValue() << std::endl;
	}



	// The Algorithm is here. 
	// First Stage: Check for strings, and asign. WORKS!
	// Second Stage: Check for int, and asign. WORKS!
	// Third Stage: Check for double, and asign. WORKS!
	// Thats it for today. Next up:
	// Forth Stage: Check for floats. WORKS! (cast to double if  you want a double cause its float by default)
	// Fifth Stage: Check for Strings inside ''. WORKS!
	////////////////////////////////////////////////////////////////////////////////////
	// NEXT::::
	// Create Instances of data, than link them with pointers.



	// The Backbone
	void dataStrucAlgo(std::string jsonString, int limitOfStrings) {
		bool stringDetector = true;

		// for for now, will try to use pattern matching with hof next.
		for (int i = 0; i < jsonString.length(); i++) {
			// if '{' is found, create a datatstruc.
			if (jsonString[i] == '{') {
				// Create a new datastruc
			}
			else if (jsonString[i] == '"' || jsonString[i] == '\'') {
				// this means a string has been detected
				// so i think i should send a runner. a runner is a loop that goes until it finds the other '"'
				// and saves every character while doing so.
				if (stringDetector) {
					int runner = i + 1;
					std::string word = "";
					while (true) {
						if (jsonString[runner] == '"' || jsonString[runner] == '\'') {
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
					if (jsonString[runner] == ':' || jsonString[runner] == '\n' || jsonString[runner] == ',' || jsonString[runner] == '}') {
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
					// BUT, if this num, is not inside the borders of a float, then cast it to floaty float float.
					if (std::stod(num) < std::numeric_limits<float>::min() || std::stod(num) > std::numeric_limits<float>::max()) {
						std::cout << "The detected double is: " << std::stod(num) << std::endl;
						// BUUUUT what if the digit aint no digit, but an e.... cause floats contain e for 10^x...
					}
					else {
						std::cout << "The detected float is: " << std::stof(num) << std::endl;
					}
				}
				else {
					std::cout << "The detected number is: " << std::stoi(num) << std::endl;
				}
				num.clear();
				i = runner;
			}
		}


	};
};

#endif