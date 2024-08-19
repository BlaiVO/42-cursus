#include <iostream>
#include "Cat.hpp"


Cat::Cat() : Animal(){
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(){
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator= (const Cat &a) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	return ;
}

void	Cat::makeSound() const{
	std::cout << this->type << ": Meooow!" << std::endl;
}
