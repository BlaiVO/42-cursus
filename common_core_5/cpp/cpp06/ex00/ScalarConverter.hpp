#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator= (const ScalarConverter &a);
		~ScalarConverter();
	public:
		static void	convert(std::string num);
};

#endif