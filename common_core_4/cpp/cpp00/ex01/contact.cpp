#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string phone, std::string secret) {
	_f_name = f_name;
	_l_name = l_name;
	_n_name = n_name;
	_phone = phone;
	_secret = secret;
	return;
}

Contact::~Contact(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

void Contact::set_value(std::string f_name, std::string l_name, std::string n_name, std::string phone, std::string secret){
	_f_name = f_name;
	_l_name = l_name;
	_n_name = n_name;
	_phone = phone;
	_secret = secret;
	return;
}