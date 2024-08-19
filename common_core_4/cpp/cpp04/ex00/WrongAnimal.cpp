#include <iostream>
#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator= (const WrongAnimal &a) {
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const{
	std::cout << this->type << ": *Generic wrong animal sound*" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return this->type;
}
