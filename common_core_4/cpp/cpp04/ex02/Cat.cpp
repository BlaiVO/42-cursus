#include <iostream>
#include "Cat.hpp"


Cat::Cat() : Animal(){
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();

}

Cat::Cat(const Cat &copy) : Animal(){
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator= (const Cat &a) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->type = a.type;
		this->brain = new Brain(*a.brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete(this->brain);
}

void	Cat::makeSound() const {
	std::cout << this->type << ": Meooow!" << std::endl;
}

void	Cat::setIdea(unsigned int index, std::string idea) {
	this->brain->ideas[index] = idea;
}

void	Cat::printIdeas() const {
	for (int i = 0; i < 100; i++) {
		if (this->brain->ideas[i].length() > 0)
			std::cout << this->brain->ideas[i] << std::endl;
	}
}
