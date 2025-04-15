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

char getType(std::string num)
{
	std::string literals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++){
		if (num == literals[i])
			return 'l';
	}
	if (num.length() == 1 && !isdigit(num[0]))
		return 'c';
	char *p;
	long converted_int = strtol(num.c_str(), &p, 10);
	if (!*p && converted_int >= INT_MIN && converted_int <= INT_MAX)
		return 'i';
	char *p2;
	double converted_double = strtod(num.c_str(), &p2);
	if (num.find('.') == std::string::npos || num.find('.') == num.length() - 1)
		goto undefined;
	if (!*p2)
		return 'd';
	else if (*p2 == 'f' && (converted_double == ((double)((float)converted_double))))
	{
		if (!p2[1])
			return ('f');
	}
	undefined:
		{
			return ('u');
		}
}

void	ScalarConverter::convert(std::string num)
{
	std::cout << getType(num) << std::endl;
}
