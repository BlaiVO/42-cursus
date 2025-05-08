#include <fstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->is_initialized = false;

	std::ifstream data_file("data.csva");
	if (!data_file)
		return;
	std::string line;

	getline(data_file, line);
	while (getline(data_file, line))
	{
		std::string key;
		float value;

		int comma_pos =  line.find(',');
		if (comma_pos == std::string::npos || line.find(',', comma_pos + 1) != std::string::npos)
			return ;
		key = line.substr(0, comma_pos);
	}

	data_file.close();
	this->is_initialized = true;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){(void)copy;}
//BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &a){}
BitcoinExchange::~BitcoinExchange(){}
void BitcoinExchange::process_line(std::string line){(void)line;}
