
// do not include .cpp files !

#include <iostream>

#include "value.cpp" // exception, because there is no value header file
#include "value_impl.hpp"
#include "date.hpp"


int main() {
	Date d = Date{2020};
	Year y = Year{2020};
	d.print(std::cout);
}
