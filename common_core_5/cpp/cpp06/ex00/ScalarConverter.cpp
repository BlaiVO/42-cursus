#include <iostream>
#include <string>
#include <cstdlib>
#include <climits> // for INT_MAX and INT_MIN
#include <iomanip> // for std::setprecision()
#include <cmath> // for std::modf
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

void casePseudoLiteral(std::string num)
{
	std::string f_literals[3] = {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++)
	{
		if (num == f_literals[i])
		{
			num.erase(num.end()-1);
			break;
		}
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << num << 'f' << std::endl;
	std::cout << "double: " << num << std::endl;
}

void caseChar(std::string num)
{
	char c = num[0];
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
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
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;

}

void caseFloat(std::string num)
{
	float f = static_cast<float>(strtod(num.c_str(), NULL));
	char c = static_cast<char>(f);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	char *p;
	long int_check = std::strtol(num.c_str(), &p, 10);
	if (*p != '.' || int_check < INT_MIN || int_check > INT_MAX)
		std::cout << "int: invalid int" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(int_check) << std::endl;

	double integral;
	if (std::modf(f, &integral) == 0)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
		std::cout << "double: " << f << std::endl;
	}
	else
	{
		std::cout.precision(10);
		std::cout << "float: " << f << 'f' << std::endl;
		std::cout.precision(10);
		std::cout << "double: " << f << std::endl;
	}
}

void caseDouble(std::string num)
{
	double d = strtod(num.c_str(), NULL);
	char c = static_cast<char>(d);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	char *p;
	long int_check = std::strtol(num.c_str(), &p, 10);
	if (*p != '.' || int_check < INT_MIN || int_check > INT_MAX)
		std::cout << "int: invalid int" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	double integral;
	if (std::modf(d, &integral) == 0)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << d << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout.precision(10);
		std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
		std::cout.precision(17);
		std::cout << "double: " << d << std::endl;
	}
}

void	ScalarConverter::convert(std::string num)
{
	std::string pseudo_literals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++){
		if (num == pseudo_literals[i])
			return casePseudoLiteral(num);
	}
	if (num.length() == 1 && !isdigit(num[0]) && isprint(num[0]))
		return caseChar(num);
	char *p;
	long i = strtol(num.c_str(), &p, 10);
	if (!*p && i >= INT_MIN && i <= INT_MAX)
		return caseInt(num);
	char *p2;
	strtod(num.c_str(), &p2);
	if (num.find('.') == std::string::npos || num.find('.') == num.length() - 1)
		goto undefined;
	if (!*p2)
		return caseDouble(num);
	else if (*p2 == 'f' && isdigit(num[num.find('f') - 1]))
	{

		if (!p2[1])
			return caseFloat(num);
	}
	undefined:
		{
			std::cout << "Error: invalid input" << std::endl;
		}
}
