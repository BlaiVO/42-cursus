#include <iostream>
#include <fstream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	std::ifstream ifile(argv[1]);
	std::string line;
	BitcoinExchange btc;

	if (!ifile)
	{
		std::cerr << "Error: File could not be opened" << std::endl;
		return 1;
	}

	getline(ifile, line);
	if (line != "date | value")
		btc.process_line(line);

	while (getline(ifile, line))
		std::cout << line << std::endl;

	ifile.close();

}
