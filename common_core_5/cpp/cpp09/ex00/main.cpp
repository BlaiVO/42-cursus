#include <iostream>
#include <fstream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	if (argc > 2)
	{
		std::cerr << "Error: too many files." << std::endl;
		return 1;
	}

	std::ifstream ifile(argv[1]);
	std::string line;
	BitcoinExchange btc;

	if (!ifile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	if (!btc.is_initialized)
	{
		std::cerr << "Error: Error parsing data file." << std::endl;
		return 1;
	}

	getline(ifile, line);

	if (line != "date | value")
		btc.process_line(line);

	while (getline(ifile, line))
	{
		btc.process_line(line);
	}

	ifile.close();
}
