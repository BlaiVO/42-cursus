#include <iostream>
#include <string>
#include <cstdlib>
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

int getIntNum(std::string num)
{
	if (num.length() == 1 && !isnumber(num[0]))
		return int(num[0]);
	return 0;
}

char getType(std::string num)
{
	if (num.length() == 1 && !isnumber(num[0]))
		return 'c';
	else if (std::atoi(num.c_str()) != 0 || num == "0")
		return 'i';
	else if (std::atof(num.c_str()) )
		//AAAAAAA
}

void	ScalarConverter::convert(std::string num)
{
	std::cout << getIntNum(num) << std::endl;
}
