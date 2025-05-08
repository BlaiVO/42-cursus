#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string,float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		//BitcoinExchange &operator=(const BitcoinExchange &a);
		~BitcoinExchange();
		void process_line(std::string line);
		bool is_initialized;
};

#endif