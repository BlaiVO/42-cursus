#include <iostream>
#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(){
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator= (const WrongCat &a) {
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
	return ;
}

void	WrongCat::makeSound() const{
	std::cout << this->type << ": Meooow!" << std::endl;
}
