#include <iostream>
#include "Animal.hpp"


Animal::Animal() {
	std::cout << "Animal Default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &copy){
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator= (const Animal &a) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound() const{
	std::cout << this->type << ": *Generic animal sound*" << std::endl;
}

std::string	Animal::getType() const{
	return this->type;
}
