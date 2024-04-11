#include <iostream>
#include <string>
#include <stdlib.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "phonebook constructor called" << std::endl;
	total_contacts = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "phonebook destructor called" << std::endl;
	return;
}

void	PhoneBook::printValue(std::string value) {
	std::cout << "|";
	for (size_t i = 0; i < 10; i++) {
		if (i + 1 <=  value.length())
		{
			if (i + 1 == 10 && value.length() > 10)
				putchar('.');
			else
				putchar(value[i]);
		}
		else
			putchar(' ');
	}
}

void	PhoneBook::printContact(Contact *contact)
{
	std::string numbers[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
	printValue(numbers[contact->index - 1]);
	printValue(contact->f_name);
	printValue(contact->l_name);
	printValue(contact->n_name);
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
	contacts[total_contacts % 8].f_name = f_name;
	contacts[total_contacts % 8].l_name = l_name;
	contacts[total_contacts % 8].n_name = n_name;
	contacts[total_contacts % 8].phone = phone;
	contacts[total_contacts % 8].secret = secret;
	contacts[total_contacts % 8].index = (total_contacts % 8) + 1;
	total_contacts++;
	std::cout << "Contact created" << std::endl;
}

void	PhoneBook::search(void)
{
	int	input;
	std::cout << "|Index     |Name      |Last Name |Nickname  |" << std::endl;
	if (contacts[0].index)
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		if (contacts[i].index)
			printContact(&contacts[i]);
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cin >> input;
	if (std::cin.fail() || (input < 1 || input > 8) || !contacts[input].index) {
		std::cout << "Invalid index" << std::endl;
	} else {
		std::cout << "First Name: " << contacts[input - 1].f_name << std::endl;
		std::cout << "Second Name: " << contacts[input - 1].l_name << std::endl;
		std::cout << "Nickname: " << contacts[input - 1].n_name << std::endl;
		std::cout << "Phone Number: " << contacts[input - 1].phone << std::endl;
		std::cout << "Darkest Secret >:): " << contacts[input - 1].f_name << std::endl;
	};
} 