#include <iostream>
#include "FragTrap.hpp"


FragTrap::FragTrap(std::string new_name) : ClapTrap(new_name) {
	std::cout << "FragTrap " << this->name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap " << this->name << " copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator= (const FragTrap &a) {
	std::cout << "FragTrap " << this->name << " copy assignment operator called" << std::endl;
	ClapTrap::operator=(a);
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(){
	if (this->hit_points == 0) {
		std:: cout << this->name << " is dead and cannot high fives anymore :(" << std::endl;
		return;
	}
	std::cout << this->name << ": High fives guys!! :D" << std::endl;
}
