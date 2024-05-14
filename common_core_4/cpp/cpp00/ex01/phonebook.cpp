#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
	//std::cout << "phonebook constructor called" << std::endl;
	total_contacts = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	//std::cout << "phonebook destructor called" << std::endl;
	return;
}

void	PhoneBook::printValue(std::string value) {
	std::cout << "|";
	if (value.length() > 10) {
		value.resize(9);
		value.append(".");
	}
	std::cout << std::left << std::setw(10) << value;
}

void	PhoneBook::printContact(Contact *contact)
{
	std::string numbers[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
	printValue(numbers[contact->get_index() - 1]);
	printValue(contact->get_f_name());
	printValue(contact->get_l_name());
	printValue(contact->get_n_name());
	std::cout << "|" << std::endl;
}

void	PhoneBook::add(void) {
	std::string	f_name;
	std::string l_name;
	std::string n_name;
	std::string	phone;
	std::string	secret;

	std::cout << "Input your contact's first name" << std::endl;
	std::getline(std::cin, f_name);
	std::cout << "Input your contact's last name" << std::endl;
	std::getline(std::cin, l_name);
	std::cout << "Input your contact's nickname" << std::endl;
	std::getline(std::cin, n_name);
	std::cout << "Input your contact's phone number" << std::endl;
	std::getline(std::cin, phone);
	std::cout << "Input your contact's darkest secret >:)" << std::endl;
	std::getline(std::cin, secret);
	if (f_name == "" || l_name == "" || n_name == "" || phone == "" || secret == "") {
		std::cout << "Empty parameters detected. Contact not created." << std::endl;
		return;
	}
	contacts[total_contacts % 8].set_f_name(f_name);
	contacts[total_contacts % 8].set_l_name(l_name);
	contacts[total_contacts % 8].set_n_name(n_name);
	contacts[total_contacts % 8].set_phone(phone);
	contacts[total_contacts % 8].set_secret(secret);
	contacts[total_contacts % 8].set_index((total_contacts % 8) + 1);
	total_contacts++;
	std::cout << "Contact created" << std::endl;
}

int	PhoneBook::get_int(void)
{
	std::stringstream ss;
	std::string		input;
	int	n;

	ss.clear();
	ss.str("");
	if (!getline(std::cin, input))
		std::exit(1);
	ss.str(input);
	if (ss >> n)
		return (n);
	return (-1);
}

void	PhoneBook::search(void)
{
	int				index;

	std::cout << "|Index     |Name      |Last Name |Nickname  |" << std::endl;
	if (contacts[0].get_index())
		std::cout << "|----------+----------+----------+----------|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		if (contacts[i].get_index())
			printContact(&contacts[i]);
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Please, input an index." << std::endl;
	index = get_int();
	if ((index < 1 || index > 8) || !contacts[index - 1].get_index()) {
		std::cout << "Invalid index" << std::endl;
	} else {
		std::cout << "- First Name: " << contacts[index - 1].get_f_name() << std::endl;
		std::cout << "- Second Name: " << contacts[index - 1].get_l_name() << std::endl;
		std::cout << "- Nickname: " << contacts[index - 1].get_n_name() << std::endl;
		std::cout << "- Phone Number: " << contacts[index - 1].get_phone() << std::endl;
		std::cout << "- Darkest Secret >:): " << contacts[index - 1].get_secret() << std::endl;
	};
	std::cout << std::endl;
} 