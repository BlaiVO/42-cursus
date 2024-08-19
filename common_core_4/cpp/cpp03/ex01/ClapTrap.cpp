#include <iostream>
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string new_name) {
	this->name = new_name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ClapTrap " << this->name << " Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	*this = copy;
	std::cout << "ClapTrap " << this->name << " Copy constructor called" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &a) {
	if (this != &a) {
		this->name = a.name;
		this->hit_points = a.hit_points;
		this->energy_points = a.energy_points;
		this->attack_damage = a.attack_damage;
	}
	std::cout << "ClapTrap " << this->name << " Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->name << " Destructor called" << std::endl;
	return;
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
	std::cout << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
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
