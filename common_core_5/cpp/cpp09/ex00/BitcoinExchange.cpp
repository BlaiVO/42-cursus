#include <fstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream data_file("data.csva");
	if (!data_file)
		return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){(void)copy;}
//BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &a){}
BitcoinExchange::~BitcoinExchange(){}
void BitcoinExchange::process_line(std::string line){(void)line;}
