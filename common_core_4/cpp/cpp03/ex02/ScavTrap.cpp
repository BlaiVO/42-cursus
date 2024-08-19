#include <iostream>
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name) {
	std::cout << "ScavTrap " << this->getName() << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap " << this->getName() << " copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &a) {
	std::cout << "ScavTrap " << this->getName() << " copy assignment operator called" << std::endl;
	ClapTrap::operator=(a);
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target){
	if (this->getHitPoints() <= 0) {
		std::cout << "ScavTrap " << this->getName() << " is dead and can't attack " << target << std::endl;
		return;
	}
	if (this->getEnergyPoints() <= 0) {
		std::cout << "ScavTrap " << this->getName() << " has no energy and can't attack " << target << std::endl;
		return;
	}
	this->setEnergyPoints(this->getEnergyPoints());
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(){
	if (this->getHitPoints() == 0) {
		std:: cout << this->getName() << " is dead and cannot guard a gate" << std::endl;
		return;
	}
	std::cout << this->getName() << " is now in Gate Keeper mode" << std::endl;
}
