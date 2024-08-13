#include <iostream>
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string new_name) {
	std::cout << "Default constructor called" << std::endl;
	this->name = new_name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->name = a.name;
		this->hit_points = a.hit_points;
		this->energy_points = a.energy_points;
		this->attack_damage = a.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target){
	if (this->hit_points <= 0) {
		std::cout << this->name << " is dead and can't attack " << target << std::endl;
		return;
	}
	if (this->energy_points <= 0) {
		std::cout << this->name << " has no energy and can't attack " << target << std::endl;
		return;
	}
	(this->energy_points)--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int ammount) {
	if (this->hit_points <= 0) {
		std::cout << this->name << " can't take any damage because it's already dead!" << std::endl;
		return;
	}
	if (this->hit_points <= ammount)
		this->hit_points = 0;
	else
		this->hit_points -= ammount;
	std::cout << this->name << " took " << ammount << " points of damage, leaving him at " << this->hit_points << " hp!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int ammount) {
	if (this->hit_points <= 0) {
		std::cout << this->name << " is dead and can't be repaired " << std::endl;
		return;
	}
	if (this->energy_points <= 0){
		std::cout << this->name << "could not be repaired because it has no energy" << std::endl;
		return;
	}
	if (this->energy_points < ammount) {
		std::cout << this->name << " doesn't have enough energy to repair so many points" << std::endl;
		return;
	}
	this->hit_points += ammount;
	this->energy_points -= ammount;
	std::cout << this->name << " was repaired. Now it has " << this->hit_points << " hp" << std::endl;
}
