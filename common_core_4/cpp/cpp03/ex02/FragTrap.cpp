#include <iostream>
#include "FragTrap.hpp"


FragTrap::FragTrap(std::string new_name) : ClapTrap(new_name) {
	std::cout << "FragTrap " << this->getName() << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap " << this->getName() << " copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator= (const FragTrap &a) {
	std::cout << "FragTrap " << this->getName() << " copy assignment operator called" << std::endl;
	ClapTrap::operator=(a);
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(){
	if (this->getHitPoints() == 0) {
		std:: cout << this->getName() << " is dead and cannot high fives anymore :(" << std::endl;
		return;
	}
	std::cout << this->getName() << ": High fives guys!! :D" << std::endl;
}
