#pragma once

#ifndef DATA_STRUC_H
#define DATA_STRUC_H

#include <iostream>
#include "Data.h"

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

public:

	DataStruc();

	// The Algorithm is here. 
	// First Stage: Check for strings, and asign. WORKS!
	// Second Stage: Check for int, and asign. WORKS!
	// Third Stage: Check for double, and asign. WORKS!
	// Thats it for today. Next up:
	// Forth Stage: Check for floats.
	// Fifth Stage: Check for Strings inside ''.
	void dataStrucAlgo(std::string jsonString, int limitOfStrings);

};



#endif