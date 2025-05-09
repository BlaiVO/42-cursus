#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "BitcoinExchange.hpp"

#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	this->is_initialized = false;

	std::ifstream data_file("data.csv");
	if (!data_file)
		return;
	std::string line;

	getline(data_file, line);
	while (getline(data_file, line))
	{
		unsigned long comma_pos =  line.find(',');
		if (comma_pos == std::string::npos || line.find(',', comma_pos + 1) != std::string::npos)
			return ;

		this->data[line.substr(0, comma_pos)] = std::atof(line.substr(comma_pos + 1).c_str());
	}

	data_file.close();
	this->is_initialized = true;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->data = copy.data;
	this->is_initialized = copy.is_initialized;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &a)
{
	if (this != &a)
	{
		this->data = a.data;
		this->is_initialized = a.is_initialized;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){
}

bool get_float(std::string str_value, float &value)
{
	if ((str_value.find_first_of(".") != str_value.find_last_of(".")) ||
		(str_value.find_first_of("-") != str_value.find_last_of("-")) ||
		(str_value.find_first_not_of("-.0123456789") != std::string::npos))
	{
		std::cout << "Error: invalid value." << std::endl;
		return false;
	}

	value = std::atof(str_value.c_str());

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool check_date(int year, int month, int day)
{
	if (month > 12)
	{
		std::cout << "Error: Invalid month." << std::endl;
		return false;
	}

	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ))
		months[1] = 29;
	if (day > months[month -1])
	{
		std::cout << "Error: Invalid day." << std::endl;
		return false;
	}
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
	{
		std::cout << "Error: Data starts at 2009-01-02" << std::endl;
		return false;
	}
	return true;
}

bool valiDate(std::string date)
{
	if ((static_cast<int>(std::count(date.begin(), date.end(), '-')) != 2) ||
	   (date.find_first_not_of("-0123456789") != std::string::npos))
	{
		std::cout << "Error: invalid date." << std::endl;
		return false;
	}
	unsigned long first_separator = date.find_first_of("-");
	unsigned long second_separator = date.find_last_of("-");

	std::string year = date.substr(0, first_separator);
	std::string month = date.substr(first_separator + 1, date.size() - second_separator - 1);
	std::string day = date.substr(second_separator + 1);

	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
	{
		std::cout << "Error: invalid date." << std::endl;
		return false;
	}

	if (!check_date(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str())))
		return false;

	return true;
}

void BitcoinExchange::process_line(std::string line)
{
	std::string date;
	std::string str_value;
	float value;

	unsigned long separator = line.find(" | ");
	if ((separator == std::string::npos || separator == line.size() - 3 || separator == 0) ||
	   (static_cast<int>(std::count_if(line.begin(), line.end(), std::iswspace)) != 2))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	date = line.substr(0, separator);
	str_value = line.substr(separator + 3);

	if (!valiDate(date))
		return;

	if (!get_float(str_value, value))
		return;

	std::map<std::string, float>::iterator it = this->data.lower_bound(date);

	if (it == this->data.end())
	{
		it--;
		std::cout << date << " => " << std::setprecision(7) << value << " = " << value * (*it).second << std::endl;
	}
	else if (it == this->data.begin())
		std::cout << "Error: cannot find any closer data" << std::endl;
	else
	{
		if ((*it).first != date)
			it--;
		std::cout << date << " => " << std::setprecision(7) << value << " = " << std::setprecision(7) << (float)(value * (*it).second) << std::endl;
	}
}
