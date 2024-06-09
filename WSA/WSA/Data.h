#pragma once
#ifndef DATA_H
#define DATA_H

#include <string>
#include <optional>
#include <iostream>
#include <typeinfo>

template <typename T1, typename T2>
class Data {
public:
    // One Constructor, tkae 2 arguments of any datatype. 
    // So time for templates:
    Data(T1 arg1, T2 arg2);


    Data(); // Default constructor

    // simpe func to print datatypes and its values.
    void printData();

    // getter for attributes no setters yet. because i want this to be immutable after declaration such that
    // no nonos happen later on. keeping it functional
    T1 getKey() { return this->data.first; }

    T2 getValue() { return this->data.second; }


private:
    std::pair<typename T1, typename T2> data;
    Data<T1,T2>* next = nullptr;
    Data<T1,T2>* previous = nullptr;

};

#include "Data.cpp";

#endif
