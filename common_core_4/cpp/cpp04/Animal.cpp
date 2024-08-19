#include <iostream>
#include "Animal.hpp"


Animal::Animal() {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Animal &Animal::operator= (const Animal &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}
