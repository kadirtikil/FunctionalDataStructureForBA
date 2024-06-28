#ifndef FUNCTIONAL_ALGORITHM_H
#define FUNCTIONAL_ALGORITHM_H

#include <string>
#include <iostream>


// The Functional way of parsing a json.
void functionalJsonParser();



// extracter funcs


// extract a found string as string. if a " is found.
std::string extractString();

// extract a float number as string
std::string extractFloat();

// extract a double number as string
std::string extractDouble();

// extract a int number as string
std::string extractInt();


#include "FunctionalAlgorithm.cpp"

#endif
