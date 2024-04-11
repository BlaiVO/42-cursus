#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "contact constructor called" << std::endl;
	f_name = "";
	l_name = "";
	n_name = "";
	phone = "";
	secret = "";
	index = 0;
	return;
}

Contact::~Contact(void){
	std::cout << "contact destructor called" << std::endl;
	return;
}

