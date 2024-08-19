#include <iostream>
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name) {
	std::cout << "ScavTrap " << this->name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap " << this->name << " copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &a) {
	std::cout << "ScavTrap " << this->name << " copy assignment operator called" << std::endl;
	ClapTrap::operator=(a);
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target){
	if (this->hit_points <= 0) {
		std::cout << "ScavTrap " << this->name << " is dead and can't attack " << target << std::endl;
		return;
	}
	if (this->energy_points <= 0) {
		std::cout << "ScavTrap " << this->name << " has no energy and can't attack " << target << std::endl;
		return;
	}
	(this->energy_points)--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(){
	if (this->hit_points == 0) {
		std:: cout << this->name << " is dead and cannot guard a gate" << std::endl;
		return;
	}
	std::cout << this->name << " is now in Gate Keeper mode" << std::endl;
}
