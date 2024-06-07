#ifndef DATA_IMPL_CPP
#define DATA_IMPL_CPP

#include "Data.h"

template< typename T1, typename T2>
Data<T1, T2>::Data() {}

template< typename T1, typename T2>
Data<T1, T2>::Data(T1 arg1, T2 arg2) { 
	this->attr.first = arg1;
	this->attr.second = arg2;
}

template< typename T1, typename T2>
void Data<T1, T2>::printData() {
	std::cout << "KeyDataType: " << typeid(this->attr.first).name() << ", KeyValue: " << this->attr.first << std::endl;
	std::cout << "ActualValueType: " << typeid(this->attr.second).name() << ", ActualValue: " << this->attr.second << std::endl;
}


#endif
