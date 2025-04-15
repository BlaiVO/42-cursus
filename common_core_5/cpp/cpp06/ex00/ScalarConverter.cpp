#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
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

void caseChar(std::string num)
{
	char c = num[0];
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << (int)c << std::endl;
	std::cout << "float: " << (int)c << ".0f" << std::endl;
	std::cout << "double: " << (int)c << ".0" << std::endl;
}

void caseInt(std::string num)
{
	int i = strtol(num.c_str(), NULL, 10);
	char c = static_cast<char>(i);
	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible";
	else if (isprint(c))
		std::cout << c;
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << i << ".0f" << std::endl;
	std::cout << "double: " << i << ".0" << std::endl;
}

void caseFloat(std::string num)
{
	int f = static_cast<float>(strtod(num.c_str(), NULL));
	char c = static_cast<char>(f);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << f << std::endl;
}

void getType(std::string num)
{
	std::string pseudo_literals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++){
		if (num == pseudo_literals[i])
			return ; //pseudo-literal
	}
	if (num.length() == 1 && !isdigit(num[0]) && isprint(num[0]))
		return caseChar(num);
	char *p;
	long converted_int = strtol(num.c_str(), &p, 10);
	if (!*p && converted_int >= INT_MIN && converted_int <= INT_MAX)
		return caseInt(num);
	char *p2;
	double converted_double = strtod(num.c_str(), &p2);
	if (num.find('.') == std::string::npos || num.find('.') == num.length() - 1)
		goto undefined;
	if (!*p2)
		return; // double
	else if (*p2 == 'f' && (converted_double == ((double)((float)converted_double))))
	{
		if (!p2[1])
			return caseFloat(num);
	}
	undefined:
		{
			std::cout << "Error: invalid input" << std::endl;
		}
}

void	ScalarConverter::convert(std::string num)
{
	getType(num);
}
