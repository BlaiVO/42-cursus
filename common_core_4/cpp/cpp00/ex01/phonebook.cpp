#include <iostream>
#include <string>
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
	for (size_t i = 0; i <10; i++) {
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

void	PhoneBook::printContact(Contact contact)
{
	printValue(contact.f_name);
	printValue(contact.l_name);
	printValue(contact.n_name);
	printValue(contact.phone);
	printValue(contact.secret);
	std::cout << "|" << std::endl;

}

void	PhoneBook::add(void) {
	//TODO Reject empty values
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
	//Contact new_contact();
	contacts[total_contacts % 8].f_name = f_name;
	contacts[total_contacts % 8].l_name = l_name;
	contacts[total_contacts % 8].n_name = n_name;
	contacts[total_contacts % 8].phone = phone;
	contacts[total_contacts % 8].secret = secret;
	contacts[total_contacts % 8].is_set = 1;
	total_contacts++;
}

void	PhoneBook::search(void)
{
	std::cout << "|Name      |Last Name |Nickname  |Phone Nbr |DarkSecret|" << std::endl;
	if (contacts[0].is_set)
		std::cout << "|----------|----------|----------|----------|----------|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		if (contacts[i].is_set)
			printContact(contacts[i]);
	}
	std::cout << "--------------------------------------------------------" << std::endl;
}