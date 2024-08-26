#include <iostream>
#include "Dog.hpp"


Dog::Dog() : Animal(){
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(){
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator= (const Dog &a) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
		this->brain = new Brain(*a.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete(this->brain);
}

void	Dog::makeSound() const{
	std::cout << this->type << ": Woof Woof!" << std::endl;
}

void	Dog::setIdea(unsigned int index, std::string idea) {
	this->brain->ideas[index] = idea;
}

void	Dog::printIdeas() const {
	for (int i = 0; i < 100; i++) {
		if (this->brain->ideas[i].length() > 0)
			std::cout << this->brain->ideas[i] << std::endl;
	}
}
