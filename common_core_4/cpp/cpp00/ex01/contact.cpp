#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){
	//std::cout << "contact constructor called" << std::endl;
	f_name = "";
	l_name = "";
	n_name = "";
	phone = "";
	secret = "";
	index = 0;
	return;
}

Contact::~Contact(void){
	//std::cout << "contact destructor called" << std::endl;
	return;
}

void	Contact::set_f_name(std::string new_value) {
	f_name = new_value;
}
void	Contact::set_l_name(std::string new_value) {
	l_name = new_value;
}
void	Contact::set_n_name(std::string new_value) {
	n_name = new_value;
}
void	Contact::set_phone(std::string new_value) {
	phone = new_value;
}
void	Contact::set_secret(std::string new_value) {
	secret = new_value;
}
void	Contact::set_index(int new_value) {
	index = new_value;
}
std::string	Contact::get_f_name(void){
	return (f_name);
} 
std::string	Contact::get_l_name(void){
	return (l_name);
}
std::string	Contact::get_n_name(void){
	return (n_name);
}
std::string	Contact::get_phone(void){
	return (phone);
}
std::string	Contact::get_secret(void){
	return (secret);
}
int	Contact::get_index(void){
	return (index);
}