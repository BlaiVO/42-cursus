#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Constructor called" << std::endl;
	total_contacts = 0;

	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Destructor called" << std::endl;
	return;
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
	std::getline(std::cin, f_name);
	std::cout << "Input your contact's phone number" << std::endl;
	std::getline(std::cin, phone);
	std::cout << "Input your contact's darkest secret >:)" << std::endl;
	std::getline(std::cin, secret);
	Contact new_contact(f_name, l_name, n_name, phone, secret);
	contacts[total_contacts % 8] = new_contact;
}

void	PhoneBook::search(void)
{
	std::cout << "| Name | Last Name | Nickname | Phone Number | Darkest Secret|" << std::endl;
	
}