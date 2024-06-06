#pragma once
#ifndef DATA_H
#define DATA_H

#include <string>
#include <optional>
#include <iostream>

class Data {
public:
    Data(); // Default constructor
    Data(std::string x, std::string y); // Constructor for string, string
    Data(std::string x, int y); // Constructor for string, int
    Data(int x, std::string y); // Constructor for int, string
    Data(int x, int y); // Constructor for int, int

    void printValOfInstance(); // Function to print values

    enum ConstructorType {
        INT_INT,
        INT_STRING,
        STRING_INT,
        STRING_STRING,
    };

private:

    ConstructorType constructortype;
    int keyValInt;
    int actualValInt;
    std::string keyValString;
    std::string actualValString;
   
};

#endif
