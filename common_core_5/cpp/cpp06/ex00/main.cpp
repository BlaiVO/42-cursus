#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: must input exactly 1(one) argument" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

