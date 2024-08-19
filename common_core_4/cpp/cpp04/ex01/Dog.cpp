#include <iostream>
#include "Dog.hpp"


Dog::Dog() : Animal(){
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(){
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator= (const Dog &a) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

void	Dog::makeSound() const{
	std::cout << this->type << ": Woof Woof!" << std::endl;
}
