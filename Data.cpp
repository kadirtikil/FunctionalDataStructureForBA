#ifndef DATA_IMPL_CPP
#define DATA_IMPL_CPP

#include "Data.h"

template< typename T1, typename T2>
Data<T1, T2>::Data() {}

template< typename T1, typename T2>
Data<T1, T2>::Data(T1 arg1, T2 arg2) { 
	this->data.first = arg1;
	this->data.second = arg2;
}

template <typename T1, typename T2>
Data<T1, T2>::~Data() {
	delete data;
}

template< typename T1, typename T2>
void Data<T1, T2>::printData() {
	std::cout << "KeyDataType: " << typeid(this->data.first).name() << ", KeyValue: " << this->data.first << std::endl;
	std::cout << "ActualValueType: " << typeid(this->data.second).name() << ", ActualValue: " << this->data.second << std::endl;
}


#endif
