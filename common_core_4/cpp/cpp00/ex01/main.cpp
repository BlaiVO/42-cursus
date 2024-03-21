#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook phonebook;

	std::string input;
	std::cout << "Welcome 	\n";
	std::cout << "Plase input one of the following commands: ADD, SEARCH, EXIT" << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			phonebook.add();
		if (input == "SEARCH")
			phonebook.search();
		if (input == "EXIT")
			break;
		std::cout << "Plase input one of the following commands: ADD, SEARCH, EXIT" << std::endl;
	}
	return 0;
}
