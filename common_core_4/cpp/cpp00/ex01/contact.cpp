#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::Contact(std::string new_f_name, std::string new_l_name, std::string new_n_name, std::string new_phone, std::string new_secret) {
	f_name = new_f_name;
	l_name = new_l_name;
	n_name = new_n_name;
	phone = new_phone;
	secret = new_secret;
	return;
}

Contact::~Contact(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

