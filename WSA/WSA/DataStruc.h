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


class DataStruc {
private:
	template<typename T1, typename T2>
	Data<T1, T2>* head();
	template<typename T1, typename T2>
	Data<T1, T2>* tail();

public:
	DataStruc() {}
	// Concstructor takes in a Object of Class Data.
	// Then has to make it, such that, the latest added element point its next pointer to the newest.
	template<typename T1, typename T2>
	DataStruc(Data<T1, T2>* element);
	// Getter
	template<typename T1, typename T2>
	Data<T1, T2>* getHead();
	template<typename T1, typename T2>
	Data<T1, T2>* getTail();

	// Setters
	template<typename T1, typename T2>
	void setHead(Data<T1, T2>* element);
	template<typename T1, typename T2>
	void setTail(Data<T1, T2>* element);


	// Add Element to list
	template<typename T1, typename T2>
	void addDataToList(Data<T1, T2> elem);



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
	void dataStrucAlgo(std::string jsonString, int limitOfStrings);

};


#endif