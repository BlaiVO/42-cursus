#include <iostream>
#include "Brain.hpp"


Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy){
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator= (const Brain &a) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &a) {
		for (int i = 0; i < 100; i++) {
			if (a.ideas[i].length() > 0) {
				this->ideas[i] = a.ideas[i];
			}
		}
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called" << std::endl;
}
