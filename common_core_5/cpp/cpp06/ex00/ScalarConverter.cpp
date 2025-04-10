#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	*this = copy;
}

ScalarConverter &ScalarConverter::operator= (const ScalarConverter &a) {
	(void)a;
	return *this;
}

ScalarConverter::~ScalarConverter(){
}

void	ScalarConverter::convert(std::string num)
{
	//dostuff
}
